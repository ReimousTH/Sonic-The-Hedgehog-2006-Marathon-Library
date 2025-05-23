#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>

#include <Sox/Physics/BoxShape.h>
#include <Sox/Physics/Havok/ShapeHavok.h>

#include <Sox/Memory/Destruction.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			namespace Havok{
				class BoxShapeHavok:Sonicteam::SoX::Physics::BoxShape,Sonicteam::SoX::Physics::Havok::ShapeHavok
			{
			public:
				//size0x60
				BoxShapeHavok(double width,double height,double length);
				~BoxShapeHavok(void);

				DESTRUCTION_H;

				virtual void ShapeProceedUnk01(__out XMFLOAT4* u1,__out XMFLOAT4* u2);
				virtual void ShapeInitVolume();

			};
			};
		};
	}
}
