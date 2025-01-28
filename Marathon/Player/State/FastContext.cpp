#include "FastContext.h"

using namespace Sonicteam::Player::State;

FastContext::FastContext(void):ICommonContext()
{
}

FastContext::~FastContext(void)
{
}



void FastContext::OnVarible(Sonicteam::LuaSystem** t)
{

	Sonicteam::LuaSystem* x = *t;

	c_walk_border = x->GetFloatValue( &std::string("c_walk_border"));  
	c_run_acc = x->GetFloatValue( &std::string("c_run_acc"));  
	c_walk_speed_max = x->GetFloatValue( &std::string("c_walk_speed_max"));  
	c_run_speed_max = x->GetFloatValue( &std::string("c_run_speed_max"));  
	c_brake_acc = x->GetFloatValue( &std::string("c_brake_acc"));  
	c_brake_dashpanel = x->GetFloatValue( &std::string("c_brake_dashpanel"));  
	c_jump_run = x->GetFloatValue( &std::string("c_jump_run"));  
	c_brake_quick_acc = x->GetFloatValue( &std::string("c_brake_quick_acc"));  
	c_jump_speed = x->GetFloatValue( &std::string("c_jump_speed"));  
	c_jump_walk = x->GetFloatValue( &std::string("c_jump_walk"));  
	c_invincible_time = x->GetFloatValue( &std::string("c_invincible_time"));  
	c_jump_time_min = x->GetFloatValue( &std::string("c_jump_time_min"));  
	c_jump_brake = x->GetFloatValue( &std::string("c_jump_brake"));  
	c_homing_time = x->GetFloatValue( &std::string("c_homing_time"));  
	c_homing_spd = x->GetFloatValue( &std::string("c_homing_spd"));  
	c_lightdash_speed = x->GetFloatValue( &std::string("c_lightdash_speed"));  

	
	

}

void FastContext::ICCIF_03()
{

}

void FastContext::ICCIF_04()
{

}

void FastContext::ICCIF_05()
{

}

//CharacterControls
void FastContext::ICOnPostInputTick(void)
{

}

//Character Core
void FastContext::ICOnInputTick(float delta)
{

	ICommonContext::ICOnInputTick(delta);
	







}
//Character OnDamage

void FastContext::ICOnOnDamage(DWORD)
{

}




DWORD FastContext::IEPRFExportFlag(void)
{

	return this->ExportPostureRequestFlag;

}


void FastContext::OnLink(Sonicteam::Player::IPlugIn*& plugin)
{

}

void Sonicteam::Player::State::FastContext::SetAnimation(int num)
{
	this->CurrentAnimation = num;
	this->AnimationState = -2;
}

void Sonicteam::Player::State::FastContext::DestroyObject(unsigned int flag)
{
	FastContext::~FastContext();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

