#include "FileHandleARC.h"
#include <zlib.h>
#include <cstring>

#include <../2006DLL_REWORK/Core/Debug.h>
#include <../2006DLL_REWORK/Hook/HookBase.h>

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

//path1 =
int ComparePathComponents(const char* str1, const char* str2) {
	
	while (*str2 != '\0') {
		char c1 = tolower(*str1);
		char c2 = tolower(*str2);

		if (c1 != c2) {
			return 0; 
		}

		str1++;
		str2++;
	}

	char last_char = (*str1);
	if (last_char == '/' || last_char == '\0') {
		return 1;  
	}

	return 0;  
}




size_t FileHandleARC::SearchChunkEntryE1(Sonicteam::SoX::ArcFile* arcFile, const char* path) {

	


	std::string test = path;




	
	if (!arcFile || !path || !arcFile->ChunkArray || !arcFile->ChunkStringOffset) 
		return -1;

	const char* current = path;
	size_t current_index = arcFile->RootIndex;

	// Skip leading slashes
	while (*current == '/') current++;
	if (*current == '\0') return current_index;


	bool enable_compare = true;
	// win32/stage/wvo/sonic/ssh_envmap
	if (test.find("ssh_envmap") != std::string::npos){


	//	enable_compare = true;
	//	PushXenonMessage(L"MSG",path);
	//	Sleep(2000);

	}


	while (true) 
	{
		// Get current directory bounds
		size_t start_index = current_index + 1;
		size_t end_index = arcFile->ChunkArray[current_index].CompressedSize;
		bool found = false;

		// Search through current directory entries
		for (size_t i = start_index; i < end_index; ) 
		{

			Sonicteam::SoX::ArcFileChunk* chunk_i =  &arcFile->ChunkArray[i];

			const char* name =  (const char*)((size_t)arcFile->ChunkStringOffset+ (size_t)chunk_i->Info.NameOffset);
			bool is_dir = arcFile->ChunkArray[i].Info.Type == Sonicteam::SoX::_ChunkInfo::Directory;

			// Debug output
			if (enable_compare){

			//	std::stringstream ss; ss << name << std::hex << " - " <<  (void*)name << " - " << (void*)chunk_i << " - " << " - " << arcFile->ChunkStringOffset << " - "<<    arcFile->ChunkArray[i].Info.NameOffset;
			//	PushXenonMessage(L"MSG", ss.str().c_str());
			}
		

			if (ComparePathComponents(current, name)) 
			{
				// Move past the matched component
				current += strlen(name);

				// Skip any slashes after component
				while (*current == '/') current++;

				if (*current == '\0') 
				{
					// Found our final target
					return i;
				}

				if (!is_dir) 
				{
					// Path continues but entry isn't a directory
					return -1;
				}

				// Descend into subdirectory
				current_index = i;
				found = true;
				break;
			}

			// Move to next entry (skip directory contents if this is a directory)
			i = is_dir ? arcFile->ChunkArray[i].CompressedSize : i + 1;
		}

		if (!found) return -1;
	}
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



