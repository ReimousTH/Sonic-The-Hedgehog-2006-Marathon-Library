#ifndef SONICTEAM__SOX__CLUMP
#define SONICTEAM__SOX__CLUMP


#include "Defs.h"

#include <xtl.h>
#include <SoX/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>
#include "Drawable.h"

namespace Sonicteam{
	namespace SoX{
		namespace Scenery{
			class Clump:public Drawable{

			public:
				Clump();
				~Clump();

				DESTRUCTION_H override;

				virtual void SSSD01() override; //0x4
				virtual void SSSD02(unsigned int*) override; //0x8
				virtual void SSSD03(unsigned int*) override; //0xC
				virtual void SSSD04(unsigned int*) override; //0x10
				virtual void SSSD05() override; //0x14
				virtual void SSSD06() override; //0x18
				virtual std::string SSSDGetDrawableName() override; //0x1C
				virtual void ClearDrawable() override; //0x20
				virtual void SSSD09() override; //0x24

				virtual void CEC01() override;
				virtual void CEC02() override;
				virtual void CEC03() override;
				virtual void CEC04() override;
				virtual void CEC05() override;

				unsigned int unk0x70;
			
			};
		}
	}
}
#endif