#pragma once

#include "../IPlugIn.h"
#include "../IFlagCommunicator.h"
#include "../IStepable/IStepable.h"
#include "../IDynamicLink.h"
#include "../IVariable.h"
#include "../INotification.h"

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>


namespace Sonicteam{
	namespace Player{
		namespace Weapon{

			class SonicWeapons:IPlugIn,IFlagCommunicator,IStepable,IDynamicLink,IVariable,INotification
			{
			public:
				SonicWeapons(void);
				virtual ~SonicWeapons(void);





				///FIELDS
				unsigned int WorldHavokReference; // 820464EC ,0x34
				unsigned int PlayerRootFrame; //8200D150 ,0x38

				boost::shared_ptr<unsigned int> PlayerLoad; //820014F8 ,0x3C
				boost::shared_ptr<unsigned int> ActorManager; //82000904 ,0x44
				boost::shared_ptr<unsigned int> PlayerSonicEffect; //8200C3EC ,0x4C

				unsigned int SoXEngineTask; //820460EC ,0x54
				boost::shared_ptr<unsigned int> PlayerWeaponSonicSliding; //8200E4C8 ,0x58
				boost::shared_ptr<unsigned int> PlayerWeaponSonicBoundAttack; //8200E4E4 ,0x60
				boost::shared_ptr<unsigned int> PlayerWeaponSonicBoundEdge; //8200E4E4 ,0x68
				boost::shared_ptr<unsigned int> PlayerWeaponSonicThunderGuard; //8200E508 ,0x70
				boost::shared_ptr<unsigned int> PlayerWeaponSonicTornado; //8200E508 ,0x78

				unsigned int SWUnk0x80;
				unsigned int SWUnk0x84;
				unsigned int SWUnk0x88;
				unsigned int SWUnk0x8C; // self + 0x80 ?? why point to himself but -0xC wtf ?????

				unsigned int ObjectPlayerSonic; //82003564 ,0x90
				unsigned int DocMarathonState; //0x8200094C ,0x94

				char IsSlowTime;
				char IsShrinkCharacter;
				char unk9A;
				char unk9B;

				boost::shared_ptr<unsigned int> SonicCamera; //82002348 ,0x9C , Temp Module returns to 0 after shrink is done
				
				unsigned int SWUnk0xA0;
				unsigned int SWUnk0xA4;
				unsigned int SWUnk0xA8;
				float SWUnk0xAC; // == 2
				float SWUnk0xB0; // == 0.1
				unsigned int SWUnk0xB4;



		
			};
		}
		
	}
}

