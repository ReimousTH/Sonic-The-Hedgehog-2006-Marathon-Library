#ifndef SONICTEAM__SOX__IRESOURCE
#define SONICTEAM__SOX__IRESOURCE

#include <string>
#include <Sox/Defs.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/ResourceManager.h>


namespace Sonicteam{
	namespace SoX{
		class IResource:public Sonicteam::SoX::RefCountObject
		{
		public:
			//size0x60
			IResource(void);
			~IResource();
			//virtual ~IResource(void);
			DESTRUCTION_H;



			//bool	
			virtual bool ResourceLoad(void* File,size_t size) = 0; // FileArrayPtr,FileSizeMb
			virtual int ResouceUnk02(); //return 0
			virtual std::string GetResourceName(std::string file_name) = 0;
			virtual int ResourceType(); //return 1




			//used for boost::bind
			bool ResourceLoadFinal(void* File,unsigned __int64 size);


			//fields

			unsigned int MgrRegistryIndex; //8

			std::string ResourceMgrName; //0xC .lua
			std::string ResourceName; //0x28 .lua
			std::string ResourceStr3; //0x44 .lua (ResourceArcName? After Load?)

			char IsInResourceManager; //or int 0x60
			char unk0x61;
			char unk0x62;
			char unk0x63;
		


			void SetResourceManagerMeta(unsigned int* i,std::string& m,std::string& r);




		};
	}
}

#endif

