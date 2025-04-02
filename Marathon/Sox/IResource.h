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
			virtual int ResourceLoad(void* File,size_t size) = 0; // FileArrayPtr,FileSizeMb
			virtual int ResouceUnk02(); //return 0
			virtual std::string GetResourceName(std::string file_name) = 0;
			virtual int ResourceType(); //return 1





			//fields

			unsigned int MgrRegistryIndex; //8

			std::string ResourceStr1; //0xC
			std::string ResourceStr2; //0x28
			std::string ResourceStr3; //0x44

			unsigned int IResouceUnk60; //or int




		};
	}
}

#endif

