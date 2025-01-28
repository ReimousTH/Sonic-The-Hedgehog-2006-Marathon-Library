#include "IParticle.h"
using namespace Sonicteam::Player::Effect;

Sonicteam::Player::Effect::IParticle::IParticle(IParticle& value)
{
	this->PlayerLoad = value.PlayerLoad;
	this->BufferParticleName.assign(this->BufferParticleName);
	this->EffectPlayerParticleScript = value.EffectPlayerParticleScript;
}

Sonicteam::Player::Effect::IParticle::IParticle(Sonicteam::Player::IPlugIn* PlayerLoad,std::string& path)
{
	this->PlayerLoad = PlayerLoad;
	this->BufferParticleName.assign(path);
	boost::shared_ptr<Sonicteam::Player::Effect::ParticleScript> x(new Sonicteam::Player::Effect::ParticleScript(path));
	this->EffectPlayerParticleScript = 	x;
}

Sonicteam::Player::Effect::IParticle::~IParticle(void)
{

}

void Sonicteam::Player::Effect::IParticle::DestroyObject(unsigned int flag)
{

}
