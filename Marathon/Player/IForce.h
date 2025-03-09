#ifndef SONICTEAM__PLAYER__IFORCE
#define SONICTEAM__PLAYER__IFORCE


#include <Player/Defs.h>
#include <Sox/Memory/Destruction.h>
#include <Player/IPlugIn.h>
#include <Player/IFlagCommunicator.h>

namespace Sonicteam{
	namespace Player{


		class IForce:public Sonicteam::Player::IPlugIn,public Sonicteam::Player::IFlagCommunicator
		{
		public:
			IForce();
			~IForce();


			DESTRUCTION_H;
			
			unsigned int Flag1; //24
			unsigned int Flag2; //28
			unsigned int Flag3; //2c




			virtual void SetFlag01(DWORD flag_value);


			virtual void SetFlag02(DWORD flag_value);


			virtual void SetFlag08(DWORD flag_value);

		};

	}
}



#endif

