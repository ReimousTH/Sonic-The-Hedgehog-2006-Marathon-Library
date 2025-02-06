#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>
#include <Sox/Memory/Destruction.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class Shape:public Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				Shape(void);
				~Shape(void);

				unsigned int SFlag; //Shape Type
				unsigned int SVolume; // w*h*l * FLT_MIN //0xC

				

				DESTRUCTION_H;
				virtual void ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2) = 0;
				virtual void ShapeInitVolume(); // i guess


			};
		};
	}
}
