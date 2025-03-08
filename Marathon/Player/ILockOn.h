#ifndef SONICTEAM__PLAYER__ILOCKON
#define SONICTEAM__PLAYER__ILOCKON




#include <Player/IPlugIn.h>
#include <Player/IStepable/IStepable.h>
#include <Sox/Physics/EntityContainer.h>
#include <Player/RootFrame.h>
#include <Sox/Physics/Entity.h>

namespace Sonicteam{
	namespace Player{


		class ILockOn:public Sonicteam::Player::IPlugIn,public Sonicteam::Player::IStepable
		{
		public:
			ILockOn(const char* plugname);
			~ILockOn(void);


			virtual EntityContainer GetLockEntity1(EntityContainer*); //hyphotethical name,weird huh 
			virtual EntityContainer GetLockEntity2(); //no idea???
			virtual bool IsLockEntity(); //ithink
			virtual EntityContainer GetLockEntity3(); //no idea???
			virtual REF_TYPE(Sonicteam::Player::RootFrame) GetLockRootFrame();
			virtual void LockSetEntity(Sonicteam::SoX::Physics::Entity*);


			DESTRUCTION_H;




		};

	}
}



#endif

