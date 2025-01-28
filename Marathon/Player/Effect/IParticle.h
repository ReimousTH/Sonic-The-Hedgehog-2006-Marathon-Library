#pragma once

#include <Player/Effect/ParticleScript.h>
#include <xtl.h> //replace to only XMFLOAT4
#include <string>

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace Sonicteam{
	namespace Player{
		namespace Effect{
		typedef class IParticle;
		
		//Complete Size : 0x2C;
		class IParticle
		{
		public:

			

			IParticle(IParticle&);
			IParticle(Sonicteam::Player::IPlugIn* PlayerLoad,std::string& path);
			~IParticle();



			//Fields


			virtual void DestroyObject(unsigned int flag);

			Sonicteam::Player::IPlugIn* PlayerLoad; //Load_Player_Sonicteam 82007C24 (Or IPlugin)
			std::string BufferParticleName;

			boost::shared_ptr<Sonicteam::Player::Effect::ParticleScript> EffectPlayerParticleScript;






		

		};
		};
	}
}

