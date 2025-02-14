#include "ExFileSystem.h"


using namespace Sonicteam::SoX;

std::string Sonicteam::SoX::ExFileSystem::FileSystemGetFullPath(std::string& InputPath,int folder)
{
	return InputPath + FileSystemFolder[folder];
}

unsigned int Sonicteam::SoX::ExFileSystem::FileSystemIsExistsSpecificFiles(unsigned int unkptr,std::string& InputFolder,std::string& extension)
{
	return false; //for now
}

unsigned int Sonicteam::SoX::ExFileSystem::FileSystemIsFileExist(std::string& InputFile)
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