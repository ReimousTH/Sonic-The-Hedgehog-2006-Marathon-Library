#pragma once

#include <Player/IPlugIn.h>
#include <string>
#include <LuaSystem.h>

namespace Sonicteam{
	namespace Player{
		namespace Effect{
		

		class ParticleScript
		{
		public:

			const static char* ParticleScriptExt;
			ParticleScript(std::string& value);
			~ParticleScript(void);



			//Fields


			virtual void DestroyObject(unsigned int flag);
			Sonicteam::LuaSystem* LSScript;






		

		};
		};
	}
}

