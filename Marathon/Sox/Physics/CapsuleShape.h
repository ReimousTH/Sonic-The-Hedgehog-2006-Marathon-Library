#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include "Shape.h"


namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class CapsuleShape:public Sonicteam::SoX::Physics::Shape
			{
			public:
				//size0x60
				CapsuleShape(double height,double radius);
				~CapsuleShape(void);

	

				float Radius; //0x10
				float Height; //0x14
		
				

				virtual void DestroyObject(unsigned int flag) override;
	
				virtual void ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2) override = 0;
				virtual int ShapeProceedUnk02() override; // i guess




			};
		};
	}
}
