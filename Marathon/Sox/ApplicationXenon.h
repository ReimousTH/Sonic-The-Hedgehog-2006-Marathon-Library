#ifndef SONICTEAM__SOX__APPLICATIONXENON
#define SONICTEAM__SOX__APPLICATIONXENON



#define MARATHON_APP_XENON_MESSAGE_D3D_SETTHREADOWNERSHIP 0
#define MARATHON_APP_XENON_MESSAGE_D3D_2 1
#define MARATHON_APP_XENON_MESSAGE_RESIGNIN 2
#define MARATHON_APP_XENON_MESSAGE_3 3
#define MARATHON_APP_XENON_MESSAGE_4 4
#define MARATHON_APP_XENON_MESSAGE_GETSIGNINSTATE 5
#define MARATHON_APP_XENON_MESSAGE_SIGNIN 6
#define MARATHON_APP_XENON_MESSAGE_READ_PROFILESETTINGS 7
#define MARATHON_APP_XENON_MESSAGE_SHOW_DEVICE_SELECTOR_UI 8
#define MARATHON_APP_XENON_MESSAGE_GET_CONTENT_DEVICE_STATE 9
#define MARATHON_APP_XENON_MESSAGE_GET_SAVE_CREATOR 0xA
#define MARATHON_APP_XENON_MESSAGE_B 0xB
#define MARATHON_APP_XENON_MESSAGE_C 0xC
#define MARATHON_APP_XENON_MESSAGE_D 0xD
#define MARATHON_APP_XENON_MESSAGE_RESET 0xE

#include <Sox/Engine/Application.h>
#include <Sox/Perfomance.h>
#include <xtl.h>
#include <xonline.h>



namespace Sonicteam{

	namespace SoX{
		//Sonicteam::SoX::Engine::Application
		class ApplicationXenon:Sonicteam::SoX::Engine::Application
		{
		public:
			ApplicationXenon(void);
			~ApplicationXenon(void);

			DESTRUCTION_H;



			virtual void Run();
			virtual bool HandleMessage(size_t,size_t,size_t);
			virtual bool D3DSetShaderGPRAllocation();
			virtual void D3DRenderFrameAndSwapBuffers();
			virtual char IsPause();
			virtual char IsReturnToTitle();
			virtual size_t GetLocale();
			virtual size_t GetRegion();

			
			virtual bool WriteSaveFile(const char* SaveFileName,void* SaveFileBuffer,size_t SaveFileSize);
			virtual bool ReadSaveFile(const char* SaveFileName,void* ReadFileBuffer,size_t ReadFileSize);
			virtual bool CreateContent(const char* ContentName);
			virtual void GetDownloadContent(std::vector<std::string>& content);
			virtual void AppUnk0x38();
			virtual void OnDocAfter();
			

			//Extra

			void ProcessDoc(double delta);
			void ProcessXAM();
			void ProcessXAM2();
			void ProcessXAM3();
		

			//Xenon-Part
			size_t unk0xC; //C
			LARGE_INTEGER FisrtTimeBase; //0x10	
			LARGE_INTEGER FirstPerformanceFrequency; //0x18	
			size_t D3DDeviceState; //0x20
			D3DDevice* D3DDevice; //0x24
			size_t unk0x28; //0x28
			size_t unk0x2C; //0x2C
			size_t unk0x30; //0x30
	

			//later
			LARGE_INTEGER PerfScalePre; //0xE0
			LARGE_INTEGER PefScalePost; //0xE8

			IDirect3DTexture9* DestTexture; //0xF8


			DWORD ShaderVertexCount; // 0x114
			DWORD PixelShaderCount; // 0x118
			HANDLE HNotification; //0x11C


			char Lock1; //0x122
			char ToTitle; //0x123
			char Lock2; //0x124
			char IsUserSign; //0x125
			char Lock3; //0x126

			XUSER_SIGNIN_STATE LastSignInState; //0x128;
			DWORD NotifyTargetSignInStateMSG; //0x12C


			DWORD NotifyTargetSignInState; //0x148
			DWORD DefaultUserContextPresence; //0x14C
			DWORD DefaultUserContextValue[2]; //0x150

			DWORD ConfirmMessageNotify1; //0x158
			DWORD ConfirmMessageNotify2; //0x160
			DWORD ConfirmMessageNotify3; //0x168
			DWORD ConfirmMessageNotify4; //0x170

			MESSAGEBOX_RESULT SignInStatusChangedMSGResult;

			DWORD ConfirmMessageNotify5; //0x17C


	

			
			



			static DWORD SignInUserIndex; // TargetUserIndex (XamUserGetSigninState)
			static DWORD XDeviceUI;
			static ApplicationXenon*& ApplicationXenonMarathon;
		
			

	

		};
	}
}

#endif