#ifndef SONIC__PLAYER__ROTATIONGRAVITYAXIS
#define SONIC__PLAYER__ROTATIONGRAVITYAXIS


#include <Sox/Memory/Destruction.h>
#include <Player/IPosturePlugIn.h>


namespace Sonicteam{
	namespace Player{

		class RotationGravityAxis:Sonicteam::Player::IPosturePlugIn
		{
		public:
			RotationGravityAxis(void);
			~RotationGravityAxis(void);
			DESTRUCTION_H;
			XMVECTOR GravityVector; //821FB8EC (where it stores)
			

		};
	}
}

#endif

