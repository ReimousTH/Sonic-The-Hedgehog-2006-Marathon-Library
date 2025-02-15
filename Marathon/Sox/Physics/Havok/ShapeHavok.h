#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>


#ifdef _HAVOK
#include <Physics/Collide/Shape/hkpShape.h>
#include <Physics/Collide/Shape/hkpShape.h>
#include <Physics/Collide/Shape/Convex/Box/hkpBoxShape.h>
#define HAVOK_SHAPE_TYPE hkpShape
#define HAVOK_SHAPE_BOX_CREATEDYNAMIC(width,height,length) new hkpBoxShape(hkVector4(width,height,length))



#else
#define HAVOK_SHAPE_TYPE void
#define HAVOK_SHAPE_BOX_CREATEDYNAMIC(width,height,length) malloc(4)
#endif





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

				HAVOK_SHAPE_TYPE* HavokShape;

			
				

				DESTRUCTION_H;

			};
			};
		};
	}
}
