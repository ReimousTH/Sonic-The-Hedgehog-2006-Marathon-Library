#ifndef SONICTEAM__NAMEDACTOR
#define SONICTEAM__NAMEDACTOR


#include <Defs.h>
#include <Actor.h>
#include <boost/shared_ptr.hpp>



namespace Sonicteam{




	class NamedActor:public Sonicteam::Actor{

	public:
		//Sonicteam::Game(base class missing)
		NamedActor(Sonicteam::Actor*,boost::shared_ptr<Sonicteam::GameImp>,const char*); 
		~NamedActor();


		std::string ActorName;

		


		DESTRUCTION_H;



		virtual void OnTaskUpdate(float);

		void UpdateKhronoTime(double);

	};

};




#endif