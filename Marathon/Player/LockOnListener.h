#ifndef SONICTEAM__PLAYER__LOCKONLISTENER
#define SONICTEAM__PLAYER__LOCKONLISTENER


#include "Defs.h"
#include <Sox/Physics/PhantomListener.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/RefCountObject.h>
#include <Sox/Physics/Havok/WorldHavok.h>
#include <Sox/Physics/Shape.h>
#include <Sox/MessageReceiver.h>
#include <deque>

class LockOnListener:public Sonicteam::SoX::Physics::PhantomListener{
	LockOnListener();
	~LockOnListener();

	REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok; //0x8
	std::deque<EntityContainer> EntityDeque1; 	//0xC
	std::deque<EntityContainer> EntityDeque2; 	//0x20
	Sonicteam::SoX::MessageReceiver* Receiver; // usually to someone, player , entity ? 34
	unsigned int lockon_mode; //0x38
	DESTRUCTION_H;




};




#endif



