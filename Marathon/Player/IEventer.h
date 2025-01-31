

#ifndef SONICTEAM__PLAYER__IEVENTER
#define SONICTEAM__PLAYER__IEVENTER

#include "Defs.h"

#include <vector>
#include <Player/IDynamicLink.h>
#include <Player/IFlagCommunicator.h>
#include <Player/IStepable/IStepable.h>
#include <Player/INotification.h>
#include <Player/IEventerListener.h>

#define IEVENTER_CONTAINER boost::shared_ptr<Sonicteam::Player::IEventerListener>

namespace Sonicteam{
	namespace Player{

		//82220C04
		class IEventer:public Sonicteam::Player::IDynamicLink,public Sonicteam::Player::IFlagCommunicator,public Sonicteam::Player::IStepable,public Sonicteam::Player::INotification
		{
		public:
			IEventer(void);
			~IEventer(void);

			std::vector<IEVENTER_CONTAINER> EventerListener; //0x10

			void* UnkStruct0x10; //0x20 (82220C7C)
			//other stuff later



			virtual void DestroyObject(unsigned int flag) override;

		};
	}
}




#endif

