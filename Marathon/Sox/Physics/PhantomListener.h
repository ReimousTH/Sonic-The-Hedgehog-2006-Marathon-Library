#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>
#include <Player/EntityContainer.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{

		



			class PhantomListener:Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				PhantomListener(void);
				~PhantomListener(void);


				//name not finish
				virtual void PhantomListenerOnStart(EntityContainer) = 0;
				virtual void PhantomListenerOnUpdate(EntityContainer) = 0;
				virtual void PhantomListenerOnEnd(EntityContainer) = 0;

				DESTRUCTION_H;

		


			};
		};
	}
}
