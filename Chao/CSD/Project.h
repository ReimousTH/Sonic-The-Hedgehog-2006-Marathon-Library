	#ifndef CHAO__CSD__PROJECT
#define CHAO__CSD__PROJECT


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/RCObject.h>
#include <Chao/CSD/CMemoryAlloc.h>
#include <Chao/CSD/Scene.h>
#include <Chao/Misc/utill.hpp>



namespace Chao{
	namespace CSD{



		//Before .DXL - 0x10


		struct Directory{
			Chao::CDictionary86<Chao::CSD::Scene*> _Scene; //0x0-0x4-0x8-0xC-0x10-0x14
			Chao::CDictionary86<Chao::CSD::Directory> _Directory; //0x18-0x1C-0x20-0x24-0x28-0x2C
		};


		struct Project
		{
			Project();
			~Project();

			Chao::C64BIT<Directory*> _RootDir; //0-4
			Chao::C64BIT<const char*> _RootDirName;

			//
		};
	};
};

#endif
