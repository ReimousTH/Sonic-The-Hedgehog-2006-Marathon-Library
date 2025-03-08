#ifndef CHAO__CSD__CPROJECT
#define CHAO__CSD__CPROJECT

#include <xtl.h>

#include <Sox/Misc/MapExtension.h>
#include <string>
#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CScene.h>
#include <Chao/CSD/RCObject.h>
#include <Chao/CSD/CTexList.h>
#include <Chao/CSD/Project.h>
#include <Chao/CSD/CResourceBase.h>



#include <map>


namespace Chao{
	namespace CSD{



		class CProject:Chao::CSD::CResourceBase<Chao::CSD::Project>
		{
		public:
			CProject(void);
			~CProject(void);

			virtual void CResourceBase0x4(void*);

			unsigned int FCProject0xC;
			std::map<const char*,Chao::CSD::RCObject<Chao::CSD::CScene>*,STD_MAP_CONST_CHAR_PTR_COMPARATOR> CProjectScene; //later 0x10
			std::map<float,Chao::CSD::RCObject<Chao::CSD::CScene>*> CProjectSceneFloat; //later //0x1C

			Chao::CSD::RCObject<Chao::CSD::CTexList> CTexList; //0x28
			void* unk0x2C; //0x2C
			//
			unsigned int unk0x30; //lost-name class later
			unsigned int FCProject0x34;// ?
			unsigned int FCProject0x38;
			unsigned int FCProject0x3C;
			unsigned int FCProject0x40; // ?
			unsigned int FCProject0x44; 
		

	};
};
};
#endif
