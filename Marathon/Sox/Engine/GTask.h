#pragma once

#include "../MessageReceiver.h"
#include "../Component.h"

namespace Sonicteam{
	namespace SoX{
		namespace Engine{
			class GTask:Sonicteam::SoX::Component
		{
		public:
			GTask(Sonicteam::SoX::Component*); //no idea THRERE TWO OF THEM
			virtual char* GetObjectType();
			 ~GTask(void);

			//Fields
			unsigned int Tuint0x24; // Self????????
			unsigned int Tuint0x28;
			unsigned int Tuint0x2C;
			unsigned int Tuint0x30;


		};
	};
}
}
