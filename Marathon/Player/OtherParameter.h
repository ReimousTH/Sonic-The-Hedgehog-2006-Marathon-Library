

#ifndef SONICTEAM__PLAYER__OTHERPARAMETER
#define SONICTEAM__PLAYER__OTHERPARAMETER

#include "Defs.h"
#include <Player/RootFrame.h>
#include <Player/IPlugIn.h>
#include <Sox/RefCountObject.h>
#include <Combo/AttackManager.h>
#include <ActorManager.h>
#include <DocMarathonImp.h>
#include <boost/weak_ptr.hpp>



namespace Sonicteam{
	namespace Player{

		//82220C04
		class OtherParameter:public Sonicteam::Player::IPlugIn
		{
		public:
			OtherParameter(void);
			OtherParameter(void* Cameraman);
			~OtherParameter(void);

			unsigned int ObjectPlayerActorID;
			void* CameramanPlayer; //0x24

		
			boost::weak_ptr<Sonicteam::ActorManager> ActorManager; //0x28-2C
			REF_TYPE(Sonicteam::SoX::RefCountObject) WorldHavok; //0x30
			REF_TYPE(Sonicteam::Player::RootFrame) ObjectPlayerRootFrame; //0x34
			Sonicteam::DocMarathonImp* DocMarathon; //0x38 (DocMarathon)
			REF_TYPE(Sonicteam::Combo::AttackManager) ObjectPlayerComboAttackManager; //0x3C



			DESTRUCTION_H override;

		};
	}
}




#endif

