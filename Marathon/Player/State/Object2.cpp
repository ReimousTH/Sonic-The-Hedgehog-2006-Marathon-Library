#include "Object2.h"

using namespace Sonicteam::Player::State;

unsigned int* Object2::StateConstant()
{
	return 0;
}

void Object2::OnStateStart(Sonicteam::Player::State::IContext* context)
{
	this->Object2Start();
}

void Object2::OnStateUpdate(float delta)
{

	this->Object2PreUpdateCmn(delta);
	this->OnStateUpdate(delta);
	this->Object2PostUpdateCmn(delta);
}

void Object2::OnStateEnd()
{
	this->Object2End();
}

unsigned int Object2::StateUnknown()
{

	return 0;
}

Object2::Object2(IMachine* a1)
{
	this->ObjectMashine = a1;
}

Object2::~Object2(void)
{

}

DESTRUCTION_CPP(Object2);


