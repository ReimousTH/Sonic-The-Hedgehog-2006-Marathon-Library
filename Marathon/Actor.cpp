#include "Actor.h"


using namespace Sonicteam;



Sonicteam::Actor::~Actor()
{

}



Sonicteam::Actor::Actor(Sonicteam::Actor* other, boost::weak_ptr<unsigned int>& gameimp):Sonicteam::SoX::Engine::Task(other)
{

}

Actor::Actor()
{

}

DESTRUCTION_CPP(Actor)
