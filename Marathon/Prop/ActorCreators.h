#ifndef Sonicteam_Prop_ActorCreators
#define Sonicteam_Prop_ActorCreators


#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include "PropClass.h"
#include "ActorCreator.h"
#include <map>



namespace Sonicteam { namespace Prop {






	class ActorCreators{

	public:
		ActorCreators();
		~ActorCreators();

		Sonicteam::Actor* NamedActor; //0
		boost::weak_ptr<Sonicteam::GameImp> GameImp; //0x4-0x8
		std::map<std::string,boost::shared_ptr<Sonicteam::Prop::IActorCreator>> ActorCreator; //Sonicteam::Prop::IActorCreator ,0xC
	

	};


}};

#endif

