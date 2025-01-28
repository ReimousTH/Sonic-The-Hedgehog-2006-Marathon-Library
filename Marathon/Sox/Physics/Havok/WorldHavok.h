#pragma once

#include "../World.h"


namespace Sonicteam{
	namespace SoX{
		namespace Physics{

			namespace Havok{

				class WorldHavok:Sonicteam::SoX::Physics::World
			{
			public:
				//size0x60
				WorldHavok(void);
				~WorldHavok(void);

				virtual void PhysicsWorldUnk01(XMFLOAT4*);

				virtual XMFLOAT4 PhysicsWorldUnk02();

				virtual void PhysicsWorldUnk03(float);

				virtual unsigned int PhysicsWorldUnk04(XMFLOAT4*,unsigned int);

				virtual void PhysicsWorldUnk05(unsigned int);

				virtual void PhysicsWorldUnk07(unsigned int);

				virtual void PhysicsWorldUnk08(unsigned int);

				virtual void PhysicsWorldUnk09(unsigned int);






				//FIELDS LEFT
				

			

			};
			}

		};
	}
}
