
#ifndef SONICTEAM__FIXTURE
#define SONICTEAM__FIXTURE


#include "Defs.h"
#include <Actor.h>
#include <xtl.h>
#include <Sox/Physics/EntityJoint.h>
#include <Sox/Physics/Entity.h>
#include <SoX/Scenery/Clump.h>
#include <Sox/Graphics/Frame.h>

namespace Sonicteam{



	//not complete :(


	
	struct FixturePhysJoint{
		REF_TYPE(Sonicteam::SoX::Physics::EntityJoint) _joint;
		REF_TYPE(Sonicteam::SoX::Physics::Entity) _entity;
	};


	class Fixture:public Sonicteam::Actor
	{
	public:
		~Fixture();
		Fixture(Sonicteam::Actor* other, boost::weak_ptr<unsigned int>& gameimp);
		DESTRUCTION_H;


		//4 (methods virttual later :C)

		XMVECTOR Rotation; //0X60
		XMVECTOR Position; //0x70




		REF_TYPE(Sonicteam::SoX::Graphics::Frame) FFrame; //0x80 	Sonicteam::SoX::Graphics::FrameGP +-
		REF_TYPE(Sonicteam::SoX::RefCountObject) MyActivationObject; // 0x84 Sonicteam::MyActivationObject
		std::vector<FixturePhysJoint> arrjoint1; //0x88
		std::vector<FixturePhysJoint> arrjoint2; //0x98


		boost::shared_ptr<size_t> unk0xA8; //FixtureStateManager
		boost::shared_ptr<size_t> unk0xB0; //Sonicteam::SoX::AI::StateMachine<Sonicteam::Fixture>:
		boost::shared_ptr<size_t> AnimController; //0xB8 Sonicteam::AnimController (no vft, boost saved it)
		std::vector<REF_TYPE(Sonicteam::SoX::Scenery::Clump)> VClump1; //0xC0
		std::vector<REF_TYPE(Sonicteam::SoX::Scenery::Clump)> VClump2; //0xD0
		std::vector<REF_TYPE(Sonicteam::SoX::RefCountObject)> VRagdoll1; //0xE0 //Sonicteam::SoX::Physics::Ragdoll
		std::vector<REF_TYPE(Sonicteam::SoX::RefCountObject)> VAnimationHierarchy; //0xF0 //Sonicteam::SoX::Graphics::AnimationHierarchyCommon:
		REF_TYPE(Sonicteam::SoX::RefCountObject) AnimationHierarchy; //0x100 Sonicteam::SoX::Graphics::AnimationHierarchyCommon
		REF_TYPE(Sonicteam::SoX::RefCountObject) AnimationHierarchy2; //0x104 Sonicteam::SoX::Graphics::AnimationHierarchyCommon
		size_t unk0x108; //0x108
		size_t unk0x10C; //0x10C
		std::vector<REF_TYPE(Sonicteam::SoX::RefCountObject)> VMaterialAnimationInstance; //0x110
		REF_TYPE(Sonicteam::SoX::RefCountObject) MaterialAnimationInstance;  //0x120
		REF_TYPE(Sonicteam::SoX::RefCountObject) unk0x124;  //0x124
		size_t unk0x128; //0x128
		size_t unk0x12C; //0x12c
		size_t unk0x130; //0x130
		size_t unk0x134; //0x134
		size_t unk0x138; //0x138
		size_t unk0x13C; //0x13c
		size_t unk0x140; //0x140

		std::vector<size_t> vunk0x140;
		REF_TYPE(Sonicteam::SoX::RefCountObject) unk0x150;
		REF_TYPE(Sonicteam::SoX::RefCountObject) unk0x154;
		size_t unk0x158;
		size_t unk0x15C;
		size_t unk0x160;
		REF_TYPE(Sonicteam::SoX::Scenery::Clump) FClump; // 0x164 Sonicteam::`anonymous namespace'::MyClump:
		size_t unk0x168; //0x168 flag
		size_t unk0x16C; //0x16C 
	


	};
};

#endif