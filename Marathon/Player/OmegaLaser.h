#ifndef SONICTEAM__PLAYER__OMEGALASER
#define SONICTEAM__PLAYER__OMEGALASER

#include "Defs.h"

#include <Sox/Physics/Havok/WorldHavok.h>
#include <Player/RootFrame.h>
#include <Sox/Engine/Task.h>

#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>

#include <Player/Effect/IParticle.h>

#include <Player/ObjectPlayer.h>
#include <Combo/AttackManager.h>

#include <Player/LTMJoint.h>
#include <Sox/Physics/Havok/BodyHavok.h>

#include <deque>

#include <Sox/Misc/LinkSoxNode.h>

#include <Sox/Physics/EntityContainer.h>


namespace Sonicteam{
	


	namespace Player{

	



		//YES size is correct, huh weird huh
		//weird, struct i think its bigger :| sadly vft lost
	

		class OmegaLaser:public Sonicteam::SoX::Engine::Task{

		public:
			OmegaLaser();
			~OmegaLaser();

			REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok; //0x4C
			REF_TYPE(Sonicteam::Player::RootFrame) RootFrame; //0x50

			boost::shared_ptr<Sonicteam::Player::Load> PLoad; //0x54
			boost::shared_ptr<Sonicteam::Player::LockOn> LockOn; //0x5C
			unsigned int unk0x64;
			float unk0x68;
			float unk0x6C;
			float unk0x70;
			unsigned int unk0x74;
			std::deque<EntityContainer> Entities; // 0x78
			Sonicteam::Player::Effect::IParticle* EffectIParticle; //0x8C
			Sonicteam::Player::ObjectPlayer* ObjectPlayer; //0x90
			REF_TYPE(Sonicteam::Combo::AttackManager) AttackManager; //0x94

			Sonicteam::Player::LTMJoint LaserPoint_A_Joint; //0x98
			Sonicteam::Player::LTMJoint LaserPoint_B_Joint; //0xB0
			Sonicteam::Player::LTMJoint LaserPoint_C_Joint; //0xC8
			Sonicteam::Player::LTMJoint LaserPoint_D_Joint; //0xE0
			Sonicteam::Player::LTMJoint LaserPoint_A01_Joint; //0xF0
			Sonicteam::Player::LTMJoint LaserPoint_B01_Joint; //0x110
			Sonicteam::Player::LTMJoint LaserPoint_C01_Joint; //0x128
			Sonicteam::Player::LTMJoint LaserPoint_D01_Joint; //0x140

			XMMATRIX LaserPoint_A_Joint_Transform; //0x160
			XMMATRIX LaserPoint_B_Joint_Transform; //0x1A0
			XMMATRIX LaserPoint_C_Joint_Transform; //0x1E0
			XMMATRIX LaserPoint_D_Joint_Transform; //0x220
			XMMATRIX LaserPoint_A01_Joint_Transform; //0x260
			XMMATRIX LaserPoint_B01_Joint_Transform; //0x2A0
			XMMATRIX LaserPoint_C01_Joint_Transform; //0x2E0
			XMMATRIX LaserPoint_D01_Joint_Transform; //0x320
		




			DESTRUCTION_H;

	
		};

		

	}
}




#endif
