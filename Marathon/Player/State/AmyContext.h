#pragma once
#include "CommonContext.h"
#include "..\Gauge\SonicGauge.h"
#include "..\IExportPostureRequestFlag.h"
#include "..\IExportWeaponRequestFlag.h"
#include "..\Score.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <xtl.h>

namespace Sonicteam{

	namespace Player{

		namespace State{

		

			//only fields for now, i finish when i comlete CommmonContext FUll  methods
			class AmyContext:public CommonContext
			{
			public:
				
				//00000000 00000000 00000000 00000000
				//00000001 -- Hammer Flag
				unsigned int AmyUnkFlags;
				int AvailableJumpNum;
				float StealthTime;
				unsigned int unk0x23C;
				int c_jump_double_count;
				float c_stealth_pray;
				float c_stealth_limit;
				float c_stealth_countdown;
				float c_jump_double_speed;
				unsigned int unk0x254;
				unsigned int unk0x258;
				unsigned int unk0x25C;



			};

		}

	}
}

