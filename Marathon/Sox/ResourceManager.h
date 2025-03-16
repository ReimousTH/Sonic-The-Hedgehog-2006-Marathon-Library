#ifndef SONICTEAM__SOX__RESOURCEMANAGER
#define SONICTEAM__SOX__RESOURCEMANAGER

#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>

#include <Sox/IResource.h>
#include <Sox/IResourceMgr.h>

#include <map>
#include <Sox/Misc/MapExtension.h>

#include <list>



namespace Sonicteam{
	namespace SoX{

	   
		struct HoldMGR{
			unsigned int Unk0;  //no idea 82 59 58 18
			unsigned int Unk4; //no idea 82 63 15 00
			Sonicteam::SoX::IResourceMgr* Mgr;
			unsigned short Flag01; //01  (enabled??)
			unsigned short Flag02; //index?
		};
	
		
		class ResourceManager{
        public:




        public:
			ResourceManager();
            ~ResourceManager();


			//ResourceMap1[ManagerRegistryIndex][STD::STRING FileName] = IResource(ResouceHandle)
			std::map<int,std::map<std::string, REF_TYPE(Sonicteam::SoX::IResource)>> ResourceRegistryHandle; 
			unsigned int unk0x10;
			std::list<REF_TYPE(Sonicteam::SoX::RefCountObject)> ResourceList; // Empty always?  0x14 i think it list :
			std::map<int,HoldMGR> ManagerResouceMgr; //0x20
			unsigned int unk0x2C;
			std::map<const char*,int,STD_MAP_CONST_CHAR_PTR_COMPARATOR> ManagerRegistryIndex; //0x30 (ClassName, Index)


			DESTRUCTION_H;



		
		
		};



	};
};

#endif