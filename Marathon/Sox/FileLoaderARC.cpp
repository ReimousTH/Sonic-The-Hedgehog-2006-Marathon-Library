#include "FileLoaderARC.h"


using namespace Sonicteam::SoX;



REF_TYPE(Sonicteam::SoX::IFileHandle) FileLoaderARC::LoadFile(std::string& filepath,IFileLoader_BFUNCTION_TYPE& function)
{
	return new FileHandleARC(filepath,function);
}



FileLoaderARC::FileLoaderARC()
{

}

FileLoaderARC::~FileLoaderARC()
{

}

DESTRUCTION_CPP(FileLoaderARC);