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

DESTRUCTION_CPP(IPlugIn);

