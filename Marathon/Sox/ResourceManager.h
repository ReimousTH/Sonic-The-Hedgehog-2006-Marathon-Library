#ifndef SONICTEAM__SOX__RESOURCEMANAGER
#define SONICTEAM__SOX__RESOURCEMANAGER

#include <map>
#include <list>

#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>

#include <Sox/IResource.h>
#include <Sox/IResourceMgr.h>


#include <Sox/Misc/MapExtension.h>


#include <System/CreateStatic.h>
#include <System/Singleton.h>

#include <Sox/IResourceMgr.h>

#include <functional>



namespace Sonicteam{
	namespace SoX{

	   
		struct HoldMGR{
		

			void ( *Unk0)(Sonicteam::SoX::IResourceMgr*);
			void ( *Unk4)(Sonicteam::SoX::IResourceMgr*);
			Sonicteam::SoX::IResourceMgr* Mgr;
			unsigned short Flag01; //01  (enabled??)
			unsigned short Flag02; //index?
		};
	
		
		class ResourceManager:public SSINGLETON(ResourceManager){
        public:



        public:
			ResourceManager();
            ~ResourceManager();


			//ResourceMap1[ManagerRegistryIndex][STD::STRING FileName] = IResource(ResouceHandle)
			std::map<int,std::map<std::string, Sonicteam::SoX::IResource*>> ResourceRegistryHandle; 
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