#pragma once

#include <xtl.h>
#include <SoX/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>
#include "CameraEventCallback.h"
#include <Sox/Graphics/FrameObserver.h>
#include <string>


namespace Sonicteam{
	namespace SoX{
		namespace Scenery{
			class Drawable:Sonicteam::SoX::RefCountObject,public CameraEventCallback{
			public:
				class frameObserver:Sonicteam::SoX::Graphics::FrameObserver{

				public:

					frameObserver();
					~frameObserver();

					virtual void ObserveFrameStep(double a1) override;
					virtual void DestroyObject(unsigned int flag) override;

					unsigned int unk0x34;
					unsigned int unk0x38;
					unsigned int unk0x3C;
					unsigned int unk0x40;
					unsigned int unk0x44;
					unsigned int unk0x48;
					unsigned int unk0x4C;
					unsigned int unk0x50;
					unsigned int unk0x54;
					unsigned int unk0x58;
					unsigned int unk0x5C;
					unsigned int unk0x60;
					unsigned int unk0x64;
					unsigned int unk0x68;
					unsigned int unk0x6C;
					//unsigned int unk0x70; (CTownsmanDrawable have as byte SO NO )
				};
				Drawable();
				~Drawable();

				virtual void DestroyObject(unsigned int flag) override;

				virtual void SSSD01() = 0;
				virtual void SSSD02(unsigned int*); //Vector Maybe, or XMAttric or Hybrid Struct
				virtual void SSSD03(unsigned int*);
				virtual void SSSD04(unsigned int*);
				virtual void SSSD05();
				virtual void SSSD06();
				virtual std::string SSSDGetDrawableName();
				virtual void SSSD08();
				virtual void SSSD09();


				virtual void CEC01() override;
				virtual void CEC02() override;
				virtual void CEC03() override;
				virtual void CEC04() override;
				virtual void CEC05() override;

				unsigned int unk0xC;
				unsigned int unk0x10;
				unsigned int unk0x14;
				unsigned int unk0x18;
				unsigned int unk0x1C;
				frameObserver DrawableObserver;
			};



		}
	}
}