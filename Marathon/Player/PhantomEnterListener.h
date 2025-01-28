#pragma once

#include <xtl.h>
#include <Sox/Physics/PhantomListener.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace Sonicteam{
	namespace Player{


		



		class PhantomEnterListener:Sonicteam::SoX::Physics::PhantomListener
			{
			public:
				//size0x60
				PhantomEnterListener(boost::function<int()>);
				~PhantomEnterListener(void);

				virtual void PhLsProcessMessage2(Sonicteam::SoX::Physics::PLMessage&);

				boost::function<int()> PELOnEnter;



		



		};
	}
}
