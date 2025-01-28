#include "Machine2.h"

using namespace Sonicteam::Player::State;

Machine2::Machine2(void):IMachine()
{

}

Machine2::~Machine2(void)
{

}

void Machine2::OnMashineTick(float)
{

}


unsigned int Machine2::ChangeMashineState(int)
{
return 0;
}

unsigned int Machine2::AlternativeChangeMashineState(int)
{

	return 0;
}

void Machine2::ResetStateFlagsA()
{

}

void Machine2::ResetStateFlagsB()
{

}

unsigned int Machine2::CompleteChangeMashineState(int)
{

	return 0;
}

unsigned int Machine2::GetCurrentMashineStateID()
{
 return 0;
}

boost::shared_ptr<Sonicteam::Player::State::IContext> Machine2::GetMashineContext()
{

	
	return this->MashineContext;
	
}

void Sonicteam::Player::State::Machine2::DestroyObject(unsigned int flag)
{
	throw std::logic_error("The method or operation is not implemented.");
}
