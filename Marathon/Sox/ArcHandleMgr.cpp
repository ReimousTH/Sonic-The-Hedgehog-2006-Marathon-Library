#include "ArcHandleMgr.h"
using namespace Sonicteam::SoX;


DESTRUCTION_CPP(ArcHandleMgr);

ArcHandleMgr::ArcHandleMgr()
{

}

ArcHandleMgr::~ArcHandleMgr()
{

}

Sonicteam::SoX::IResource* ArcHandleMgr::GetMgrResource(Sonicteam::SoX::IResourceMgrParam* param)
{
	return 0;
}

std::string ArcHandleMgr::GetMgrResourceName(std::string resouce)
{
	return 0;
}

void ArcHandleMgr::IResourceMgr03impl()
{
	
}

void ArcHandleMgr::IResourceMgr04impl()
{
	
}

void ArcHandleSearchResource::GetFromChunkFHandle(Sonicteam::SoX::ArcFileChunkF& chunkf,Sonicteam::SoX::ArcHandle* ahandle)
{
	//PushXenonMessage(L"MSG",search_path.c_str());
	if (ahandle->HandleBuffer){
		this->arc_path = "";
		this->arc_buffer = ahandle->HandleBuffer;

	}
	else{
		this->arc_path = ahandle->ArcFilePath.c_str();
		this->arc_buffer = 0;
	}
	this->ResourceOffset = chunkf.Offset;
	this->ResourceCompressedSize = chunkf.CompressedSize;

	if (chunkf.IsCompressed){
		this->ResourceDecompressedSize = chunkf.DecompressedSize;
	}
	else{
		this->ResourceDecompressedSize = chunkf.CompressedSize;
	}

	this->IsCompressed = chunkf.IsCompressed;
	this->Handle = ahandle;
	this->IsDownloadContent = ahandle->IsDownloadContent;

}
