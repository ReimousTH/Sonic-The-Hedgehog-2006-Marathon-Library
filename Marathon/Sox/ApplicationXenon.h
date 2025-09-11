#ifndef SONICTEAM__SOX__APPLICATIONXENON
#define SONICTEAM__SOX__APPLICATIONXENON



#define MARATHON_APP_XENON_MESSAGE_D3D_SETTHREADOWNERSHIP 0
#define MARATHON_APP_XENON_MESSAGE_D3D_2 1
#define MARATHON_APP_XENON_MESSAGE_XAM_RESIGN 2
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
		class ApplicationXenon:public Sonicteam::SoX::Engine::Application
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
			inline void _Run();
		

			//Xenon-Part
			size_t unk0xC; //C
			LARGE_INTEGER FisrtTimeBase; //0x10	
			LARGE_INTEGER FirstPerformanceFrequency; //0x18	
			size_t D3DDeviceState; //0x20
			D3DDevice* _D3DDevice; //0x24

			
			//0x28->0x68 (pro more) ( struct , ref to it 82581E60)
			size_t D3DDeviceStateEnd; //0x28
			D3DDevice* _D3DDeviceOnEnd; //0x2C
			_D3DSURFACE_PARAMETERS SurfaceParams1; //0x30-0x34-0x38
			_D3DSURFACE_PARAMETERS SurfaceParams2; //0x3C-0x40-0x44
			_D3DSURFACE_PARAMETERS SurfaceParams3; //0x48-0x4C-0x50
			IDirect3DSurface9* Sample2SurfaceRef; //0x54
			IDirect3DSurface9* Sample2DepthStencilSurfaceRef; //0x58
			IDirect3DSurface9* Sample4SurfaceRef; //0x5C
			IDirect3DSurface9* Sample4DepthStencilSurfaceRef; //0x60
			D3DPRESENT_PARAMETERS D3DPresentParams; //0x64 -0xDC
			//probably end


			LARGE_INTEGER PerfScalePost; //0xE0
			LARGE_INTEGER PefScalePre; //0xE8

			alignas_8 char BufferInitialized; //0xF0
			alignas_8 IDirect3DTexture9* FrontBufferTexture; //0xF8
			IDirect3DSurface9* BackBufferSurface; //0xFC
			IDirect3DSurface9* DepthStencilSurface; //0x100
			IDirect3DSurface9* Sample2Surface; //0x104
			IDirect3DSurface9* Sample2DepthStencilSurface; //0x108
			IDirect3DSurface9* Sample4Surface; //0x10C
			IDirect3DSurface9* Sample4DepthStencilSurface; //0x110	


			DWORD ShaderVertexCount; // 0x114
			DWORD PixelShaderCount; // 0x118
			HANDLE HNotification; //0x11C


			char unk0x120; //0x120
			char unk0x121; //0x120
			char Lock1; //0x122
			char ToTitle; //0x123
			char Lock2; //0x124
			char IsUserSign; //0x125
			char Lock3; //0x126
			char unk0x127; //0x127

			XUSER_SIGNIN_STATE LastSignInState; //0x128;
			DWORD NotifyTargetSignInStateMSG; //0x12C
			DWORD unk0x130; //0x130
			DWORD unk0x134; //0x134
			DWORD unk0x138; //0x138
			DWORD unk0x13C; //0x13c
			DWORD unk0x140; //0x140
			DWORD unk0x144; //0x144

			DWORD NotifyTargetSignInState; //0x148
			DWORD DefaultUserContextPresence; //0x14C
			DWORD DefaultUserContextValue[2]; //0x150

			DWORD ConfirmMessageNotify1; //0x158
			DWORD ConfirmMessageNotify2; //0x15C
			DWORD ConfirmMessageNotify3; //0x160
			DWORD ConfirmMessageNotify4; //0x164
			DWORD ConfirmMessageNotify5; //0x168
			DWORD ConfirmMessageNotify6; //0x16C
			DWORD ConfirmMessageNotify7; //0x170

			MESSAGEBOX_RESULT SignInStatusChangedMSGResult; //0x174
			DWORD ConfirmMessageNotify8; //0x17C
			//End


	



			static DWORD SignInUserIndex; // TargetUserIndex (XamUserGetSigninState)
			static DWORD XDeviceUI;
			static ApplicationXenon*& ApplicationXenonMarathon;
		
			

	

		};
	}
}

#endif