#ifndef Sonicteam__SOX__Graphics__INSTANCEMODELCOMMON
#define Sonicteam__SOX__Graphics__INSTANCEMODELCOMMON



#include "Defs.h"
#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/Graphics/InstanceModel.h>


namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


	
			//:)
			class InstanceModelCommon:public Sonicteam::SoX::Graphics::InstanceModel 
			{

			public:
				InstanceModelCommon();
				~InstanceModelCommon();

				DESTRUCTION_H override;





			};
		};
	}
}

#endif

