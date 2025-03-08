#ifndef SONICTEAM__SPANVERSE__MODELPLUGIN__MODELINFO
#define SONICTEAM__SPANVERSE__MODELPLUGIN__MODELINFO

#include "Defs.h"
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>


#include <boost/shared_ptr.hpp>
#include <DocMarathonImp.h>

#include <Sox/Graphics/Model.h>
#include <Spanverse/ModelPlugin/ModelInfo.h>

namespace Sonicteam{
	namespace Spanverse{
		namespace ModelPlugin{
			class ModelInfo{
			public:
				ModelInfo();
				~ModelInfo();

				REF_TYPE(Sonicteam::SoX::Graphics::Model) Model; //0x4
				DESTRUCTION_H;


				virtual bool InitializeModel(Sonicteam::DocMarathonImp* doc,const char* xnofilepath); //82532B70
				virtual boost::shared_ptr<Sonicteam::Spanverse::ModelPlugin::ModelControl> InitializeFromModel(Sonicteam::Spanverse::ModelPlugin::ModelInfo* ModelInfo);




			};




		};
	};
};



#endif