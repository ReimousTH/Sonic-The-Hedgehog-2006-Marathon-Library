
#ifndef __MARATHON_ACTORMANAGER__
#define __MARATHON_ACTORMANAGER__

#include "Actor.h"


#include <vector>
#include <xmath.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Engine/Task.h>

namespace Sonicteam{

	

	//not complete :(

	class ActorManager
		{
		public:
			~ActorManager();
			ActorManager();

			unsigned int ActorID[0xFFFF];
			Sonicteam::SoX::Engine::Task* Actor[0xFFFF]; //Actor class
			unsigned int LastActorID; // guess, correct 
			unsigned int LastActorIndex; // Count-1, 39 is actually, but 38 here	

		
			virtual void DestroyObject(unsigned int flag);

			//other
			static const unsigned int MaxID = 0xFFFFFFFF;
			Sonicteam::SoX::Engine::Task* SearchActorByID(unsigned int& ID);

		

	};
};
#endif