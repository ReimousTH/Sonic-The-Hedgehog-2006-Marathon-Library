#pragma once
#ifndef SONICTEAM__PLAYER__IIMPORTANIMATION

#include "Defs.h"

namespace Sonicteam{
	namespace Player{


		class IImportAnimation
		{
		public:
			virtual void ImportAnimation(unsigned int Animation) = 0;
		};

	}
}

#define SONICTEAM__PLAYER__IIMPORTANIMATION
#endif





