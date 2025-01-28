#include "INotification.h"




using namespace Sonicteam::Player;

INotification::INotification(void)
{

}

INotification::~INotification(void)
{

}

void Sonicteam::Player::INotification::DestroyObject()
{
	Sonicteam::Player::INotification::~INotification();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,1);

}
