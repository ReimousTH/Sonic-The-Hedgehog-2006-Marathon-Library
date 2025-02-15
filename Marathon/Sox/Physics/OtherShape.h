#ifndef SONICTEAM__SOX__PHYSICS__OTHERSHAPE
#define SONICTEAM__SOX__PHYSICS__OTHERSHAPE



#include <Sox/RefCountObject.h>
#include <Sox/Physics/Shape.h>
#include <Xboxmath.h>




namespace Sonicteam{
	namespace SoX{
		namespace Physics{




			class OtherShape:public Sonicteam::SoX::Physics::Shape
			{
			public:
				OtherShape();
				~OtherShape();
				DESTRUCTION_H;

			};
		};
	}
}
#endif