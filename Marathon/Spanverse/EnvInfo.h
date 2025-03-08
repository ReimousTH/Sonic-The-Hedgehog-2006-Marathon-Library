#ifndef SONICTEAM__SPANVERSE__ENVINFO
#define SONICTEAM__SPANVERSE__ENVINFO


#include <xtl.h>
#include <boost/shared_ptr.hpp>
#include <Sox/Misc/VectorExtension.h>
#include <string>
#include <map>

#include <Spanverse/ModelPlugin/ModelInfo.h>
#include <Spanverse/ModelPlugin/ModelStandardInfo.h>

namespace Sonicteam{
	namespace Spanverse{
		class EnvInfo{
			public:
			EnvInfo();
			~EnvInfo();

			std::map<std::string,boost::shared_ptr<Sonicteam::Spanverse::ModelPlugin::ModelInfo>> EnvModelInfoMap; 
			boost::shared_ptr<Sonicteam::Spanverse::ModelPlugin::ModelStandardInfo> ModelStandardInfo;
			boost::shared_ptr<Sonicteam::Spanverse::ModelPlugin::ModelMorphInfo> ModelMorphInfo;

	
			
		};
	};
};



#endif