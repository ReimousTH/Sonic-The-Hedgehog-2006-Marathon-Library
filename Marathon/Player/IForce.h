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
			
			unsigned int IPosturePlugInFlag; //24
			unsigned int ICommonContextIFFlag; //28
			unsigned int PostureRequestFlag; //2c




			virtual void ImportICommonContextIFFlag(DWORD flag_value);


			virtual void ImportIPosturePlugInFlag(DWORD flag_value);


			virtual void ImportPostureRequestFlag(DWORD flag_value);

		};

	}
}



#endif

