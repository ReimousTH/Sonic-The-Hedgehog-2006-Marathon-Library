#include "GaugeStandard.h"


using namespace Sonicteam::Player;

GaugeStandard::GaugeStandard(void):IGauge((char*)"gauge")
{
	this->GaugeValue = 0;
	this->c_s_max = 0;
	this->GaugeFlags = 0;

}

GaugeStandard::~GaugeStandard(void) 
{

}

//
void GaugeStandard::OnVarible(Sonicteam::LuaSystem** l)
{

	Sonicteam::LuaSystem* x = *l;
	char buffer[0x60];
	sprintf_s(buffer,"c_%s_max",this->PluginName.c_str());
	this->c_s_max =     x->GetFloatValue( &std::string(buffer));

	

}
void GaugeStandard::OnStepable(float delta)
{
	
}

float GaugeStandard::GetGaugeValue()
{
	return this->GaugeValue;

}
unsigned int GaugeStandard::GetGaugeLevel()
{
	return 0; // By Default
}

float GaugeStandard::GetGaugeMaturity()
{
	return 0.0;
}
float GaugeStandard::GetGaugePoint()
{

	return this->GaugeValue /this->c_s_max;
}
void GaugeStandard::AddGaugeValue(float value) //Same by C++ but different in asm (
{
	ShowXenonMessage(L"MSG","my");
	if (this->c_s_max >=  value + this->GaugeValue )
		this->GaugeValue+=value;
	else
		this->GaugeValue = this->c_s_max;

}
void GaugeStandard::AddMaturityValue()
{
	this->AddGaugeValue(1.0);
}
