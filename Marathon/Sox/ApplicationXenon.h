#pragma once

#include <Sox/Object.h>
#include <xtl.h>



namespace Sonicteam{
	class DocMarathonImp;
	namespace SoX{
		class ApplicationXenon:Sonicteam::SoX::Object,Sonicteam::SoX::IOObject
		{
		public:
			ApplicationXenon(void);
			virtual ~ApplicationXenon(void);
			virtual char* GetObjectType();

			virtual void ApplicationXenonM1(void);
			virtual void ApplicationConsoleMessages(unsigned int,unsigned int,unsigned int); //Get User Signing State and more 825B2400
			virtual void ApplicationXenonD3DDevice_SetShaderGPRAllocation(void);
			virtual void ApplicationXenonD3DDevice_SetShaderGPRAllocation_KickOFF(void);
			virtual unsigned int ApplicationXenonM5(void); // *(unsigned __int8 *)(a1 + 0x126) | *(unsigned __int8 *)(a1 + 0x124) | *(unsigned __int8 *)(a1 + 0x122);
			virtual unsigned int ApplicationXenonM6(void); //*(unsigned __int8 *)(a1 + 0x123);
			virtual unsigned int ApplicationXenonGetFixedGameRegion(void); 
			virtual unsigned int ApplicationXenonGetFixedGameRegion2(void); //*(unsigned __int8 *)(a1 + 0x123);
			virtual unsigned int ApplicationXenonProcessSaveGameFile(const char* SaveFileName,byte* EndFileSaveBuffer,unsigned int EndFileSaveBufferSize ); //*(unsigned __int8 *)(a1 + 0x123);
			virtual unsigned int ApplicationXenonProcessLoadGameFile(const char* SaveFileName,byte* LoadFileSaveBuffer,unsigned int EndFileSaveBufferSize ); //*(unsigned __int8 *)(a1 + 0x123);
			virtual unsigned int ApplicationXenonProcessIsXamContentCreate(const char* SaveFileName);
			virtual unsigned int ApplicationXenonProcessDLC(unsigned int); //PTR
			virtual unsigned int ApplicationXenonMD()  = 0; //PTR
			virtual unsigned int ApplicationXenonME()  = 0; //PTR



			LARGE_INTEGER AXuai0x10;	
			LARGE_INTEGER PerformanceFrequency; //Queary
			unsigned int AXuint0x20;
			unsigned int AXuint0x24;
			unsigned int AXuint0x28;
			unsigned int AXuint0x2C;
			unsigned int AXuint0x30;
			unsigned int AppD3DDevice;
			unsigned int AXuint0x38;
			unsigned int AXuint0x3C;
			unsigned int AXuint0x40;
			unsigned int AXuint0x44;
			unsigned int AXuint0x48;
			unsigned int AXuint0x4C;
			unsigned int AXuint0x50;
			unsigned int AXuint0x54;
			unsigned int AXuint0x58;
			unsigned int AXuint0x5C;
			unsigned int AXuint0x60;
			unsigned int AXuint0x64;
			unsigned int AXuint0x68;
			unsigned int AXuint0x6C;
			unsigned int AXuint0x70;
			unsigned int AXuint0x74;
			unsigned int AXuint0x78;
			unsigned int AXuint0x7C;
			unsigned int AXuint0x80;
			unsigned int AXuint0x84;
			unsigned int AXuint0x88;
			unsigned int AXuint0x8C;
			unsigned int AXuint0x90;
			unsigned int AXuint0x94;
			unsigned int AXuint0x98;
			unsigned int AXuint0x9C;
			unsigned int AXuint0xA0;
			unsigned int AXuint0xA4;
			unsigned int AXuint0xA8;
			unsigned int AXuint0xAC;
			unsigned int AXuint0xB0;
			unsigned int AXuint0xB4;
			unsigned int AXuint0xB8;
			unsigned int AXuint0xBC;
			unsigned int AXuint0xC0;
			unsigned int AXuint0xC4;
			unsigned int AXuint0xCC;
			unsigned int AXuint0xD0;
			unsigned int AXuint0xD4;
			unsigned int AXuint0xD8;
			unsigned int AXuint0xDC;
			unsigned long long AXuint0xE0;
			unsigned long long AXuint0xE8;
			unsigned int AXuint0xF0;
			unsigned int AXuint0xF4;
			unsigned int AXuint0xF8;
			unsigned int AXuint0xFC;
			unsigned int AXuint0x100;
			unsigned int AXuint0x104;
			unsigned int AXuint0x108;
			unsigned int AXuint0x10C;
			unsigned int AXuint0x110;
			unsigned int AXuint0x114;
			unsigned int AXuint0x118;
			unsigned int AXuint0x11C;

			unsigned int AXuint0x120;
			unsigned int AXuint0x124;
			unsigned int AXuint0x128;
			unsigned int AXuint0x12C;
			unsigned int AXuint0x130;
			unsigned int AXuint0x134;
			unsigned int AXuint0x138;
			unsigned int AXuint0x13C;
			unsigned int AXuint0x140;
			unsigned int AXuint0x144;
			unsigned int AXuint0x148;
			unsigned int AXuint0x14C;
			unsigned int AXuint0x150;
			unsigned int AXuint0x154;

			unsigned int AXuint0x158;	
			unsigned int AXuint0x15C;	
			unsigned int AXuint0x160;	
			unsigned int AXuint0x164;	
			unsigned int AXuint0x168;
			unsigned int AXuint0x16C;	
			unsigned int AXuint0x170;	
			unsigned int AXuint0x174;	
			unsigned int AXuint0x178;	
			unsigned int AXuint0x17C;	
			Sonicteam::DocMarathonImp* DocMarathon;	 //APPLICATGION_MARATHON MOVE LATER (or DocMode, ???) DocMarathonState
			//mb



			static ApplicationXenon*& ApplicationXenonMarathon;
			

			
		};
	}
}
