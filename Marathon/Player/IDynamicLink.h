#pragma once
#include <Player/IPlugIn.h>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/scoped_ptr.hpp>

#define DynContainer(T) boost::shared_ptr<Sonicteam::Player::IPlugIn>&  //Yes weak



namespace Sonicteam{
	namespace Player{
		class IDynamicLink
		{
		public:
			IDynamicLink(void);
			~IDynamicLink(void);

			DESTRUCTION_H;
			virtual void OnLink(DynContainer(Sonicteam::Player::IPlugIn) plugin);
		};
	}
}

