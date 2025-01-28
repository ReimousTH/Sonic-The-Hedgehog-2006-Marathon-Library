#pragma once
#include "ICommonContext.h"
#include "..\IExportPostureRequestFlag.h"
#include "..\IExportWeaponRequestFlag.h"
#include "..\Score.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include "../Input/IListener.h"
#include <xtl.h>

//GroundAirFlags (Gordon Ramsay)
#define CC_GROUND 0x1 //detects Ground 
#define CC_WALLBRUSHING 0x8 // detects brushing against a wall
#define CC_HEADONWALL 0x10 //detects head-on wall collision (will always be enabled w/ 2^3)
#define CC_RAILGRIND 0x40 //Rail grinding
#define CC_BEFOREFALL 0x100 // seems like Neutral or Pre-Fall? The moment before transitioning from the Jump to Fall animation
#define CC_FALL 0x200 // is Falling
#define CC_WATERLCOL 0x800 //  Water collision (making you slide down an incline)? 2^8(CC_BEFOREFALL) is often set with this
#define CC_LIGHTDASHIN 0x4000 // Light Dashing (2 ^ 14)
#define CC_QUICKROTATE 0x8000 // is moving the control stick in a non-forward direction (usually only active for a frame since the character instantly rotates)
#define CC_TENTATIVE 0x10000 // is Tentative collision 
#define CC_WATERSLIDE 0x20000 // Water sliding (2^17)	
#define CC_GRASS 0x100000 // grass 2^20
#define CC_DIRTCLAY 0x200000 // dirt/clay (2^21)
#define CC_STONE 0x400000 // stone (2^22)
#define CC_SHORELINE 0x1000000 // shoreline? sand? Uncertain (2^24) 
//Comment
//^ A lot of these are often set with 2^22, with the lower bit determining SFX/particles. For instance, the grass in Forest is 2^20 + 2^22.
//Physics objects can get a bit weird (specifically the boxes) and are seemingly affected by what's below them.
//Like, a bomb box at the start of Sonic's KDV A has the flag 27262976 while a wooden box has the flag 26214400. The difference in is 2^20, the flag for grass, which is what the bomb box is on top of.
//Similarly, if you get on the Wood Box that's on top of the bomb box, it'll have the flag 26214656. But that will revert to the standard 26214400 if the Bomb Box goes away 




namespace Sonicteam{

	namespace Player{

		namespace State{

			namespace OtherCommonContext{

				struct StateTableBase{
					unsigned int Flag1;
					unsigned int Flag2;
				};
				static  StateTableBase StateTable0x82009AB8[0x15];


			}

			class CommonContext:public ICommonContext,IExportPostureRequestFlag,IExportWeaponRequestFlag
			{
			public:
				CommonContext(void);
				~CommonContext(void);
				virtual void OnVarible(LuaSystem**) override;
				virtual void ICCIF_03() override;
				virtual void ICCIF_04() override;
				virtual void ICCIF_05() override;


				////VFT_table
				virtual void ICOnPostInputTick(void)  override;
				virtual void ICOnInputTick(float) override;
				virtual void ICOnOnDamage(DWORD) override;
				

				///IExportPostureRequestFlag
				virtual DWORD IEPRFExportFlag(void);
				///IExportWeaponRequestFlag
				virtual DWORD IEWRFExportFlag(void);


				///IDynamicLink(0x24)
				virtual void OnLink(Sonicteam::Player::IPlugIn*& plugin) override;

				//fields
				int PComboAttackManager;
				int UnknownFlags01;
				unsigned int unkA0;
				unsigned int ContextFlags; //Export //0xA4
				unsigned int ExportPostureRequestFlag;  //0xA8
				unsigned int ExportWeaponRequestFlag; //0xAC
				float DamageInvincibleTime;
				float InvicibilityTimerWEffect;
				float SpeedUpTime;
				int UnkSomeTimer;
				float AngleMoveDataMB;
				unsigned int GroundAirFlags; //0xC4 (CC_??) FLAGS
				unsigned long long UnknownFlags0xC8;
				int UnknownFlags0xD0;
				int UnknownFlags0xD4;
				int UnknownUnUsedFlagD8;
				int FreeUnknownFlagsDC;
				char IsSonicDead; //0xE0 ( IsSonicDead)
				char IsGhostMode; //0xE1 
				char BlinkInvulMode; //0xE2
				char IsAnimationRotationLocked; //0xE3 (left,right,down)
				char HomingInvulnerable; // //0xE4
				char IsInvulnerable2; //0xE5
				char IsUnkE6; //??
				char IsGravityDisabled; //0xE7
				char IsUnkE8;
				char IsJumped_PostureVelocityYHandle; //0xE9
				char IsInActionsRunJumpBound_MB; //0xEA
				char IsUnkEB; //0xEB
				char IsUnkEC; //0xEC
				char IsUnkED; //0xED
				char IsUnkEE; //0xEE
				char JumpPush; //0xEF Dramatically reduces jump height when "pushing" against a surface. Used by the Push state

				/* UnkownFlagsUnk01 OLD
				char IsAttackSlideSpindashCollisionOn;
				char IsUnkF1_SetsToZeroUpdate;
				char IsUnkF2;
				char IsUnkF3;
				char IsCommonEdge;
				char IsUnkF5;
				char IsUnkF6;
				char IsUnkF7;
				*/

				char UnkF0; //0xF0
				char UnkF1; //0xF1
				char UnkF2; //0xF2
				char UnkF3; //0xF3
				char IsEdgeGrab; //0xF4 (Probably). When initially set, stores your coordinates then attempts to keep you locked there.
				char UnkF5; //0xF5
				char UnkF6; //0xF6
				char DisableGroundCollision; //0xF7  Detaches the player from the ground
				char DisableGroundCollision2; //0xF8  Same as above but only lasts for a moment

				char IsWaterSlider; //0xF9
				char IsForceTypeA_DashpanelsJumpRunHoming; //0xFA
				char IsUnkFB; //0xFB
				char ResetGravity; //0xFC Resets accumulated gravity to 0
				char DisableGravity; //0xFD Resets accumulated gravity to 0, turns off gravity accumulation, resets base Y Speed to 0 on A Release
				char IsUnkFE; //0xFE
				char IsUnkFF; //0xFF
				char IsSendCharacterToPositionVectorZero; //0x100
				char IsUnk101;
				char IsInvulnerableItemBox; //0x102 Probably triggered by an itembox
				char IsUnk103; //0x103
				char IsBarrier; //0x104
				char IsUnk105_AlwaysSetsZero; //0x105
				char IsGrabbed; //0x106 ? Maybe? Can be triggered by a glitch in multiplayer
				char IsUnk107;
				char IsGrabbedAura ; //0x108 Activates ESP shader
				char LockRotationHold; //0x109   (probably for a Hold. This is different from 0xE3)
				char IsAntiGravity; //0x10A (collider)
				char IsChrCamDisabled; //0x10B
				char IsUnk10C; //0x10C
				char IsKillChrIfZeroRings; //0x10D
				char IsUnk10E;
				char IsUnk10F;
				char IsUnk110;
				char UnknownFlags0x111[0x15]; //chr-upgrades (get only)
				char IsUnk126;
				char IsUnk127;
				boost::shared_ptr<Sonicteam::Player::Score> ScorePlugin; //0x128
				boost::shared_ptr<int> GravityPlugin;  //0x130
				boost::shared_ptr<Sonicteam::Player::Input::IListener> ListenerNormalInputPlugin; //0x138
				boost::shared_ptr<int> PlayerAIAmigoPlugin; //0x140
				float float148;
				float gravity;
				float c_brake_acc;
				float c_brake_dashpanel;
				float c_walk_border;
				float c_run_border;
				float c_walk_speed_max;
				float c_run_acc;
				float c_run_speed_max;
				float c_speedup_acc;
				float c_speedup_speed_max;
				float c_jump_time_min;
				float c_jump_brake;
				float c_jump_speed_acc;
				float c_jump_speed_brake;
				float c_jump_speed;
				float c_jump_walk;
				float c_jump_run;
				float c_brake_quick_acc;
				float c_wait_no_input_time;
				float c_damage_time;
				float c_damage_jump;
				float c_damage_speed;
				float c_run_against_time;
				float c_grind_speed_org;
				float c_grind_acc;
				float c_grind_speed_max;
				float c_grind_time;
				float c_grind_penalty_time;
				float c_grind_brake_acc;
				float c_invincible_time;
				float c_invincible_time_ring1;
				float c_invincible_item;
				float c_speedup_time;
				float c_wind_init;
				float c_wind_spd;
				float c_wind_dist;
				float c_border_gravity;
				float c_landing_time;
				float c_ottoto_time;
				float c_dead_animation_time;
				float c_dead_animation_time_coll;
				float c_wallwait_time;
				float c_lclick_time;
				float c_flight_acc;
				float c_flight_speed_acc;
				float c_flight_speed_min;
				float c_flight_speed_max;
				float c_hovering_acc;
				float c_climb_speed;
				float c_stun;
				float c_brake_acc_sand;
				float c_run_acc_sand;
				float c_jump_speed_sand;
				float c_psi_throw_speed;
				float float224;
				float float228;
				float float22C;



				//NON VIRTUAL METHODS

				void SetAnimation(int);

				virtual void DestroyObject(unsigned int flag) override;



		





			};

		}

	}
}

