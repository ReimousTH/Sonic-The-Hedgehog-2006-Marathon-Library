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



			virtual std::string FSGetPath(std::string InputPath,int folder);

			virtual unsigned int FSDirectoryGetFiles(std::vector<std::string>& out,std::string& InputFolder,std::string& extension);

			virtual unsigned int FSPathExist(std::string& inputpath);

			DESTRUCTION_H;

		};






	
	}
}
#endif