#include "FileSystemArc.h"


using namespace Sonicteam::SoX;


DESTRUCTION_CPP(FileSystemArc);

FileSystemArc::FileSystemArc()
{

}

FileSystemArc::~FileSystemArc()
{

}

std::string FileSystemArc::FSGetPath(std::string InputPath,int folder)
{
	return Sonicteam::SoX::FileSystemXenon::getInstance().FSGetPath(InputPath,folder);
}

unsigned int FileSystemArc::FSDirectoryGetFiles(std::vector<std::string>& out,std::string& InputFolder,std::string& extension)
{
	return false;
}

unsigned int FileSystemArc::FSPathExist(std::string& inputpath)
{
	Sonicteam::SoX::ArcHandleMgr* mgr =  SSINGLETON_INSTANCE(Sonicteam::SoX::ArcHandleMgr);
	std::string fpath = inputpath.erase(inputpath.find(mgr->RootPath)); // game\\ (remove)

	/*

	for (LinkSoxNode<Sonicteam::SoX::ArcHandle>::iterator* it = mgr->LinkArcHandle.Next;it != &mgr->LinkArcHandle;it++){
		Sonicteam::SoX::ArcHandle* ahandle =  it->_this;
		ahandle->_ArcFile.ArcHeaderData1

	}

	*/
	return false;
}

