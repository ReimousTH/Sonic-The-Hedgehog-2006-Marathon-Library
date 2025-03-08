#ifndef SONICTEAM__SOX__PHYSICS__ENTITYJOINT
#define SONICTEAM__SOX__PHYSICS__ENTITYJOINT


#include <Sox/Graphics/FrameObserver.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/Physics/Entity.h>


namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class EntityJoint:Sonicteam::SoX::Graphics::FrameObserver,public Sonicteam::SoX::RefCountObject
			{
			public:

			 	REF_TYPE(Sonicteam::SoX::Physics::Entity) Entity; //0x1C

				virtual void ObserveFrameStep(FrameObserverStepType);

				DESTRUCTION_H;
				
			};
		};
	}
}



#endif

