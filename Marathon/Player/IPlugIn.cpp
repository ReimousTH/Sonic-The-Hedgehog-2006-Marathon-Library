#include "IPlugIn.h"

using namespace Sonicteam::Player;

IPlugIn::IPlugIn(char* plug_name)
{
	this->PluginName.assign(plug_name);
}

IPlugIn::~IPlugIn(void)
{
	this->PluginName.clear();
}

void Sonicteam::Player::IPlugIn::DestroyObject(unsigned int flag)
{
	IPlugIn::~IPlugIn();	
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
	