#ifndef Sonicteam__SOX__Graphics__DRAWPRIMITIVECACHE
#define Sonicteam__SOX__Graphics__DRAWPRIMITIVECACHE


#include "Defs.h"
#include <Sox/RefCountObject.h>




namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


	
			//:)
			class DrawPrimitiveCache:public Sonicteam::SoX::RefCountObject //Need Aditional Methods, FullClearLink()
			{

			public:
				DrawPrimitiveCache();
				~DrawPrimitiveCache();

				DESTRUCTION_H;
			

		

			};
		};
	}
}

#endif

