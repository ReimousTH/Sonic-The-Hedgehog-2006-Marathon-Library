#ifndef Sonicteam__SOX__Graphics__MODEL
#define Sonicteam__SOX__Graphics__MODEL



#include "Defs.h"



#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>


#include <XboxMath.h>
#include <d3d9.h>
#include <D3d9types.h>

#include <Sox/Graphics/Xenon/TextureXenon.h>
#include <Sox/Graphics/DrawPrimitiveCache.h>
#include <Sox/Graphics/ShaderCommon.h>
#include <Sox/Graphics/FrameBufferObject.h>

namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


	
			//:)
			class Device //Need Aditional Methods, FullClearLink()
			{

			public:
				Device();
				~Device();
				DESTRUCTION_H;

				virtual bool ProcessDevice01(unsigned int flag,void*,void*,double); // shadows/light?
				virtual void ProcessDevice02(void*); // 
				virtual void ProcessDevice03(void*); // 
				virtual void ProcessDevice04(void*); // 
				virtual void ProcessDevice05(unsigned int,unsigned int,unsigned int,size_t); // 
				virtual void ProcessDevice06(void*,void*,void*,void*,void*); //  ?
				virtual void ProcessDevice07(size_t,unsigned int,void*,void*,void*,size_t); // 
				virtual void ProcessDevice08(unsigned int,unsigned int); // 
				virtual void ProcessDevice09(void*,void*,void*); // 
				virtual void ProcessDevice0A(size_t,void*,size_t); // 
				virtual void ProcessDevice0B(void*,unsigned int); // 
				virtual void ProcessDevice0C(void*,void*,void*); // 
				virtual void ProcessDevice0D(void*,size_t,void*); // 
				virtual void ProcessDevice0E(); // 
				virtual void ProcessDevice0F(); // 
				virtual void ProcessDevice010(); // 
				virtual void DeviceBlockUntilIdle();
				virtual void SetFlag0x150to1();
				virtual void SetFlag0x150to0();
				virtual void SetUnkRenderFlag(unsigned int);
				virtual void ProcessDevice015(unsigned int);
				virtual void ProcessDevice016();
				virtual void ProcessDevice017(); //empty
				virtual REF_TYPE(Sonicteam::SoX::Graphics::DrawPrimitiveCache) GetDrawPrimitiveCache();
				Sonicteam::SoX::Graphics::Lights* GetLights();
				Sonicteam::SoX::Graphics::RenderStates* GetRenderStates();
				Sonicteam::SoX::Graphics::TextureStages* GetTextureStages();
				virtual bool ProcessDevice01C();
				virtual void ProcessDevice01D();
				virtual unsigned int ProcessDevice01E();
				virtual void ProcessDevice01F();
				virtual void ProcessDevice020();
				virtual void SetAmbientColor(D3DCOLORVALUE*);
				virtual void ProcessDevice022(void*);
				virtual void GSetViewport(D3DVIEWPORT9*);
				virtual void GSetClipPlaneVector(size_t ClipPlaneIndex,D3DVECTOR4* ClipPlaneVector);
				virtual void GSetScissorRect(RECT* rect);
				virtual void ProcessDevice026(REF_TYPE(Sonicteam::SoX::RefCountObject));
				virtual void ProcessDevice027(size_t index,Sonicteam::SoX::Graphics::VertexBuffer*,size_t index2,void*); //since function unused seems i no idea about last arg
				virtual void ProcessDevice028(size_t index,size_t index2,void* ptr); 
				virtual void ProcessDevice029(size_t index,size_t index2,void* ptr,size_t index3); 
				virtual void ProcessDevice02A();  //nulsub
				virtual void ProcessDevice02BEX(Sonicteam::SoX::Graphics::TechniqueFXL*,D3DVECTOR4,void*,double,double,double,double); 
				virtual void ProcessDevice02B(Sonicteam::SoX::Graphics::TechniqueFXL*,D3DVECTOR4,void*);
				virtual void ProcessDevice02C(const char*,int,int);
				virtual void ProcessDevice02D();  //nulsub
				virtual void SetTextureXenonIndexed(size_t index,Sonicteam::SoX::Graphics::Xenon::TextureXenon*);  //
				virtual void SetViewportParam(size_t index,unsigned int prm1,unsigned int prm2);
				virtual void* Getunk2F8(); //0x28-size??
				virtual void* Getunk320();


				unsigned int unk0x4;
				unsigned int unk0x8;
				unsigned int unk0xC;
				REF_TYPE(Sonicteam::SoX::RefCountObject) unk0x10; //0x10
				REF_TYPE(Sonicteam::SoX::Graphics::ShaderCommon) DShader; //0x14
				unsigned int DBRFlag; //18
				unsigned int unk0x1C;
				Sonicteam::SoX::Graphics::Lights* DLights; //0x20
				Sonicteam::SoX::Graphics::RenderStates* DRenderStates; //24
				Sonicteam::SoX::Graphics::TextureStages* DTextureStages; //28
				Sonicteam::SoX::Graphics::Transform* DTransform; //0x2C
				XMFLOAT3 unk0x30; //?
				XMFLOAT4X4 unk0x40;
				unsigned int unk0x80;
				unsigned int unk0x84;
				unsigned int unk0x88;
				unsigned int unk0x8C;
				unsigned int unk0x90;
				unsigned int unk0x94;
				unsigned int unk0x98;
				unsigned int unk0x9C;
				unsigned int unk0xA0;
				unsigned int unk0xA4;
				unsigned int unk0xA8;
				unsigned int unk0xAC;
				unsigned int unk0xB0;
				unsigned int unk0xB4;
				unsigned int unk0xB8;
				unsigned int unk0xBC;
				REF_TYPE(Sonicteam::SoX::Graphics::FrameBufferObject) DFrameBufferObject; //0xC0;
				unsigned int unk0xC4;
				unsigned int unk0xC8;
				unsigned int unk0xCC;

				//0x154 D3D::CDevice -- 0xC4 is Block

			



			};
		};
	}
}

#endif

