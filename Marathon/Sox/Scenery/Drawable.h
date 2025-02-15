#ifndef SONICTEAM__SOX__DRAWABLE
#define SONICTEAM__SOX__DRAWABLE

#include "Defs.h"



#include <xtl.h>
#include <SoX/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>
#include "CameraEventCallback.h"
#include <Sox/Graphics/FrameObserver.h>
#include <string>
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/Graphics/Frame.h>
#include <Sox/Scenery/Drawable.h>

namespace Sonicteam{
	namespace SoX{
		namespace Scenery{

			class Drawable:public Sonicteam::SoX::RefCountObject,public CameraEventCallback{
			public:
				class frameObserver:Sonicteam::SoX::Graphics::FrameObserver{

				public:

					frameObserver();
					~frameObserver();

					virtual void ObserveFrameStep(FrameObserverStepType) override;
					DESTRUCTION_H override;

					LinkSoxNode<frameObserver> ObserverLink;  //0x34,0x38,0x3C
					Sonicteam::SoX::Graphics::Frame* ObserverFrame; // or FrameGP //0x40
					Sonicteam::SoX::Scenery::Drawable* ObserverDrawable; // or FrameGP //0x44
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

				DESTRUCTION_H override;

				virtual void SSSD01() = 0;
				virtual void SSSD02(unsigned int*); //Vector Maybe, or XMAttric or Hybrid Struct
				virtual void SSSD03(unsigned int*);
				virtual void SSSD04(unsigned int*);
				virtual void SSSD05();
				virtual void SSSD06();
				virtual std::string SSSDGetDrawableName();
				virtual void ClearDrawable();
				virtual void SSSD09();


				virtual void CEC01() override;
				virtual void CEC02() override;
				virtual void CEC03() override;
				virtual void CEC04() override;
				virtual void CEC05() override;

				Sonicteam::SoX::Scenery::WorldImp*  WorldImp; //0xC
				unsigned int Index0Pre; //0x10 (0xFFFFFFFF) - possible (mostly they both same)
				unsigned int Index0Post; //0x14 (0x0000FFFF0 - why tho?
				unsigned int Index1; //No Idea //0x18
				unsigned int Index2; //0x1C
				frameObserver DrawableObserver; //0x20
			};



		}
	}
}
#endif