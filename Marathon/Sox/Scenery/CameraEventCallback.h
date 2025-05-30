#ifndef SONICTEAM__SOX__CAMERAEVENTCALLBACK
#define SONICTEAM__SOX__CAMERAEVENTCALLBACK


#include "Defs.h"
#include <xtl.h>


#include <SoX/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>




namespace Sonicteam{
	namespace SoX{
		namespace Scenery{
			class CameraEventCallback{

			public:
				CameraEventCallback();
				~CameraEventCallback();

				DESTRUCTION_H;
				virtual void CEC01() = 0;
				virtual void CEC02() = 0;
				virtual void CEC03() = 0;
				virtual void CEC04() = 0;
				virtual void CEC05() = 0;
			
			};
		}
	}
}
#endif