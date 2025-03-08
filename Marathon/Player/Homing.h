#ifndef SONICTEAM__PLAYER__HOMING
#define SONICTEAM__PLAYER__HOMING

#include "Defs.h"


#include <Sox/Physics/EntityContainer.h>
#include <Sox/RefCountObject.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Player/IPlugIn.h>
#include <Player/IPosturePlugIn.h>
#include <Player/IFlagCommunicator.h>
#include <Player/IStepable/IStepable.h>
#include <Player/IStepablePost.h>
#include <Player/IDynamicLink.h>
#include <Player/IVariable.h>
#include <Sox/Physics/Shape.h>
#include <Sox/Physics/Havok/ShapeHavok.h>
#include <Combo/AttackManager.h>
#include <Player/RootFrame.h>
#include <boost/function.hpp>


namespace Sonicteam{
	


	namespace Player{


		class Homing:public Sonicteam::Player::IPlugIn,Sonicteam::Player::IPosturePlugIn,Sonicteam::Player::IFlagCommunicator,Sonicteam::Player::IStepable,Sonicteam::Player::IStepablePost,Sonicteam::Player::IDynamicLink,Sonicteam::Player::IVariable{

		public:
			Homing();
			~Homing();

			virtual void SetFlag01(DWORD flag_value);

			virtual void OnStepable(float);

			virtual void OnStepablePost(float);

			virtual void OnVarible(LuaSystem**);

			unsigned int HomingStatePre; // == 2 enemy //0x38
			unsigned int HomingStateAfter; // == 2 enemy //0x3C
			float HomingTime; //think? //0x40
			boost::shared_ptr<Sonicteam::Player::LockOn> LockOn; //0x44,0x48
			boost::shared_ptr<Sonicteam::Player::LockOn> LockOnHoming; //0x4C,0x50
			unsigned int Homing0x54;
			unsigned int Homing0x58;
			unsigned int Homing0x5C;
			EntityContainer LockOnEntityAfter; //only if homing is processed (EntityContainer, need to make sure IF that really is here :| or maybe it complicated than i think) //x60
			EntityContainer LockOnEntityP; // not sure always stay same //0x70
			XMVECTOR HomingDirection; //0x80
			REF_TYPE(Sonicteam::Player::RootFrame) RootFrame; //0x90
			unsigned int HomingFlag; // count? 0x94
			unsigned int HomingFlag2; //  0x98
			float HomingFlag3; //  0x9C
			XMVECTOR LastHomingTargetPosition; //0xA0
			XMVECTOR LastHomingDistancePosition; //0xB0
			float unkC0; //0xC0
			XMVECTOR HomingVector0xD0; //0xD0
			float unk0xE4;
			float unk0xE8;
			float unk0xEC;

			REF_TYPE(Sonicteam::SoX::RefCountObject) HomingShapeCast; //82081B9C (restore class later :) //0x100
			REF_TYPE(Sonicteam::SoX::RefCountObject) HomingShapeCastListener; //boost::function<int(void*)> HomingFunction; //0x104 //	boost::function<int(void*)> HomingFunction; //0x104
			
			REF_TYPE(Sonicteam::SoX::Physics::Shape) HomingShape; //0x108
			HAVOK_SHAPE_SIMPLEPHANTOM_TYPE* HomingPhantom; //0x10C
			unsigned int unk0x110; 
			REF_TYPE(Sonicteam::Combo::AttackManager) AttackManager; //0x114
			unsigned int unk0x118;
			unsigned int unk0x11C;




			//0xE0

			DESTRUCTION_H;

	
		};

		

	}
}




#endif
