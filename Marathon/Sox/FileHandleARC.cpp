#include "FileHandleARC.h"
#include <zlib.h>
#include <cstring>

#include <../2006DLL_REWORK/Core/Debug.h>

using namespace Sonicteam::SoX;



FileHandleARC::FileHandleARC()
{

}

FileHandleARC::FileHandleARC(std::string& filepath,IFileHandle_BFUNCTION_TYPE func)
{
	this->filepath = filepath;
	this->IsLoaded = 0;
	this->IsProcess = 0;
	this->size = 0;
	this->HBuffer = 0;
	this->func0x34 = func;

}

FileHandleARC::~FileHandleARC()
{
	delete HBuffer;
}








///CHUNKS[END]

void FileHandleARC::LoadFileFromArc(Sonicteam::SoX::ArcHandleSearchResource& res)
{

	this->size = res.ResourceDecompressedSize;

	delete[] this->HBuffer; 
	this->HBuffer = new char[res.ResourceDecompressedSize];

	size_t decompressedSize = res.ResourceDecompressedSize;
	size_t compressedSize = res.ResourceCompressedSize;

	void* chunkBufferCompressed = res.IsCompressed ? new char[compressedSize] : NULL;
	void* chunkBuffer = res.IsCompressed ? chunkBufferCompressed : this->HBuffer;


	if (res.arc_buffer) {
		memcpy(chunkBufferCompressed, (void*)((size_t)res.arc_buffer + (size_t)res.ResourceOffset), compressedSize);
		if (res.IsCompressed) {
			DecompressZChunk(this->HBuffer,this->size,chunkBufferCompressed,compressedSize);
		}
	} else {
		HANDLE fileHandle = CreateFile(res.IsDownloadContent ? "download:\\download.arc" : res.arc_path,
			GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (fileHandle == INVALID_HANDLE_VALUE) {
			//ProcessError(res.IsDownloadContent);
			return;
		}
		SetFilePointer(fileHandle,(LONG)res.ResourceOffset,0,0);
		DWORD bytesRead = 0;
		if (res.IsCompressed) {
			ReadFile(fileHandle, chunkBufferCompressed, compressedSize, &bytesRead, NULL);
			DecompressZChunk(this->HBuffer,this->size,chunkBufferCompressed,compressedSize);
		} else {
			ReadFile(fileHandle, this->HBuffer, decompressedSize, &bytesRead, NULL);
		}
		CloseHandle(fileHandle);
		if (bytesRead != (res.IsCompressed ? compressedSize : decompressedSize)) {
			//ProcessError(res.IsDownloadContent);
			return;
		}
	}

	delete[] chunkBufferCompressed; // Clean up compressed buffer if used
}








bool FileHandleARC::LoadHandle()
{

	if (!IsLoaded){
		Sonicteam::SoX::ArcHandleMgr* mgr =  &Sonicteam::SoX::ArcHandleMgr::getInstance();
		Sonicteam::SoX::ArcHandleSearchResource chunkf;
		if (SearchChunk(mgr,this->filepath,chunkf)){
			LoadFileFromArc(chunkf);

		}
		else{
			//Load-External
		}
	}

	return IsProcess;
}

unsigned __int64 FileHandleARC::GetHandleSize()
{
	return size;
}

void* FileHandleARC::GetHandleBuffer()
{
	return HBuffer;
}

DESTRUCTION_CPP(FileHandleARC);





std::string FileHandleARC::GetARCChunkPath(ArcHandleMgr* mgr,std::string& path)
{
	std::string fpath = path;
	std::string root_path  = mgr->RootPath;
	fpath.erase(fpath.find(root_path),root_path.length());
	std::replace(fpath.begin(), fpath.end(), '\\', '/');
	return fpath;
}



size_t FileHandleARC::SearchChunkEntryE1(Sonicteam::SoX::ArcFile* ArcFile, const char* path) {

	const char* current = path;
	unsigned int currentIndex = ArcFile->RootIndex; // Previously unk0x14

	while (*current) 
	{
		// Skip path separators
		if (*current == '/') {
			current++;
			continue;
		}

		// Handle . and .. navigation
		if (*current == '.') {
			if (current[1] == '.' && (current[2] == '/' || current[2] == '\0')) {
				// Parent directory (..)
				currentIndex = static_cast<unsigned int>(reinterpret_cast<uintptr_t>(
					ArcFile->ChunkArray[currentIndex].Offset));
				current += 2;
				if (*current == '/') current++;
				continue;
			}
			else if (current[1] == '/' || current[1] == '\0') {
				// Current directory (.)
				current += 1;
				if (*current == '/') current++;
				continue;
			}
		}

		// Extract path component
		const char* componentStart = current;

		while (true) {
			char c = *current;
			if (c == '/' || c == '\0') break;
			current++;
		}

		size_t componentLength = current - componentStart;


		// Search current directory
		bool found = false;
		unsigned int childIndex = currentIndex + 1;
		unsigned int nextSibling = ArcFile->ChunkArray[currentIndex].CompressedSize;

		while (childIndex < nextSibling) 
		{
			Sonicteam::SoX::ArcFileChunk entry = ArcFile->ChunkArray[childIndex];
			bool isDirectory = (entry.Info.Type == Sonicteam::SoX::_ChunkInfo::Directory);

			// Compare names
			const char* entryName = (const char*)((size_t)ArcFile->ChunkStringOffset + entry.Info.NameOffset);



			if (strncmp(componentStart, entryName, componentLength) == 0 && 
				entryName[componentLength] == '\0') 
			{
				currentIndex = childIndex;
				found = true;



				// If directory and more path remains, continue searching
				if (isDirectory && *current == '/') {
					current++;
					break;
				}

				// If final component, return result
				if (!*current) {
					//PushXenonMessage(L"MSG",entryName);
					return currentIndex;
				}
			}

			// Move to next entry
			childIndex = isDirectory ? entry.CompressedSize : childIndex + 1;
		}

		if (!found) return 0xFFFFFFFF;
	}

	return currentIndex;
}


bool FileHandleARC::SearchChunk(Sonicteam::SoX::ArcHandleMgr* mgr,std::string& search_path,Sonicteam::SoX::ArcHandleSearchResource& search_chunk){

	for (LinkSoxNode<Sonicteam::SoX::ArcHandle>::iterator* it = mgr->LinkArcHandle.Next; it != &mgr->LinkArcHandle;it=it->Next ) {

		size_t find_index = -1;
		Sonicteam::SoX::ArcHandle* ahandle =  it->_this;
		std::string chunk_path  = mgr->RootPath;
		std::string fpath = Sonicteam::SoX::FileHandleARC::GetARCChunkPath(mgr,search_path);	
		find_index = Sonicteam::SoX::FileHandleARC::SearchChunkEntryE1(&ahandle->_ArcFile,fpath.c_str());


		if (find_index != -1){
			Sonicteam::SoX::ArcFileChunkF chunkf = ahandle->_ArcFile.ChunkArray[find_index];
			search_chunk.GetFromChunkFHandle(chunkf,ahandle);
			return true;
		}	
	}
	//PushXenonMessage(L"MSG","++");
	return false;	
}

void FileHandleARC::DecompressZChunk(void* out_buffer,size_t out_size,void* c_buffer,size_t c_size){

	// Initialize the zlib stream structure
	z_stream zs;
	memset(&zs, 0, sizeof(zs));

	// Set input and output buffers for zlib
	zs.next_in = static_cast<Bytef*>(c_buffer); // Compressed data
	zs.avail_in = static_cast<uInt>(c_size);   // Size of compressed data

	zs.next_out = static_cast<Bytef*>(out_buffer); // Output buffer
	zs.avail_out = static_cast<uInt>(out_size);    // Size of output buffer

	// Initialize the decompression process
	if (inflateInit(&zs) != Z_OK) {
		throw std::runtime_error("inflateInit failed while decompressing.");
	}

	// Perform the decompression
	int ret = inflate(&zs, Z_FINISH);
	if (ret != Z_STREAM_END) {
		inflateEnd(&zs); // Clean up zlib resources
		throw std::runtime_error("inflate failed while decompressing.");
	}

	// Clean up zlib resources after successful decompression
	inflateEnd(&zs);

	std::cout << "Decompression successful. Decompressed size: " << zs.total_out << " bytes.\n";

}



