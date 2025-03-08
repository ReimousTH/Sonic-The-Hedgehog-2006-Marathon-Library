#ifndef SONICTEAM__PLAYER__LOCKON
#define SONICTEAM__PLAYER__LOCKON


#include <Player/ILockOn.h>

#include <Sox/Physics/Havok/WorldHavok.h>
#include <Sox/Physics/Entity.h>
#include <Player/RootFrame.h>
#include <Sox/Physics/EntityJoint.h>
#include <Player/LockOnListener.h>
#include <Sox/MessageReceiver.h>


namespace Sonicteam{
	namespace Player{


		class LockOn:public Sonicteam::Player::ILockOn
		{
		public:
			LockOn(Sonicteam::SoX::MessageReceiver* Receiver,const char* plugname,REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok,REF_TYPE(Sonicteam::Player::RootFrame) RootFrame);
			~LockOn(void);

			virtual void OnStepable(float);

			REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok; //0x28
			REF_TYPE(Sonicteam::SoX::Physics::Entity) Entity; //0x2c
			REF_TYPE(Sonicteam::Player::RootFrame) RootFrame; //0x30
			Sonicteam::SoX::Physics::EntityJoint EntityJoint; //0x34
			REF_TYPE(Sonicteam::Player::LockOnListener) LockOnListener; //0x54
			unsigned int unk0x58;
			Sonicteam::SoX::MessageReceiver* Receiver; // usually player/enjtity; //0x5C
			char unk0x60; //should be pad 61-64

		
		

			DESTRUCTION_H;


		};

	}
}



#endif

