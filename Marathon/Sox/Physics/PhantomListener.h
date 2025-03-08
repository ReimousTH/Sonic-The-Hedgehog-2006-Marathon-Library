#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>
#include <Sox/Physics/EntityContainer.h>

#define PhantomListenerEntityContainerType EntityContainer

namespace Sonicteam{
	namespace SoX{
		namespace Physics{

		



			class PhantomListener:public Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				PhantomListener(void);
				~PhantomListener(void);


				//name not finish
				virtual void PhantomListenerOnStart(PhantomListenerEntityContainerType) = 0;
				virtual void PhantomListenerOnUpdate(PhantomListenerEntityContainerType) = 0;
				virtual void PhantomListenerOnEnd(PhantomListenerEntityContainerType) = 0;

				DESTRUCTION_H;

		


			};
		};
	}
}
