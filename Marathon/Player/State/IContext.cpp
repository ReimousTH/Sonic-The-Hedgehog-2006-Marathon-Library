#include "IContext.h"

using namespace Sonicteam::Player::State;
IContext::IContext(char* context_name):IPlugIn(context_name),IVariable(),IDynamicLink(),IFlagCommunicator()
{
}

IContext::~IContext(void){
	
}

DESTRUCTION_CPP(IContext);