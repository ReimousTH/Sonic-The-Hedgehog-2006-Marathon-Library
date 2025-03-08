#include "PhantomEnterListener.h"


using namespace Sonicteam::Player;;

Sonicteam::Player::PhantomEnterListener::PhantomEnterListener(boost::function<int()> fnc):PELOnEnter(fnc) //NOICE 
{

}



void Sonicteam::Player::PhantomEnterListener::PhantomListenerOnUpdate(PhantomListenerEntityContainerType)
{
	this->PELOnEnter();
}

Sonicteam::Player::PhantomEnterListener::~PhantomEnterListener(void)
{

}
