#include "IModel.h"

using namespace Sonicteam::Player;

Sonicteam::Player::IModel::IModel(char* plugname):IPlugIn(plugname)
{

}

unsigned int Sonicteam::Player::IModel::GetAnimationID1()
{
	return 0;
}

unsigned int Sonicteam::Player::IModel::GetAnimationID2()
{
	return 0;
}

unsigned int Sonicteam::Player::IModel::GetAnimationData()
{
	return 0;

}
