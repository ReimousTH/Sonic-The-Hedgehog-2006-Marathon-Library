#ifndef SONICTEAM__APPMARATHON
#define SONICTEAM__APPMARATHON
#include "Defs.h"
#include <Sox/Engine/Application.h>



namespace Sonicteam{


	class AppMarathon:Sonicteam::SoX::Engine::Application
	{

		AppMarathon();
		~AppMarathon();


		DocMarathonImp* DocMarathon;



		DESTRUCTION_H;

	};
};

#endif