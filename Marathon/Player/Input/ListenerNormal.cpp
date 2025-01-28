#include "ListenerNormal.h"

using namespace Sonicteam::Player;



Input::ListenerNormal::ListenerNormal(unsigned int a1, unsigned int a2):Sonicteam::Player::IPlugIn("input"),Sonicteam::Player::IVariable(),Sonicteam::Player::IStepable()
{

	this->ptr0x40= a1;
	this->ptr0x44= a2;

	this->StickPower = StickPower;

	this->unk0x48 = 0;
	this->StickVector = 0;

	this->unkfloat0x74 = 0;

	this->ILISunk0x78 = IListenerInputStruc02(1,0.0);
	this->ILISunk0x88 = IListenerInputStruc03(1);
	this->unk0x9c = 1;
	this->unk0xA0 = 8;
	this->unk0xA4 = 0x10;
	this->unk0xA8 = 0x8000;
	this->ILISunk0xAC = IListenerInputStruc02(0x8000,0.0);
	this->c_input_border = 0.1;




	//float v10[2] = {0,0};

	//also std list need
}

	

Input::ListenerNormal::~ListenerNormal(void)
{

}

void Input::ListenerNormal::ListenerOnUpdate(int,float)
{
	
}

XMFLOAT4* Input::ListenerNormal::ListenerGetStickVector4()
{
return 0;	
}

float Input::ListenerNormal::ListenerGetStickPower()
{
	return 0;
}

unsigned int Input::ListenerNormal::ListenerGetResult()
{
	return 0;
}

int Input::ListenerNormal::Listener5()
{
	return 0;
}

void Input::ListenerNormal::OnVarible(Sonicteam::LuaSystem** l)
{

	Sonicteam::LuaSystem* x = *l;
	float c_dclick_time =     x->GetFloatValue( &std::string("c_dclick_time"));
	float c_lclick_time =     x->GetFloatValue( &std::string("c_lclick_time"));
	float c_input_border =     x->GetFloatValue( &std::string("c_input_border"));

	this->ILISunk0x78.c_dclick_time = c_dclick_time;
	this->ILISunk0x88.c_lclick_time = c_lclick_time;
	this->ILISunk0xAC.c_dclick_time = c_dclick_time;

	this->c_input_border = c_input_border;


	//
}

void Input::ListenerNormal::OnStepable(float)
{
	
}
