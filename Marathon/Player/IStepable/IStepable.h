#pragma once

#include "../../../TypeBasics.h"



namespace Sonicteam{
	namespace Player{

		class IStepable
		{
		public:
			IStepable(void);
			virtual ~IStepable(void);
			virtual void OnStepable(float) = 0;

		};

	}
}


MFTCype(IStepable,Sonicteam::Player::IStepable);