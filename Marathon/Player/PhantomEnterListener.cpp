#include "PhantomEnterListener.h"


using namespace Sonicteam::Player;;

Sonicteam::Player::PhantomEnterListener::PhantomEnterListener(boost::function<int()> fnc):PELOnEnter(fnc) //NOICE 
{

}



void Sonicteam::Player::PhantomEnterListener::PhLsProcessMessage2(Sonicteam::SoX::Physics::PLMessage&)
{
	this->PELOnEnter();
}

Sonicteam::Player::PhantomEnterListener::~PhantomEnterListener(void)
{

}
