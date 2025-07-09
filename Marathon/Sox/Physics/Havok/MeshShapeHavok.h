#ifndef SONICTEAM__SOX__PHYSICS__HAVOK__MESHSHAPEHAVOK
#define SONICTEAM__SOX__PHYSICS__HAVOK__MESHSHAPEHAVOK

#include <Sox/Memory/Destruction.h>
#include <Sox/Physics/MeshShape.h>
#include <Sox/Physics/Havok/ShapeHavok.h>

namespace Sonicteam{
	namespace SoX{	
		namespace Physics{
			namespace Havok{
				class MeshShapeHavok:public Sonicteam::SoX::Physics::MeshShape,public Sonicteam::SoX::Physics::Havok::ShapeHavok
				{
				public:
			
					MeshShapeHavok();
					~MeshShapeHavok();
					DESTRUCTION_H;



				};
			};
		};
	}
}
#endif
