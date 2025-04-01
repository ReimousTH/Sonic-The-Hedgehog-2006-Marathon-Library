#ifndef SONICTEAM__SOX__FILELOADERARC
#define SONICTEAM__SOX__FILELOADERARC

#include <Sox/Defs.h>
#include <Sox/IFileLoader.h>

namespace Sonicteam{
	namespace SoX{
		

		
		//this is the best that i can think
		class FileLoaderARC:Sonicteam::SoX::IFileLoader
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