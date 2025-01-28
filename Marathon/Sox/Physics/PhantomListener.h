#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{

			struct PLMessage{
				unsigned int MessageInfo1; // (just number)
				unsigned int MessageInfo2; // send message back  (here example 82206070)

				PLMessage(unsigned int a1,unsigned int a2){
					this->MessageInfo1 =a1;
					this->MessageInfo2 =a2;
				};


			};





			class PhantomListener:Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				PhantomListener(void);
				~PhantomListener(void);


				virtual void PhLsProcessMessage1(PLMessage&) {};
				virtual void PhLsProcessMessage2(PLMessage&) {};
				virtual void PhLsProcessMessage3(PLMessage&) {};

				virtual void DestroyObject(unsigned int flag) override;

		


			};
		};
	}
}
