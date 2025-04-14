
#ifndef SONICTEAM__SOX__ENGINE__APPLICATION
#define SONICTEAM__SOX__ENGINE__APPLICATION

#include <Sox/Engine/Defs.h>
#include <Sox/Misc/Aligment.hpp>


#include <Sox/Object.h>
#include <Sox/Engine/Doc.h>
#include <xtl.h>
#include <vector>


namespace Sonicteam{

	namespace SoX{


		namespace Engine{

			class Application:Sonicteam::SoX::Object
			{

			public:	


				Application(void);
				~Application(void);
				DESTRUCTION_H;
				char* GetObjectType();
				virtual void Run() = 0;
				virtual bool HandleMessage(size_t,size_t,size_t);
				virtual bool D3DSetShaderGPRAllocation();
				virtual void D3DRenderFrameAndSwapBuffers();
				virtual char IsPause();
				virtual char IsReturnToTitle();
				virtual size_t GetXLocal(); //XGetLocale
				virtual size_t GetRegion(); //XGetRegion
				virtual bool WriteSaveFile(const char* SaveFileName,void* SaveFileBuffer,size_t SaveFileSize); //SonicNextSaveData.bin
				virtual bool ReadSaveFile(const char* SaveFileName,void* ReadFileBuffer,size_t ReadFileSize); //SonicNextSaveData.bin
				virtual bool CreateContent(const char* ContentName);
				virtual void GetDownloadContent(std::vector<std::string>& content);
				virtual void AppUnk0x38(); //empty
				virtual void OnDocAfter(); //empty


		


			



				//0xF8 -> IDirect3DTexture9 (->Release)



				char IsDisabled; // 4
				alignas_4 Sonicteam::SoX::Engine::Doc* AppDoc; //8

			

			};
		};
	}
}
#endif