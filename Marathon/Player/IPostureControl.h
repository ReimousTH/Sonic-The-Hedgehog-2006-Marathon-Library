

#ifndef SONICTEAM__PLAYER__IPOSTURECONTROL
#define SONICTEAM__PLAYER__IPOSTURECONTROL

#include "Defs.h"
#include <Player/Unit/ITestCase.h>
#include <Player/IVariable.h>
#include <Player/IDynamicLink.h>
#include <Player/IFlagCommunicator.h>
#include <player/RootFrame.h>
#include <Sox/Physics/Havok/WorldHavok.h>



namespace Sonicteam{
	namespace Player{
		
		class IPostureControl:Sonicteam::Player::IVariable,Sonicteam::Player::IDynamicLink,Sonicteam::Player::Unit::ITestCase,Sonicteam::Player::IFlagCommunicator
		{
		public:
			IPostureControl(void);
			~IPostureControl(void);

			REF_TYPE(Sonicteam::Player::RootFrame) RootFrame; //0x10
			XMVECTOR unk0x20; //0x20 (cuz padding)
			XMVECTOR unk0x30; //0x30 (cuz padding)
			REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok;

			//next is guess


	
			DESTRUCTION_H ;

		};
	}
}




#endif

