
#ifndef __MARATHON_ACTORMANAGER__
#define __MARATHON_ACTORMANAGER__

#include "Defs.h"
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
			Sonicteam::Actor* Actor[0xFFFF]; //Actor class
			unsigned int LastActorID; //        guess, correct 
			unsigned int LastActorIndex; //       Count-1, 39 is actually, but 38 here	

		
			DESTRUCTION_H;

			//other
			static const unsigned int MaxID = 0xFFFFFFFF;
			Sonicteam::Actor* SearchActorByID(unsigned int& ID);

		

	};
};
#endif