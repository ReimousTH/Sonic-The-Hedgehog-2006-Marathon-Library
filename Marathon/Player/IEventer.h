

#ifndef SONICTEAM__PLAYER__IEVENTER
#define SONICTEAM__PLAYER__IEVENTER

#include "Defs.h"

#include <vector>
#include <Player/IDynamicLink.h>
#include <Player/IFlagCommunicator.h>
#include <Player/IStepable/IStepable.h>
#include <Player/INotification.h>

#include <Player/IEventerListener.h>
#include <Player/IEventerSharedWork.h>

#include <Player/Gauge/IGauge.h>
#include <Player/IScore.h>
#include <Player/IModel.h>
#include <boost/weak_ptr.hpp>


#define IEVENTER_CONTAINER boost::shared_ptr<Sonicteam::Player::IEventerListener>



namespace Sonicteam{
	namespace Player{
		class IPath;

		//82220C04
		class IEventer:public Sonicteam::Player::IDynamicLink,public Sonicteam::Player::IFlagCommunicator,public Sonicteam::Player::IStepable,public Sonicteam::Player::INotification
		{
		public:
			IEventer(void);
			~IEventer(void);

			std::vector<IEVENTER_CONTAINER> EventerListener; //0x10
			boost::shared_ptr<IEventerSharedWork> EventerSharedWork; //0x20-0x24
			unsigned int UnkFlags0x28; 
			boost::weak_ptr<Sonicteam::Player::IScore> EventerScore; //0x2C
			boost::weak_ptr<Sonicteam::Player::IPath> EventerPath; //0x34
			unsigned int UnkFlags0x3C;
			boost::weak_ptr<Sonicteam::Player::IModel> EventerModel; //0x40
			unsigned int UnkFlags0x48;
			unsigned int UnkFlags0x4C;
			float EventerGaugeValue; //0x50
			boost::weak_ptr<Sonicteam::Player::IGauge> EventerGauge;// 0x54
			unsigned int unk0x5C;
			unsigned int unk0x60;
			float unk0x64;


			virtual void DestroyObject(unsigned int flag) override;

		};
	}
}




#endif

