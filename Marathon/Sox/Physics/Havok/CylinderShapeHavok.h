#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>

#include <Sox/Physics/CylinderShape.h>
#include <Sox/Physics/Havok/ShapeHavok.h>


namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			namespace Havok{
				class CylinderShapeHavok:Sonicteam::SoX::Physics::CylinderShape,Sonicteam::SoX::Physics::Havok::ShapeHavok
			{
			public:
				//size0x60
				CylinderShapeHavok(double radius,double height);
				~CylinderShapeHavok(void);

				virtual void DestroyObject(unsigned int flag) override;

				virtual void ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2) override;

				virtual int ShapeProceedUnk02() override;



	

			};
			};
		};
	}
}
