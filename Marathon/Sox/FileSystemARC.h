#ifndef SONICTEAM__SOX__FILESYSTEMARC
#define SONICTEAM__SOX__FILESYSTEMARC

#include <Sox/Defs.h>
#include <Sox/FileSystem.h>
#include <Sox/FileSystemXenon.h>
#include <System/Singleton.h>
#include <System/CreateStatic.h>
#include <Sox/ArcHandleMgr.h>


namespace Sonicteam{
	namespace SoX{
		

		

		class FileSystemArc:Sonicteam::SoX::FileSystem,public SSINGLETON(FileSystemArc)
		{
		public:
			FileSystemArc();
			~FileSystemArc();



			virtual std::string FSGetPath(std::string InputPath,int folder);

			virtual unsigned int FSDirectoryGetFiles(std::vector<std::string>& out,std::string& InputFolder,std::string& extension);

			virtual unsigned int FSPathExist(std::string& inputpath);

			DESTRUCTION_H;

		};






	
	}
}
#endif