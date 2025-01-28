#pragma once
#include <Player/IPlugIn.h>



namespace Sonicteam{
	namespace Player{
		class IDynamicLink
		{
		public:
			IDynamicLink(void);
			virtual ~IDynamicLink(void);
			virtual void OnLink(Sonicteam::Player::IPlugIn*& plugin);
		};
	}
}

