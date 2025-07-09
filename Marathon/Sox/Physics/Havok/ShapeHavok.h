#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>


#ifdef _HAVOK
#include <Physics/Collide/Shape/hkpShape.h>
#include <Physics/Dynamics/Phantom/hkpSimpleShapePhantom.h>
#include <Physics/Collide/Shape/Convex/Box/hkpBoxShape.h>
#include <Physics/Collide/Shape/Compound/Tree/Mopp/hkpMoppBvTreeShape.h>
#include <Physics/Collide/Shape/Deprecated/Mesh/hkpMeshShape.h>

#define HAVOK_SHAPE_TYPE hkpShape
#define HAVOK_SHAPE_SIMPLEPHANTOM_TYPE hkpSimpleShapePhantom
#define HAVOK_SHAPE_BOX_CREATEDYNAMIC(width,height,length) new hkpBoxShape(hkVector4(width,height,length))
#define HAVOK_SHAPE_HKMOPPBVTREESHAPE_CREATEDYNAMIC() new hkpMoppBvTreeShape() 
#define HAVOK_SHAPE_MESHSHAPE_CREATEDYNAMIC(radius,numBitsForSubpartIndex)) new hkpMeshShape(radius,numBitsForSubpartIndex) 
#define HAVOK_SHAPE_MESHSHAPE_SetScaling(MeshShape,x,y,z,w) MeshShape->setScaling(hkVector4(x,y,z,w));
#define HAVOK_SHAPE_MESHSHAPE_ComputeWeldingInfo(MeshShape,MOPPBVTREESHAPE,WeldingType) MeshShape->computeWeldingInfo(MOPPBVTREESHAPE,WeldingType)

//redef to use Without Havok
#define HAVOK_WELDING_TYPE_ANTICLOCKWISE WELDING_TYPE_ANTICLOCKWISE
#define HAVOK_WELDING_TYPE_CLOCKWISE WELDING_TYPE_CLOCKWISE
#define HAVOK_WELDING_TYPE_TWO_SIDED WELDING_TYPE_TWO_SIDED
#define HAVOK_WELDING_TYPE_NONE WELDING_TYPE_NONE



#define HCSDRadius hkConvexShapeDefaultRadius



#else
#define HAVOK_SHAPE_TYPE void
#define HAVOK_SHAPE_SIMPLEPHANTOM_TYPE void
#define HAVOK_SHAPE_BOX_CREATEDYNAMIC(width,height,length) malloc(4)
#define HAVOK_SHAPE_BOX_HKMOPPBVTREESHAPE() malloc(4)



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
