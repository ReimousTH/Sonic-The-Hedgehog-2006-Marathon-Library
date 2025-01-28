#include "SonicContext.h"

using namespace Sonicteam::Player::State;

void Sonicteam::Player::State::SonicContext::DestroyObject(unsigned int flag)
{
	this->~SonicContext();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
