#pragma once
#include "CommonObject.h"



namespace Sonicteam {

	namespace Player{
		namespace State{

			//WHERE T : CommonContext
			template <typename T>
			class BasedObject:public CommonObject{
				public:
				T* BOContext;
				BasedObject(IMachine*);
			};

			template <typename T>
			Sonicteam::Player::State::BasedObject<T>::BasedObject(IMachine* a1)
			{
				this->BOContext = a1->GetMashineContext().get();

			}

		}

	}

}