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
			class SonicContext:public CommonContext
			{
			public:

				DWORD CurrentGemImage;
				boost::shared_ptr<Sonicteam::Player::SonicGauge> GaugePlugin;
				char HomingLockOn; //byte23C
				char DisablePlayerMovement; // 0x23D They can still accrue speed/gravity and try to make inputs, but they'll be locked in place. Also stops rotation
				char AntigravityHitbox; //0x23E
				char byte23F;
				char BoundAttackHitbox;
				char byte241;
				char isShrink; //0x242 Activates Purple Gem properties (faster speed, ability to double jump, etc.) but does not activate visual shrink
				char isThunderGuard; //0x243 Only togglable when the player has a barrier. Activates the outer yellow aura and ring-magnet effect.
				char IsTornadoEnabled; //0x244 Activates the Green Gem tornado when called but keeps the hitbox active on Sonic as long as the byte is enabled
				char IsBombSearch; //0x245 Tog	gles the first-person camera mode, camera can only be adjusted with the left stick
				char ThrowGem; //0x246 Launches the sky gem
				char isSlowTime; //0x247
				char MachAura; //0x248 Enables the Blue Gem particles
				char GemsEnabled; //0x249
				char field_24A;
				char field_24B;
				DWORD IsHomingFlip; //0x24C 0x24C/D/E/F  //Seems to make Sonic go into homing_after1 on his next HA recovery period
				int CurrentGem;
				float c_homing_spd;
				float c_homing_brake;
				float c_sliding_time;
				float c_spindash_spd;
				float c_spindash_time;
				float c_bound_jump_spd_0;
				float c_bound_jump_spd_1;
				float c_lightdash_speed;
				float c_boundjump_jmp;
				float c_boundjump_block;
				float c_attack_brake;
				float c_sliding_speed_min;
				float c_sliding_speed_max;
				float c_homing_smash_charge;
				float c_custom_action_slow_time;
				float c_custom_action_machspeed_acc;
				float c_custom_action_machspeed_time;
				float c_scale_run_speed_max;
				float c_scale_run_acc;
				float c_scale_walk_speed_max;
				float c_scale_jump_speed;
				float c_scale_jump_block;

				virtual void DestroyObject(unsigned int flag) override;




			};

		}

	}
}

