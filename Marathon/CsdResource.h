#ifndef SONICTEAM__CSDRESOURCE
#define SONICTEAM__CSDRESOURCE

#include "Defs.h"
#include <Sox/Memory/IDestructible.h>
#include <Sox/IResource2.h>
#include <CsdManager.h>

struct CSDFile{};


namespace Sonicteam{



	//Or SonicTeamSoxComponent
	class CsdResource:public IResource2HR(Sonicteam::CsdResource,Sonicteam::CsdManager)
		{
		public:
			CsdResource(void);
			~CsdResource(void);

			CSDFile* _CSDFile; // :) 0x64   v13 = operator new[](a3 + 0x20); *(_DWORD *)(a1 + 0x64) = v13;
			size_t _CSDSize; //0x68



	
			DESTRUCTION_H; //0x0 + 0x10




			virtual bool ResourceLoad(void* File,size_t size);
			virtual std::string GetResourceName(std::string file_name);

	};

};

#endif