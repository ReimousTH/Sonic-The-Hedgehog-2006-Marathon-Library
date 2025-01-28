#pragma once

#include "..\IPlugIn.h"
#include "..\IVariable.h"
#include "..\IStepable\IStepable.h"




namespace Sonicteam{
	namespace Player{
		class IGauge:public IPlugIn,IVariable,IStepable
		{
		public:
			IGauge(char*);
			~IGauge(void); //Something missing, maybe additional something like extern ????
			virtual void OnVarible(LuaSystem**) override = 0;
			virtual void OnStepable(float) override = 0;

			//IGaugeVFTTABLE
			virtual float GetGaugeValue() = 0;
			virtual unsigned int GetGaugeLevel() = 0;
			virtual float GetGaugeMaturity() = 0;
			virtual float GetGaugePoint() = 0; //Current_Value / c_gauge_max
			virtual void AddGaugeValue(float) = 0; 
			virtual void AddMaturityValue() = 0; //Not Sure About That One, but i keep it, always fixed (

			void DestroyObject(unsigned int flag) override;

		
		};
	}
}