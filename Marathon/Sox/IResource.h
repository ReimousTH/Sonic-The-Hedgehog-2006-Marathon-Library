#pragma once

#include <string>

#include <Sox/RefCountObject.h>

namespace Sonicteam{
	namespace SoX{
		class IResource:public Sonicteam::SoX::RefCountObject
		{
		public:
			//size0x60
			IResource(void);
			~IResource();
			//virtual ~IResource(void);
			virtual void DestroyObject(unsigned int flag) override;



			//bool
			virtual int ResourceLoad(void* FilePTR,size_t FileSize) = 0; // FileArrayPtr,FileSizeMb
			virtual int ResouceUnk02(); //return 0
			virtual std::string GetResourceName(std::string* file_name) = 0;
			virtual int ResourceUnk04(); //return 1





			//fields
	
			unsigned int IResouceUnk8;

			std::string ResourceStr1;
			std::string ResourceStr2;
			std::string ResourceStr3;

			unsigned int IResouceUnk60; //or int

		

			
		};
	}
}
