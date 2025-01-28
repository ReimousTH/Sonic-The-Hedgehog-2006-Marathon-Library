#pragma once

#include <xtl.h>


namespace Sonicteam{

	namespace Player{

		class IFlagCommunicator
		{
		public:
			IFlagCommunicator(void);
			virtual ~IFlagCommunicator(void);
			virtual void SetFlag01(DWORD flag_value){}; // ContextFlags????// (ImportContextFlags)
			virtual void SetFlag02(DWORD flag_value){}; //Set GroundAirData Flag (ImportPostureFlags)
			virtual void SetFlag03(DWORD flag_value){};
			virtual void SetFlag04(DWORD flag_value){}; //UnknownFlags0xC8(by context)
			virtual void SetFlag05(DWORD flag_value){};
			virtual void SetFlag06(DWORD flag_value){};
			virtual void ImportAnimationStateFlag(DWORD flag_value){}; // (ImportAnimationFlags)
			virtual void SetFlag08(DWORD flag_value){};
			virtual void SetFlag09(DWORD flag_value){};			
			virtual void SetFlag10(DWORD flag_value){};
			virtual void SetFlag11(DWORD flag_value){};
			virtual void SetFlag12(DWORD flag_value){};
		};

	}
}
