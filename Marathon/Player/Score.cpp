#include "Score.h"

using namespace Sonicteam::Player;




Score::~Score(void)
{

}

//GameModules (GameImpulse,PackageBinary)
Score::Score(int* PtrObjectPlayer,int* RootFrame,int DefaultValue,int* GameModules)
{

}

void Score::AddRings(int value)
{
	this->RingsCount+=value;
}

void Score::TakeDamage(void)
{
	
}

void Score::TakeDamageOld()
{
	
}

void Score::TakeDamageLittle()
{
	
}

int Score::GetRings()
{
	return this->RingsCount;
}

void Score::SetRings(int value)
{
	this->RingsCount = value;
}

void Score::SetUnknownVector(XMFLOAT4* value)
{
	this->unkvector = *value;
}

void Score::OnVarible(void)
{
	
}

void Score::OnStepable(float)
{
	
}

