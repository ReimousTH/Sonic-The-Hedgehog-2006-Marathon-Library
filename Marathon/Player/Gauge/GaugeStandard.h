#pragma once

#include "IGauge.h"
#include "../Basics.h"

namespace Sonicteam{
	namespace Player{


		
	
		class GaugeStandard:public IGauge
			{
			public:

				//testing

			//	std::type_info const &type() const { return typeid(*this); }

				//

				GaugeStandard(void);
				~GaugeStandard(void);



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




				//FIELDS
				float GaugeValue;  //0x28
				float c_s_max; //0x2C
				unsigned int GaugeFlags; //maybe start from zero instead max  0x30
			

			};


	


	}
}
