#pragma once

#include <Sox/RefCountObject.h>
#include <sox/IResource.h>
#include <Chao/CSD/CPlatform.h>




namespace Sonicteam{


	 
	//Or SonicTeamSoxComponent
	class CPlatformMarathon:Chao::CSD::CPlatform
		{
		public:
			CPlatformMarathon(void);
			~CPlatformMarathon(void);

			virtual void DebugMessageA(LPCSTR lpOutputString);

			virtual int GetCPlatform0x8();

			virtual void CPDrawPrimiteCache0xC(unsigned int);

			virtual void CPSSetDrawPrimiteFlag0x10(unsigned int);

			virtual void CPlatform0x14(unsigned int, unsigned int);

			virtual void CPlatform0x18();

			virtual void CPSSetDrawPrimiteFlagA0x1C(unsigned int);

			virtual void CPlatform0x20(unsigned int, unsigned int);

			virtual void CPlatform0x24();

			virtual void CPDrawPrimiteCache0x28();

			virtual void CPDrawPrimiteCache0x2C();


		protected:
			unsigned int FCPlatform0x4;
			unsigned int FCPlatformFlag0x8;
			unsigned int FCPlatform0xC;
			Sonicteam::SoX::IResource* FCPlatformShader; //CSD
			Sonicteam::SoX::RefCountObject* FCPlatformResource0x14;
			Sonicteam::SoX::RefCountObject* FCPlatformResource0x18;

		
	

	};
};