#ifndef CHAO__CSD__CPROJECT
#define CHAO__CSD__CPROJECT


#include <string>
#include <map>
#include <Chao/Misc/API_DEFS.h>
#include <Chao/Misc/MapExtension.hpp>
#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CScene.h>
#include <Chao/CSD/RCObject.h>
#include <Chao/CSD/CTexList.h>
#include <Chao/CSD/Project.h>
#include <Chao/CSD/CResourceBase.h>
#include <Chao/CSD/CBase.h>

#include <Chao/CSD/Manager/csdmProject.h>


namespace Chao{
	namespace CSD{



		class CProject:Chao::CSD::CResourceBase<Chao::CSD::Project>,Chao::CSD::CBase // (0xD Position )
		{
		public:
			CProject(void);
			~CProject(void);

			virtual void CResourceBase0x4(void*);

			unsigned int FCProject0xC;
			std::map<const char*,Chao::CSD::RCObject<Chao::CSD::CScene>*,STD_MAP_CONST_CHAR_PTR_COMPARATOR> CProjectScene; //later 0x10
			std::map<float,Chao::CSD::RCObject<Chao::CSD::CScene>*> CProjectSceneFloat; //later //0x1C

			RCOBJREF(Chao::CSD::CTexList) CTexList; //0x28
			Chao::CSD::Manager::csdmProject* CMProject; //0x2C



			std::list<RCOBJREF(unsigned char)> unk0x30; //0x30-0x34-0x38
			std::list<size_t> unk0x3C; //0x3C-0x40-0x44



		};
	};
};
#endif
