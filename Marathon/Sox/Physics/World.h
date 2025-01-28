#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class World:Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				World(void);
				~World(void);

				virtual void PhysicsWorldUnk01(XMFLOAT4*) = 0; //WorldProcessAndStoreVector
				virtual XMFLOAT4 PhysicsWorldUnk02() = 0; //WorldProcessAndReturnVector
				virtual void  PhysicsWorldUnk03(float) = 0;
				virtual unsigned int PhysicsWorldUnk04(XMFLOAT4*,unsigned int) = 0; //idek,r5 = EnemyRayCastListene(820257E8), Process Enemy BUllets Or Some
				virtual void PhysicsWorldUnk05(unsigned int) = 0; // no idea
				virtual void PhysicsWorldUnk07(unsigned int) = 0; // no idea
				virtual void PhysicsWorldUnk08(unsigned int) = 0; // no idea
				virtual void PhysicsWorldUnk09(unsigned int) = 0; // no idea


			};
		};
	}
}
