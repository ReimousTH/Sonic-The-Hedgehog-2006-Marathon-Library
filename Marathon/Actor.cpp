#include "Actor.h"


using namespace Sonicteam;



Sonicteam::Actor::~Actor()
{

}



void Sonicteam::Actor::DestroyObject(unsigned int flag)
{
	Sonicteam::Actor::~Actor();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

Sonicteam::Actor::Actor(Sonicteam::Actor* other, boost::weak_ptr<unsigned int>& gameimp):Sonicteam::SoX::Engine::Task(other)
{

}


