#include "LocalAnimationUserDataListener.h"

using namespace Sonicteam::Player;


void Sonicteam::Player::PackageModel::LocalAnimationUserDataListener::DestroyObject(unsigned int flag)
{
	Sonicteam::Player::PackageModel::LocalAnimationUserDataListener::~LocalAnimationUserDataListener();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

void Sonicteam::Player::PackageModel::LocalAnimationUserDataListener::ProcessFunc(Sonicteam::SoX::Physics::Entity*& phantom)
{
	this->ListenerFunc(phantom);
}

Sonicteam::Player::PackageModel::LocalAnimationUserDataListener::LocalAnimationUserDataListener(boost::function<void*(Sonicteam::SoX::Physics::Entity*&)> fnc)
{
	this->ListenerFunc = fnc;
}

Sonicteam::Player::PackageModel::LocalAnimationUserDataListener::~LocalAnimationUserDataListener(void)
{

}
