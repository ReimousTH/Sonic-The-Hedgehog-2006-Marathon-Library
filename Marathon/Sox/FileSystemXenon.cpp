#include "FileSystemXenon.h"


using namespace Sonicteam::SoX;

FileSystemXenon::FileSystemXenon()
{

}

FileSystemXenon::~FileSystemXenon()
{

}

//later on
std::string Sonicteam::SoX::FileSystemXenon::FSGetPath(std::string InputPath,int folder)
{
	return InputPath +  "\\" + FileSystemFolder[folder] + "\\";
}

unsigned int Sonicteam::SoX::FileSystemXenon::FSDirectoryGetFiles(std::vector<std::string>& out,std::string& InputFolder,std::string& extension)
{
	// Check if directory exists
	DWORD dirAttributes = GetFileAttributesA(InputFolder.c_str());
	if (dirAttributes == -1 || 
		!(dirAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			return 0;  
	}

	std::string searchPath = InputFolder;
	searchPath += '\\';

	//std::string extension = extension;

	searchPath += "*." + extension;

	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findData);

	if (hFind == INVALID_HANDLE_VALUE) {
		return 0;  
	}

	do {
		if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
			!(findData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) {
				(&out)->push_back(findData.cFileName);
		}
	} while (FindNextFileA(hFind, &findData));

	FindClose(hFind);
	return (&out)->empty() ? 0 : 1;  
}

unsigned int Sonicteam::SoX::FileSystemXenon::FSPathExist(std::string& inputpath)
{
	DWORD fileAttributes = GetFileAttributesA((&inputpath)->c_str());
	return (fileAttributes != -1 ) ? 1 : 0;
}



DESTRUCTION_CPP(FileSystemXenon);