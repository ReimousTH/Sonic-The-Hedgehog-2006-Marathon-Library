#pragma once
#include "../LuaSystem.h"

#define IVARIABLETYPE Sonicteam::LuaSystem**


namespace Sonicteam{
	namespace Player{

		
		class IVariable
		{
		public:
			IVariable(void);
			static const char* varible;
			virtual void OnVarible(IVARIABLETYPE) = 0; // args (DWORD[3], 0 = LuaSystemMarathon, 1 = UnkPointerIDK, 2 =  Sonicteam::Spanverse::CustomEssenceModel
			
			
		};

	};
};

