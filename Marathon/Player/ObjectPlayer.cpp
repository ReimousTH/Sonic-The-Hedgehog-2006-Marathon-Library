#include "ObjectPlayer.h"

using namespace Sonicteam::Player;


int Sonicteam::Player::ObjectPlayer::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	return 0;
}



char* Sonicteam::Player::ObjectPlayer::GetObjectType()
{
	return "ObjectPlayer";
}

void Sonicteam::Player::ObjectPlayer::OnTaskUpdate(float)
{
	
}
