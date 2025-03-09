#ifndef SONICTEAM__PLAYER__GRAVITY
#define SONICTEAM__PLAYER__GRAVITY



#include <Player/Defs.h>
#include <xtl.h>



#include <Sox/Memory/Destruction.h>
#include <Player/IForce.h>
#include <Player/IVariable.h>
#include <Player/IStepable/IStepable.h>

namespace Sonicteam{
	namespace Player{


		class Gravity:Sonicteam::Player::IForce,Sonicteam::Player::IVariable,Sonicteam::Player::IStepable
		{
		public:
			Gravity();
			~Gravity();

			DESTRUCTION_H;
			virtual XMFLOAT3* GetGravityDirection(); //const force
			virtual double GetGravityDownForce(); // full down force

	
			virtual void OnVarible(IVARIABLETYPE);
			virtual void OnStepable(float);


			float gravity; //0x38
			float c_pass_fluid; //0x3C
			bool ForceUP; //Allow ForceUP Vector //0x40
			float GravityDownForce; //0x44
			XMFLOAT3 GravityDirection; //0x50(padding since) 
			//0x60 (size)


		};

	};
};



#endif

