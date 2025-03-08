#include "Homing.h"

using namespace Sonicteam::Player;


DESTRUCTION_CPP(Homing);

void Sonicteam::Player::Homing::SetFlag01(DWORD flag_value)
{
	
	if ( (flag_value & 0x10000000) != 0 )
	{
		if (!this->HomingStatePre) return;

		if (this->Homing0x54){

		}

		if (this->LockOnEntityP.Entity !=0){
			this->HomingStateAfter = 4;
			return;
		}

	}

}

void Sonicteam::Player::Homing::OnStepable(float)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Homing::OnStepablePost(float)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Homing::OnVarible(LuaSystem**)
{
	throw std::logic_error("The method or operation is not implemented.");
}
