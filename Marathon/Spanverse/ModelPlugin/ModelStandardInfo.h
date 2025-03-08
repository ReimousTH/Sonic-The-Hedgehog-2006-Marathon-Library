#ifndef SONICTEAM__SPANVERSE__MODELPLUGIN__MODELSTANDARDINFO
#define SONICTEAM__SPANVERSE__MODELPLUGIN__MODELSTANDARDINFO

#include "Defs.h"
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Spanverse/ModelPlugin/ModelInfo.h>


namespace Sonicteam{
	namespace Spanverse{
		namespace ModelPlugin{


			class ModelStandardInfo:Sonicteam::Spanverse::ModelPlugin::ModelInfo{
			public:
				ModelStandardInfo();
				~ModelStandardInfo();
				DESTRUCTION_H;

			};


		};
	};
};



#endif