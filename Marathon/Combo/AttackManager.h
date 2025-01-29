#ifndef SONICTEAM__COMBO__ATTACKMANAGER
#define SONICTEAM__COMBO__ATTACKMANAGER

#include "Defs.h"

#include "ScoreManager.h"
#include <xtl.h>
#include <vector>
#include <Sox/RefCountObject.h>

namespace Sonicteam{
	namespace Combo{

		//Size 0x1C, no methods, only destructor	
		class AttackManager:public Sonicteam::SoX::RefCountObject
		{
		public:
			AttackManager(void);
			~AttackManager(void);

			virtual void DestroyObject(unsigned int flag) override; 

			REF_TYPE(Sonicteam::Combo::ScoreManager) ScoreManager; //0x8
			std::vector<void*> unk_vec;
			unsigned int unk0x18;



		};

	}
}




#endif


