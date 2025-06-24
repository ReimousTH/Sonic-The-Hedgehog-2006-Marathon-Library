#ifndef SONICTEAM__SPANVERSE__ENV
#define SONICTEAM__SPANVERSE__ENV


#include <Spanverse/Defs.h>
#include <Sox/Graphics/Defs.h>
#include <Defs.h>


#include <System/Singleton.h>
#include <System/CreateStatic.h>
#include <Sox/Memory/Destruction.h>



#include <xtl.h>
#include <Sox/Misc/VectorExtension.h>

#include <Spanverse/SpanSPSB.h>


namespace Sonicteam{
	namespace Spanverse{
		class Env:Sonicteam::Spanverse::SpanSPSB{
			public:
			Env();
			~Env();

			Sonicteam::DocMarathonImp* DocMarathon; //0xA0
			Sonicteam::SoX::Graphics::Device* DocGraphicDevice; //0xA4
			char Flag0xA8; //pad = 4
			Sonicteam::SoX::Graphics::Shader* EnvShader; //0xAC
			Sonicteam::SoX::Graphics::TechniqueFXL* EnvTechniqueFXL1; //0xB0
			Sonicteam::SoX::Graphics::TechniqueFXL* EnvTechniqueFXL2; //0xB4
			Sonicteam::SoX::Graphics::TechniqueFXL* EnvTechniqueFXL3; //0xB8
			XMMATRIX EnvTransform; //usually player Camera :) //0xC0
			struct{ //size=0x30, since there NONE XMFLOAT3X4 welp 
				char Flag1;
				char Flag2;
				XMVECTOR Vector2;
				XMVECTOR Vector3;
			} EnvVector23Flag12[2];

			char EnvFlag0x160;
			char EnvFlag0x161;
			float EnvUnk0x164;
			float EnvUnk0x168;
			float EnvUnk0x16C;
			float EnvUnk0x170;
			char EnvFlag0x174;
			char EnvFlag0x175; //should just pad to 4 i think
			unsigned int unk0x178;
			unsigned int unk0x17C;
			unsigned int unk0x180;
			Sonicteam::Spanverse::EnvInfo* EnvInfo; //0x184
			unsigned int unk0x188;
			unsigned int unk0x18C;
			//0x190 - size



			DESTRUCTION_H;
			
		};
	};
};



#endif