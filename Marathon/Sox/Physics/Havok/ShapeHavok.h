#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>


namespace Sonicteam{
	namespace SoX{	
		namespace Physics{
			namespace Havok{
			class ShapeHavok
			{
			public:
				//size0x60
				ShapeHavok(void);
				~ShapeHavok(void);

				unsigned int* MhkBaseObject; // Marathon no name left ((( off_8207ED80 0x20
				

				virtual void DestroyObject(unsigned int flag);

			};
			};
		};
	}
}
