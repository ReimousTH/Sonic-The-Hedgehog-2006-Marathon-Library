#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>




#include <Common/Base/System/hkBaseSystem.h> // include for hkBaseSystem
#include <Common/Base/Memory/Memory/Pool/hkPoolMemory.h> // hkPoolMemory


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
