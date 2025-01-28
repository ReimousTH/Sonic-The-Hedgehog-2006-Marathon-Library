#include "ILoad.h"

using namespace Sonicteam::Player;


void Sonicteam::Player::ILoad::DestroyObject(unsigned int flag)
{
	Sonicteam::Player::ILoad::~ILoad();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

Sonicteam::Player::ILoad::ILoad(void):IPlugIn("load")
{

}

Sonicteam::Player::ILoad::~ILoad(void)
{

}

