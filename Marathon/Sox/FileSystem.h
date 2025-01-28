#pragma once

#include <string>
#include <list>


#include <deque>
#include <vector>

#define XenonFolder 0
#define Win32Folder 1
#define CommonFolder 1

//STATIC CLASS

namespace Sonicteam{
	namespace SoX{
		

		
		//this is the best that i can think
		class FileSystem
		{

		private:
			FileSystem(void);
			// Prevent copying of the Singleton instance
			//FileSystem(const FileSystem&) = delete;
//			FileSystem& operator=(const FileSystem&) = delete;

		public:	
			virtual std::string FileSystemGetFullPath(std::string& InputPath,int folder);
			//For Example (game:/win32/scripts/ -  lub) 
			virtual unsigned int FileSystemIsExistsSpecificFiles(unsigned int unkptr,std::string& InputFolder,std::string& extension);
			virtual unsigned int FileSystemIsFileExist(std::string& InputFile);
	

			static FileSystem& getInstance() {
				// Create the instance if it doesn't exist yet
				// This ensures only one instance is ever created
				static FileSystem instance;
				return instance;
			}	
			unsigned int FSuint0x4;
			std::vector<std::string*> _FSVector;
			//fields


	
		};
		//static FileSystem &06FileSystem = *(FileSystem *)0x82D35EAC;



	
	}
}
