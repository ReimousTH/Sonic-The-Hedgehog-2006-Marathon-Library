#ifndef SONICTEAM__PLAYER__ANIMATIONSCRIPT
#define SONICTEAM__PLAYER__ANIMATIONSCRIPT

#include "Defs.h"
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/RefCountObject.h>
#include <Sox/Physics/Entity.h>
#include <LuaSystem.h>
#include <Player/PackageModel/AnimationCB.h>


namespace Sonicteam{
	namespace Player{
		struct AnimationScript{
			AnimationScript();
			~AnimationScript();

			REF_TYPE(Sonicteam::LuaSystem) LuaSystem;
			std::deque<REF_TYPE(Sonicteam::Player::PackageModel::AnimationCB)> AnimationCB;


		};


	}
}




#endif



