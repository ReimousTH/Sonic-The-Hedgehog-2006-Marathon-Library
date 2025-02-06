#ifndef SONICTEAM__COMBO__SCOREMANAGER
#define SONICTEAM__COMBO__SCOREMANAGER

#include "Defs.h"
#include <Sox/RefCountObject.h>
#include <GameImp.h>


#include <cstdlib>
#include <iostream>
#include <boost/weak_ptr.hpp>


namespace Sonicteam{
	namespace Combo{

	
		class ScoreManager:public Sonicteam::SoX::RefCountObject
		{
		public:
			ScoreManager(void);
			ScoreManager(boost::weak_ptr<Sonicteam::GameImp> GameImp,unsigned ActorID);
			~ScoreManager(void);
			boost::weak_ptr<Sonicteam::GameImp> GameImp;
			unsigned int PlayerActorID;
			float unk0x14; //0x14;
			float unk0x18; //0x18;
			float unk0x1C; //0x1C;
			float unk0x20; //0x20;


			DESTRUCTION_H;

		};



	}
}

#endif