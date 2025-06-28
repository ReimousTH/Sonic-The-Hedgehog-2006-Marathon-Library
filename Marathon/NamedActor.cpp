#include "NamedActor.h"



using namespace Sonicteam;




NamedActor::NamedActor(Sonicteam::Actor* task,boost::shared_ptr<Sonicteam::GameImp> game,const char* name):Actor(task,game)
{

	this->ActorName = name;
}

NamedActor::~NamedActor()
{

}

DESTRUCTION_CPP(NamedActor);