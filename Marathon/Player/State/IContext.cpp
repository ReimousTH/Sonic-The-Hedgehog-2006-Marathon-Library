#include "IContext.h"

using namespace Sonicteam::Player::State;
IContext::IContext(char* context_name):IPlugIn(context_name),IVariable(),IDynamicLink(),IFlagCommunicator()
{
}

IContext::~IContext(void){
	
}

void Sonicteam::Player::State::IContext::DestroyObject(unsigned int flag)
{
	IContext::~IContext();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

