#ifndef SONICTEAM__SOX__PHYSICS__BODY
#define SONICTEAM__SOX__PHYSICS__BODY


#include <Sox/Physics/Entity.h>
#include <Sox/Physics/Havok/EntityHavok.h>


namespace Sonicteam{
	namespace SoX{
		namespace Physics{




			class Body:public Sonicteam::SoX::Physics::Entity
			{
			public:
				//size0x60
				Body();
				~Body();

				float unk0x28; //0x28
				unsigned int unk0x2C; //0x2C
				



				DESTRUCTION_H override;


			};
		};
	}
}
#endif