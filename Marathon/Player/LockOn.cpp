#include "LockOn.h"

using namespace Sonicteam::Player;

Sonicteam::Player::LockOn::LockOn(Sonicteam::SoX::MessageReceiver* Receiver,const char* plugname,REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok,REF_TYPE(Sonicteam::Player::RootFrame) RootFrame):Sonicteam::Player::ILockOn(plugname)
{

}

Sonicteam::Player::LockOn::~LockOn(void)
{

}

void Sonicteam::Player::LockOn::OnStepable(float)
{
	throw std::logic_error("The method or operation is not implemented.");
}


DESTRUCTION_CPP(LockOn);
