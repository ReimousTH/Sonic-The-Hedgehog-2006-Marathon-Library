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

			virtual void ImportICommonContextIFFlag(DWORD flag_value){}; // ContextFlags????// (ImportContextFlags) 0
			virtual void ImportIPosturePlugInFlag(DWORD flag_value){}; //Set GroundAirData Flag (ImportPostureFlags) 4
			virtual void IFlagCommunicator0xC(DWORD flag_value){}; //8
			virtual void ImportExternalFlag(DWORD flag_value){}; //UnknownFlags0xC8(by context) c
			virtual void ImportICommonContextIFFlag2(DWORD flag_value){}; //10
			virtual void ImportICommonContextIFFlag3(DWORD flag_value){}; //14
			virtual void ImportIModelAnimationFlag(DWORD flag_value){}; // (ImportAnimationFlags) //18
			virtual void ImportPostureRequestFlag(DWORD flag_value){}; //impulse flag
			virtual void ImportWeaponRequestFlag(DWORD flag_value){};			
			virtual void ImportUpgradeFlag(DWORD flag_value){};
			virtual void ImportVehicleFlag(DWORD flag_value){};
			virtual void ImportAIIBaseFlag(DWORD flag_value){};
		};

	}
}
