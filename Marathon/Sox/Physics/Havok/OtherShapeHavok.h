#ifndef SONICTEAM__SOX__PHYSICS__HAVOK__OTHERSHAPEHAVOK
#define SONICTEAM__SOX__PHYSICS__HAVOK__OTHERSHAPEHAVOK



#include <Sox/Physics/OtherShape.h>
#include <Sox/Physics/Havok/ShapeHavok.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			namespace Havok{




				class OtherShapeHavok:public Sonicteam::SoX::Physics::OtherShape,public Sonicteam::SoX::Physics::Havok::ShapeHavok
				{
				public:
					//size0x60
					OtherShapeHavok(HAVOK_SHAPE_TYPE*);
					~OtherShapeHavok();

			

					DESTRUCTION_H override;
				};

			};
		};
	}
}
#endif