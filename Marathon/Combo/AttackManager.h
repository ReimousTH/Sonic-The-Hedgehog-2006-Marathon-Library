#pragma once
#include <xtl.h>
#include <vector>

namespace Sonicteam{
	namespace Combo{

		//Size 0x1C, no methods, only destructor	
		class AttackManager
		{
		public:
			AttackManager(void);
			virtual ~AttackManager(void);

			DWORD field_4;
			DWORD PComboScoreManager;
			std::vector<void*> unk_vec;
		

			//vtable
			//field_4 (???) 
			//PComboScoreManager
			// std::vector<???> ????
			// 




		};

	}
}


