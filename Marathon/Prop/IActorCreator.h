

#ifndef Sonicteam_Prop_IActorCreator
#define Sonicteam_Prop_IActorCreator

#include "PropClass.h"
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <Defs.h>



namespace Sonicteam { namespace Prop {




	class IActorCreator{

	public:
		IActorCreator();
		~IActorCreator();

		DESTRUCTION_H;
		virtual Sonicteam::Actor* CreateActor(Sonicteam::Actor* NamedActor,boost::weak_ptr<Sonicteam::GameImp>* GameImp,void* ObjectCreationData) = 0;

	};


}};

#endif

