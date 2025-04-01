#include "FileHandleARC.h"


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



bool FileHandleARC::LoadHandle()
{
	if (!IsLoaded){
		Sonicteam::SoX::ArcHandleMgr* mgr =  &Sonicteam::SoX::ArcHandleMgr::getInstance();
		/*
		for (LinkSoxNode<Sonicteam::SoX::ArcHandle>::iterator* it = mgr->LinkArcHandle.Next;it != &mgr->LinkArcHandle;it++){
			Sonicteam::SoX::ArcHandle* ahandle =  it->_this;
		}
		*/

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