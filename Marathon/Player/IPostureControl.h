

#ifndef SONICTEAM__PLAYER__IPOSTURECONTROL
#define SONICTEAM__PLAYER__IPOSTURECONTROL

#include "Defs.h"
#include <Player/Unit/ITestCase.h>
#include <Player/IVariable.h>
#include <Player/IDynamicLink.h>
#include <Player/IFlagCommunicator.h>
#include <player/RootFrame.h>
#include <Player/Gravity.h>
#include <Sox/Physics/Havok/WorldHavok.h>
#include <boost/weak_ptr.hpp>
#include <Player/IPosturePlugIn.h>

#include <Player/Input/IListener.h>
#include <Player/AI/IBase.h>
#include <Player/State/IContext.h>
#include <Player/State/ICommonContextIF.h>


#include <Player/ObjectPlayer.h>

#include <Sox/Misc/VectorExtension.h>

#include <D3d9types.h>



namespace Sonicteam{
	namespace Player{
		
		


		struct IPostureControlFlag{
			unsigned int PostureRequestFlag; //0x114
			//00 00 00 00 default
			//00 00 00 40 run(moving?) on ground
			//00 00 00 04 jump()
			//00 00 00 12 stuck(or chainjump_start) or ignore gravity?
			unsigned int PostureFlag0x118; // no idea (821FDDD0(lock movement at all?) ?? here somehing)
			unsigned int PostureFlag0x11C; // no info

		};
		class IPostureControl:public Sonicteam::Player::IVariable,
			public Sonicteam::Player::IDynamicLink,
			public Sonicteam::Player::Unit::ITestCase,
			public Sonicteam::Player::IFlagCommunicator
		{
		public:
			IPostureControl(REF_TYPE(Sonicteam::Player::RootFrame) RootFrame,REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok);
			~IPostureControl(void);


			REF_TYPE(Sonicteam::Player::RootFrame) RootFrame; //0x10
			XMVECTOR RotationFixed; //0x20 (cuz padding) (not editable)
			XMVECTOR PositionFixed; //0x30 (cuz padding) (not editable)
			REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok; //0x40
			boost::shared_ptr<Sonicteam::Player::Gravity> Gravity; //0x44
			boost::shared_ptr<Sonicteam::Player::Input::IListener> InputListener; //0x4C
			boost::shared_ptr<Sonicteam::Player::Input::IListener> AmigoListener; //0x54
			boost::shared_ptr<Sonicteam::Player::State::ICommonContextIF> IContextIF; //0x5C
			boost::shared_ptr<Sonicteam::ActorManager> ActorManager; //0x64
			Sonicteam::SoX::Engine::Task* PostureTask; //0x6C , since  821F1B38, send message, i think there should be MoreLike PostureComponent, since :| but for later :)
			boost::shared_ptr<Sonicteam::Player::IPosturePlugIn> IPosturePlugIn; // either weak_ptr or just PTR Path() no idea how to figure name (crash 0x821F15A8, snowboard can) //0x70
			//next is guess (0x78)
			XMVECTOR GravityDirection; /// I think since 0,-1,0,1 (0x80 since padding) (821F1FBC where it stores) (can be changed only from gravity modulke)
			float GravityDownForce; //0x90
			XMVECTOR NormalizedSurface; //0xA0  //821F0DC8 + when is nothing to collide GravityDirection used as normalizedsurface(but after normalie)
			XMVECTOR Position; //0xB0
			XMVECTOR Rotation; //0xC0
			XMVECTOR unk0xD0; //0xD0
			XMVECTOR unk0xE0; //maybe Vector Or NO	
			unsigned int IPosturePlugInFlag; //0xF0
			float ImpulseZX; //0xF4
			float ImpulseY; //0xF8
			//0x100
			XMVECTOR ImpulseVectorUP; // 821FDFEC (here where it stores) 0x100
			//INFO
			unsigned int ContextIFFlag; //0x110
			//01 00 00 00 default or stand
			//01 00 00 80 default + run
			//01 00 00 C0 default + jump
			//01 00 40 00 default + spindash
			//01 00 40 04 default + spindash_release
			//01 00 50 0C default + spin kick
			//01 00 00 C8 default + bound, gove to jump after bound end
			//11 00 00 C4 default + homing
			//11 00 00 C8 default + homing_after
			//01 00 01 88 default + dashpanel(or higher speed?)
			//01 00 05 08 default + waterslider
			//01 00 09 C8 default + spring
			//01 00 08 C0 default + spring_end
			//01 00 00 A8 default + chainjump(on)
			//01 00 00 E8 default + chainjump(action)
			//01 00 04 80 default + grind

			//01 00 00 80 - after land from jump panel before any move

			//01 00 00 E0 - Tails Fly

			//01 00 40 C4 - tails roll air
			//01 00 40 04 - tails roll gound


			//01 00 00 E0 - tails fly

			//0x80 | 0x40 = 0xC0
			//0x40 - Air Flag

			//0x20 - Tails Flag Fly Flag

			//0x8 - Bound Flag
		
			//0x400 - grind?



			IPostureControlFlag IPostureControlFlag0x114;

		
		

			virtual void IPostureControlOn();// -- unk?>
			virtual void IPostureControlStep(double); 
			virtual void IPostureControlImport(XMVECTOR&,double) = 0;



			XMVECTOR PlayerGetTransformData();
	
			DESTRUCTION_H ;

		};
	}
}




#endif

