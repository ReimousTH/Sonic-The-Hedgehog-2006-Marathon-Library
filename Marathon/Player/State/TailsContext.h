#pragma once
#include "CommonContext.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <xtl.h>

namespace Sonicteam{

	namespace Player{

		namespace State{

		

			class TailsContext:public CommonContext
			{
			public:

				float TCuint0x230;
				float BombCooldown; //0x234
				char ThrowGroundBomb;  // //0x238 (instantly throws a dummy ring bomb when set to 1, automatically turns itself off. Uses the trajectory of a ground throw)
				char IsBombSearch; //(toggles FPS mode) ;//0x239
				char unk0x23E; // 0x23A
				char ThrowAirBomb; //(same as GroundBomb but with aerial trajectory. Will spawn below the ground if you're grounded) 0x23B

				float c_flight_timer; //0x23C
				float c_flight_timer_b; //0x240
				float c_flight_acc; //0x244
				float c_ignore_spread_time; //0x248
	
			};

		}

	}
}

