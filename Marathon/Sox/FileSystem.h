#ifndef SONICTEAM__SOX__FILESYSTEM
#define SONICTEAM__SOX__FILESYSTEM



#include <string>
#include <list>
#include <deque>
#include <vector>
#include <fstream>

#define XenonFolder 0
#define Win32Folder 1
#define CommonFolder 1




//STATIC CLASS

namespace Sonicteam{
	namespace SoX{
		

		
		//this is the best that i can think
		class FileSystem
		{

		public:	
			FileSystem();
			~FileSystem();


			virtual std::string FileSystemGetFullPath(std::string& InputPath,int folder) = 0;
			//For Example (game:/win32/scripts/ -  lub) 
			virtual unsigned int FileSystemIsExistsSpecificFiles(unsigned int unkptr,std::string& InputFolder,std::string& extension) = 0;
			virtual unsigned int FileSystemIsFileExist(std::string& InputFile) = 0;
			DESTRUCTION_H;

			std::vector<std::string> FileSystemFolder; // game:\xenon\ ...

			//fields


	
		};


		//static FileSystem &06FileSystem = *(FileSystem *)0x82D35EAC;



	
	}
}
#endif