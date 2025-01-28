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


namespace Sonicteam{

	namespace Player{

		namespace State{

			namespace OtherFastContext{

				struct StateTableBase{
					unsigned int Flag1;
					unsigned int Flag2;
				};
				static  StateTableBase StateTable0x82009AB8[0x15];


			}

			class FastContext:public ICommonContext,IExportPostureRequestFlag
			{
			public:
				FastContext(void);
				~FastContext(void);
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
		

				///IDynamicLink(0x24)
				virtual void OnLink(Sonicteam::Player::IPlugIn*& plugin) override;

				//fields
				int ICommonContextIFUnkFlags0x94;
				int ICommonContextIFUnkFlags0x98; //0x98
				int ICommonContextIFUnkFlags0x9C; //0x9C
				unsigned int ExportPostureRequestFlag; //0xA0
				unsigned int unk0xA4;
				unsigned int ImportPostureFlag; //0xAC	
				unsigned long long UnknownFlags0xB0; //0xB0

				unsigned int unk0xB8;
				unsigned int unk0xBC;
				unsigned int unk0xC0;
				unsigned int unk0xC4;
				unsigned int unk0xC8;
				unsigned int unk0xCC;
				unsigned int unk0xD0;
		
				boost::shared_ptr<Sonicteam::Player::Score> ScorePlugin; //0xD4
				boost::shared_ptr<Sonicteam::Player::Input::IListener> ListenerNormalInputPlugin; //0xDC
				 
				
				float c_walk_border; // 0xE4 
				float c_run_acc; // 0xE8
				float c_walk_speed_max; // 0xEC
				float c_run_speed_max; // 0xF0
				float c_brake_acc; // 0xF4
				float c_brake_dashpanel; // 0xF8
				float c_jump_run; // 0xFC
				float c_brake_quick_acc; // 0x100
				float c_jump_speed; // 0x104
				float c_jump_walk; // 0x108
				float c_invincible_time; // 0x10C
				float c_jump_time_min; // 0x110
				float c_jump_brake; // 0x114
				float c_homing_time; // 0x118
				float c_homing_spd; // 0x11C
				float c_lightdash_speed; // 0x120





				//NON VIRTUAL METHODS

				void SetAnimation(int);

				virtual void DestroyObject(unsigned int flag) override;



		





			};

		}

	}
}

