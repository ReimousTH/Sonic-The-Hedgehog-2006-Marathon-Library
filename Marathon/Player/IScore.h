#pragma once

#include "IPlugIn.h"
#include "IVariable.h"
#include "IStepable/IStepable.h"
#include <xtl.h> //replace to only XMFLOAT4

namespace Sonicteam{
	namespace Player{

		
		class IScore:public IPlugIn, public IVariable, public IStepable
		{
		public:
			IScore(void);
			~IScore(void);

			virtual void AddRings(int) = 0;
			virtual void TakeDamage(void) = 0;
			virtual void TakeDamageOld() = 0;
			virtual void TakeDamageLittle() = 0;
			virtual int GetRings() = 0;
			virtual void SetRings(int) = 0;
			virtual void SetUnknownVector(XMFLOAT4*) = 0; //have no idea

			virtual void DestroyObject(unsigned int flag);





		

		};

	}
}

