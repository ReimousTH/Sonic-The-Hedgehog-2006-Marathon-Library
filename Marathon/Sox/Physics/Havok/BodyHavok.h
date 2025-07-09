#ifndef SONICTEAM__SOX__PHYSICS__HAVOK__BODYHAVOK
#define SONICTEAM__SOX__PHYSICS__HAVOK__BODYHAVOK


#include <sox/Physics/Body.h>
#include <Sox/Physics/Havok/EntityHavok.h>

namespace Sonicteam{
	namespace SoX{	
		namespace Physics{
			namespace Havok{

				//size0x90
				class BodyHavok:public Sonicteam::SoX::Physics::Body,public Sonicteam::SoX::Physics::Havok::EntityHavok
				{
				public:
					//size0x60
					BodyHavok();
					~BodyHavok();


					unsigned int unk0x80; // ? 

					DESTRUCTION_H;
					




				};
			};
		};
	}
}
#endif
