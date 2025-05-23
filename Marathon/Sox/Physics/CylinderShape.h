#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include "Shape.h"



namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class CylinderShape:public Sonicteam::SoX::Physics::Shape
			{
			public:
				//size0x60
				CylinderShape(double height,double radius);
				~CylinderShape(void);

			
				float Radius; //0x10
				float Height; //0x14
		
				

				DESTRUCTION_H;
	
				virtual void ShapeProceedUnk01(__out XMFLOAT4* u1,__out XMFLOAT4* u2) override = 0;
				virtual void ShapeInitVolume() override; // i guess




			};
		};
	}
}
