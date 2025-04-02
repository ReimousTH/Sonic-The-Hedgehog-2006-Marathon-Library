#include "FileHandleARC.h"
#include <zlib.h>

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


std::string combinePaths(const std::string& path1, const std::string& path2) {
	if (path1.empty()) return path2;
	if (path2.empty()) return path1;

	char separator = '\\'; // Windows directory separator

	// Check if path1 ends with a separator
	bool endsWithSeparator = !path1.empty() && (path1[path1.size() - 1] == separator);

	// Combine paths
	if (endsWithSeparator) {
		return path1 + path2; // No extra separator needed
	} else {
		return path1 + separator + path2; // Add separator between paths
	}
}


size_t FileHandleARC::SearchChunkEntry(Sonicteam::SoX::ArcHandle* handle, Sonicteam::SoX::ArcFileChunk* Chunk, size_t ChunkCount, size_t index, std::string& search_path, std::string current_path, size_t& find_index) {
	Sonicteam::SoX::ArcFileChunk* entry = &Chunk[index];
	const char* chunk_name = (const char*)((size_t)handle->_ArcFile.ChunkStringOffset + entry->Info.NameOffset);
	std::string local_current_path = combinePaths(current_path, chunk_name);

	//std::stringstream compare;
	//compare << handle->ArcFilePath << " --- " <<  local_current_path << " ---- " << search_path;

	if (search_path == local_current_path){
		find_index = index;
	}
	bool it = search_path.find(local_current_path) == std::string::npos; //accelerate little more


	switch (entry->Info.Type) {
		case Sonicteam::SoX::_ChunkInfo::Directory: {

			if (it) return entry->CompressedSize;

			size_t u8ChildIndex = ++index;
			while (u8ChildIndex < entry->CompressedSize && find_index == -1) {
				u8ChildIndex = SearchChunkEntry(handle, Chunk, ChunkCount, u8ChildIndex, search_path, local_current_path, find_index);
			}
			return entry->CompressedSize; // Return the end of the directory
													}
		case Sonicteam::SoX::_ChunkInfo::File: {

			return ++index; // Move to the next entry
											   }
	}

}

bool FileHandleARC::SearchChunk(Sonicteam::SoX::ArcHandleMgr* mgr,std::string& search_path,Sonicteam::SoX::ArcHandleSearchResource& search_chunk){


	
	for (LinkSoxNode<Sonicteam::SoX::ArcHandle>::iterator* it = mgr->LinkArcHandle.Next; it != &mgr->LinkArcHandle;it=it->Next ) {


		Sonicteam::SoX::ArcHandle* ahandle =  it->_this;
		std::string chunk_path  = mgr->RootPath;
		size_t find_index = -1;

		SearchChunkEntry(ahandle,ahandle->_ArcFile.ChunkArray,ahandle->_ArcFile.ChunkArraySize /0x10,0,search_path,chunk_path,find_index);
		if (find_index != -1){
			Sonicteam::SoX::ArcFileChunkF chunkf = ahandle->_ArcFile.ChunkArray[find_index];

			//PushXenonMessage(L"MSG",search_path.c_str());
			if (ahandle->HandleBuffer){
				search_chunk.arc_path = "";
				search_chunk.arc_buffer = ahandle->HandleBuffer;

			}
			else{
				search_chunk.arc_path = ahandle->ArcFilePath.c_str();
				search_chunk.arc_buffer = 0;
			}
			search_chunk.ResourceOffset = chunkf.Offset;
			search_chunk.ResourceCompressedSize = chunkf.CompressedSize;

			if (chunkf.IsCompressed){
				search_chunk.ResourceDecompressedSize = chunkf.DecompressedSize;
			}
			else{
				search_chunk.ResourceDecompressedSize = chunkf.CompressedSize;
			}
			
			search_chunk.IsCompressed = chunkf.IsCompressed;
			search_chunk.Handle = ahandle;
			search_chunk.IsDownloadContent = ahandle->IsDownloadContent;
	


			return true;
		}	
	}
	//PushXenonMessage(L"MSG","++");
	return false;	
}








void DecompressZChunk(void* out_buffer,size_t out_size,void* c_buffer,size_t c_size){

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


void FileHandleARC::LoadFileFromArc(Sonicteam::SoX::ArcHandleSearchResource& res)
{

	this->size = res.ResourceDecompressedSize;

	delete[] this->HBuffer; // Ensure array deletion
	this->HBuffer = new char[res.ResourceDecompressedSize]; // Allocate decompressed buffer

	size_t decompressedSize = res.ResourceDecompressedSize;
	size_t compressedSize = res.ResourceCompressedSize;

	void* chunkBufferCompressed = res.IsCompressed ? new char[compressedSize] : NULL;
	void* chunkBuffer = res.IsCompressed ? chunkBufferCompressed : this->HBuffer;

	// Handle file or directory
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