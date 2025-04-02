#ifndef SONICTEAM__SOX__FILELOADERARC
#define SONICTEAM__SOX__FILELOADERARC

#include <Sox/Defs.h>
#include <Sox/IFileLoader.h>
#include <Sox/FileHandleARC.h>
#include <System/Singleton.h>
#include <System/CreateStatic.h>

namespace Sonicteam{
	namespace SoX{
		

		
		//this is the best that i can think
		class FileLoaderARC:Sonicteam::SoX::IFileLoader,public SSINGLETON(FileLoaderARC)
		{

		public:	
			FileLoaderARC();
			~FileLoaderARC();
			DESTRUCTION_H;
			virtual REF_TYPE(Sonicteam::SoX::IFileHandle) LoadFile(std::string& filepath,IFileLoader_BFUNCTION_TYPE& function);
			

		};

	};
};
#endif