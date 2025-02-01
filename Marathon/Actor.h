
#ifndef SONICTEAM__ACTOR
#define SONICTEAM__ACTOR


#include "Defs.h"


#include "ActorManager.h"
#include <Sox/Memory/IDestructible.h>
#include <Sox/Engine/Task.h>
#include <boost/weak_ptr.hpp>
#include <GameImp.h>





namespace Sonicteam{

	

	//not complete :(



	class Actor:public Sonicteam::SoX::Engine::Task
		{
		public:
			~Actor();
			 Actor(Sonicteam::Actor* other, boost::weak_ptr<unsigned int>& gameimp);

			boost::weak_ptr<Sonicteam::GameImp> GameImp; //0x4C-0x50
			unsigned int ActorID; //0x54

		
			virtual void DestroyObject(unsigned int flag);



		

	};
};

#endif