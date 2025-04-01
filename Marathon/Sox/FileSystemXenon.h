#ifndef SONICTEAM__SOX__EXFILESYSTEM
#define SONICTEAM__SOX__EXFILESYSTEM

#include "FileSystem.h"

#include <xtl.h>
#include <System/Singleton.h>
#include <System/CreateStatic.h>


namespace Sonicteam{
	namespace SoX{
		

		

		class FileSystemXenon:Sonicteam::SoX::FileSystem,public SSINGLETON(FileSystemXenon)
		{
		public:
			FileSystemXenon();
			~FileSystemXenon();



			virtual std::string FSGetPath(std::string InputPath,int folder);

			virtual unsigned int FSDirectoryGetFiles(std::vector<std::string>& out,std::string& InputFolder,std::string& extension);

			virtual unsigned int FSPathExist(std::string& inputpath);

			DESTRUCTION_H;

		};






	
	}
}
#endif