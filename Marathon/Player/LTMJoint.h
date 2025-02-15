#ifndef SONICTEAM__PLAYER__LTMJOINT
#define SONICTEAM__PLAYER__LTMJOINT

#include "Defs.h"

#include <Sox/Physics/Havok/WorldHavok.h>
#include <Player/RootFrame.h>
#include <Sox/Engine/Task.h>

#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>

#include <Player/Effect/IParticle.h>

#include <Player/ObjectPlayer.h>
#include <Combo/AttackManager.h>

#include <Sox/Graphics/FrameObserver.h>

#include <deque>

#include <xtl.h>
#include <Xboxmath.h>


namespace Sonicteam{
	


	namespace Player{

	



		class LTMJoint:public Sonicteam::SoX::Graphics::FrameObserver{;

		public:
			LTMJoint();
			LTMJoint(REF_TYPE(Sonicteam::Player::RootFrame) RootFrame,const char* Joint,XMMATRIX* JointTransform);
			~LTMJoint();

			virtual void ObserveFrameStep(FrameObserverStepType);

			XMMATRIX* JointTransform;
			DESTRUCTION_H;

	
		};

		

	}
}




#endif
