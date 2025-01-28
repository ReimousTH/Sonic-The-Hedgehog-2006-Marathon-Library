#include "ParticleScript.h"
using namespace Sonicteam::Player::Effect;


const char* Sonicteam::Player::Effect::ParticleScript::ParticleScriptExt = ".particle.lua";


Sonicteam::Player::Effect::ParticleScript::ParticleScript(std::string& value)
{
	std::string player = std::string("player/");
	player.append(value);
	player.append(Sonicteam::Player::Effect::ParticleScript::ParticleScriptExt);
	LuaSystem::LoadInitResource(this->LSScript,player);

}

Sonicteam::Player::Effect::ParticleScript::~ParticleScript(void)
{

}

void Sonicteam::Player::Effect::ParticleScript::DestroyObject(unsigned int flag)
{

}

