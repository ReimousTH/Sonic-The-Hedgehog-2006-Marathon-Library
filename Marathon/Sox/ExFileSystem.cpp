#include "ExFileSystem.h"


using namespace Sonicteam::SoX;

//later on
std::string Sonicteam::SoX::ExFileSystem::FSGetPath(std::string InputPath,int folder)
{
	return InputPath +  "\\" + FileSystemFolder[folder] + "\\";
}

unsigned int Sonicteam::SoX::ExFileSystem::FSDirectoryGetFiles(std::vector<std::string>& out,std::string& InputFolder,std::string& extension)
{
	return false; //for now
}

unsigned int Sonicteam::SoX::ExFileSystem::FSPathExist(std::string& inputpath)
{
	return false; //for now
}

Sonicteam::SoX::ExFileSystem::ExFileSystem()
{

}

Sonicteam::SoX::ExFileSystem::~ExFileSystem()
{

}

DESTRUCTION_CPP(ExFileSystem);