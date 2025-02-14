#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>

#include <Sox/Physics/CapsuleShape.h>
#include <Sox/Physics/Havok/ShapeHavok.h>


namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			namespace Havok{
				class CapsuleShapeHavok:Sonicteam::SoX::Physics::CapsuleShape,Sonicteam::SoX::Physics::Havok::ShapeHavok
			{
			public:
				//size0x60
				CapsuleShapeHavok(double radius,double height);
				~CapsuleShapeHavok(void);

				DESTRUCTION_H override;

				virtual void ShapeProceedUnk01(__out XMFLOAT4* u1,__out XMFLOAT4* u2) override;

				virtual void ShapeInitVolume() override;



	

			};
			};
		};
	}
}
