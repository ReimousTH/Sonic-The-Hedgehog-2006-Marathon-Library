

#ifndef Sonicteam_Prop_IActorCreator
#define Sonicteam_Prop_IActorCreator

#include "PropClass.h"
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <Actor.h> // Sonicteam::NamedActor



namespace Sonicteam { namespace Prop {




	class IActorCreator{

	public:
		IActorCreator();
		~IActorCreator();

		virtual void DestroyObject(unsigned int flag) = 0;
		virtual Sonicteam::Actor* CreateActor(Sonicteam::Actor* NamedActor,boost::weak_ptr<Sonicteam::GameImp>* GameImp,void* ObjectCreationData) = 0;

	};


}};

#endif

