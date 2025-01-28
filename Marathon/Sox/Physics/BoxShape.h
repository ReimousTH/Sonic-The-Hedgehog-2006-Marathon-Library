#pragma once
#include "..\RefCountObject.h"
#include "Shape.h"

#include <xtl.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class BoxShape:public Sonicteam::SoX::Physics::Shape
			{
			public:
				//size0x60
				BoxShape(double width,double height,double length);
				~BoxShape(void);


				float Width; //0x10
				float Height; //0x14
				float Length; //0x18
				

				virtual void DestroyObject(unsigned int flag) override;

				virtual void ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2) override = 0;
				virtual int ShapeProceedUnk02() override; // i guess




			};
		};
	}
}
