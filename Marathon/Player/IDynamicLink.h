#pragma once
#include <Player/IPlugIn.h>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#define DynContainer(T) boost::weak_ptr<Sonicteam::Player::IPlugIn>  //Yes weak



namespace Sonicteam{
	namespace Player{
		class IDynamicLink
		{
		public:
			IDynamicLink(void);
			~IDynamicLink(void);

			virtual void DestroyObject(unsigned int flag);
			virtual void OnLink(DynContainer(Sonicteam::Player::IPlugIn) plugin);
		};
	}
}

