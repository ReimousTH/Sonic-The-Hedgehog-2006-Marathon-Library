#pragma once

#include <xtl.h>


namespace Sonicteam{

	namespace Player{

		class IFlagCommunicator
		{
		public:
			IFlagCommunicator(void);
			~IFlagCommunicator(void);
			DESTRUCTION_H;

			virtual void SetFlag01(DWORD flag_value){}; // ContextFlags????// (ImportContextFlags) 0
			virtual void SetFlag02(DWORD flag_value){}; //Set GroundAirData Flag (ImportPostureFlags) 4
			virtual void SetFlag03(DWORD flag_value){}; //8
			virtual void SetFlag04(DWORD flag_value){}; //UnknownFlags0xC8(by context) c
			virtual void SetFlag05(DWORD flag_value){}; //10
			virtual void SetFlag06(DWORD flag_value){}; //14
			virtual void ImportAnimationStateFlag(DWORD flag_value){}; // (ImportAnimationFlags) //18
			virtual void SetFlag08(DWORD flag_value){};
			virtual void SetFlag09(DWORD flag_value){};			
			virtual void SetFlag10(DWORD flag_value){};
			virtual void SetFlag11(DWORD flag_value){};
			virtual void SetFlag12(DWORD flag_value){};
		};

	}
}
