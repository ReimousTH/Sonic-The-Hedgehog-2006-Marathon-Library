#pragma once

namespace Sonicteam{
	namespace Player{
		namespace State{

			class ICommonContextIF
			{
			public:
				ICommonContextIF(void);
				virtual void ICCIF_01(float,float,float)= 0;
				virtual void ICCIF_02(float,float,float,float)= 0; // no args_first , then pass Context flag to to other
				virtual void ICCIF_03()= 0;
				virtual void ICCIF_04()= 0; //Export UnknownFlags01
				virtual void ICCIF_05()= 0; 
				virtual float GetTotalSpeedY()= 0; // no args
				virtual float GetTotalSpeedZ()= 0; // self
				static const float  unk_float;





			};


		}


	}
}

