#pragma once

#include "IGauge.h"

namespace Sonicteam{
	namespace Player{


		
	
		class SonicGauge:IGauge
			{
			public:

				//testing

			//	std::type_info const &type() const { return typeid(*this); }

				//

				SonicGauge(void);
				~SonicGauge(void);



				///ISteapable,IVarible VFT
				virtual void OnVarible(LuaSystem**) override;
				virtual void OnStepable(float) override;


				///IGaugeVFT

				virtual float GetGaugeValue()  override;
				virtual unsigned int GetGaugeLevel()  override;
				virtual float GetGaugeMaturity() override;
				virtual float GetGaugePoint() override; //Current_Value / c_gauge_max
				virtual void AddGaugeValue(float) override; 
				virtual void AddMaturityValue() override; //Not Sure About That One, but i keep it, always fixed (

				virtual void DestroyObject(unsigned int flag) override;




				//FIELDS
				float GaugeValue;  //0x28
				float GaugeGroundTime; //0x2C
				unsigned int Unknown0x30; //maybe start from zero instead max  0x30
				int IsNotGrounded; // Or Is Can Heal 0x34
				float c_gauge_max; // 0x38
				float c_green; //0x3C
				float c_red; // 0x40
				float c_blue; // 0x44
				float c_white; // 0x48
				float c_sky; // 0x4C
				float c_yellow; // 0x50
				float c_purple; // 0x54
				float c_super; // 0x58
				float c_gauge_heal; // 0x5C
				float c_gauge_heal_delay; // 0x60






			};


	


	}
}
