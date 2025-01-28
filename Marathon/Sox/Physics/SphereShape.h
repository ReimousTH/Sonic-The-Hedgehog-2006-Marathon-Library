#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include "Shape.h"



namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class SphereShape:public Sonicteam::SoX::Physics::Shape
			{
			public:
				//size0x60
				SphereShape(double radius);
				~SphereShape(void);


				float Radius; //0x10
		
				

				virtual void DestroyObject(unsigned int flag) override;

				virtual void ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2);

				virtual int ShapeProceedUnk02();







			};
		};
	}
}
