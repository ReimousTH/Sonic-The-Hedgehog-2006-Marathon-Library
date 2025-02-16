#ifndef SONICTEAM__SOX__EXFILESYSTEM
#define SONICTEAM__SOX__EXFILESYSTEM

#include "FileSystem.h"



namespace Sonicteam{
	namespace SoX{
		

		

		class ExFileSystem:Sonicteam::SoX::FileSystem
		{
		public:
			ExFileSystem();
			~ExFileSystem();



			virtual std::string FileSystemGetFullPath(std::string InputPath,int folder);

			virtual unsigned int FileSystemIsExistsSpecificFiles(unsigned int unkptr,std::string InputFolder,std::string& extension);

			virtual unsigned int FileSystemIsFileExist(std::string InputFile);

			DESTRUCTION_H;

		};






	
	}
}
#endif