#ifndef SONICTEAM__SOX__PHYSISC__MESHSHAPE
#define SONICTEAM__SOX__PHYSISC__MESHSHAPE


#include <Sox/Physics/Defs.h>
#include <Sox/Physics/Shape.h>


namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class MeshShape:public Sonicteam::SoX::Physics::Shape
			{
			public:
				//size0x60
				MeshShape(void);
				~MeshShape(void);
				DESTRUCTION_H;
		


			};
		};
	}
}



#endif


