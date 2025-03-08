#ifndef SONICTEAM__PLAYER__LOAD
#define SONICTEAM__PLAYER__LOAD


#include "Defs.h"
#include <Sox/Graphics/Frame.h>
#include <Sox/Memory/IDestructible.h>
#include <Player/IPlugIn.h>
#include <Player/IExportExternalFlag.h>
#include <Sox/Engine/Doc.h>
#include <Sox/Memory/DEFINITIONS.hpp>

#include <map>
#include <Player/ILoad.h>
#include <string>


#include <memory>
#include <iostream>
#include <deque>


#include <Sox/RefCountObject.h>
#include <boost/shared_ptr.hpp>
#include <PackageBinary.h>
#include <Player/AnimationScript.h>

namespace Sonicteam{
	namespace Player{





		class Load:public ILoad
		{
		public:
			Load(Sonicteam::SoX::Engine::Doc* doc);
			~Load(void);


			//YES IT IS  std::_Tree<std::_Tmap_traits< match 
			DESTRUCTION_H override;

			std::map<std::string,REF_TYPE(Sonicteam::PackageBinary)> PackageBinary;
			std::map<std::string,boost::shared_ptr<Sonicteam::Player::AnimationScript>> PackageScript; //not sure
			std::deque<REF_TYPE(Sonicteam::SoX::RefCountObject)> RefObjects0x38; //or que
			Sonicteam::SoX::Engine::Doc* EDoc; //0x4C

	
			_MARATHON_DEFINE_CONSTRUCTOR_(Load,0x821E2C18,Sonicteam::SoX::Engine::Doc* doc);

			virtual Sonicteam::SoX::RefCountObject LoadPackage(std::string* package_path);

			virtual Sonicteam::DocMarathonPlayerInput* GetInputFCopy(Sonicteam::DocMarathonPlayerInput* out_input,int index);

			virtual void ProcessFrame(Sonicteam::SoX::Graphics::Frame** PlayerFrame);

			virtual void ProcessClump01(Sonicteam::SoX::RefCountObject** obj);

			virtual void ProcessClump02(Sonicteam::SoX::RefCountObject** obj);

			virtual void ProcessClump02_01(Sonicteam::SoX::RefCountObject** obj);

			virtual void ProcessClump02_02(Sonicteam::SoX::RefCountObject** obj);

			virtual void ILoadUnknown();

			virtual void ProcessClump02_03(Sonicteam::SoX::RefCountObject** obj);

			virtual void* GetDGraphicDevice();

			virtual void* GetDUnkModules();

			virtual void DocProcessSFX(Sonicteam::SoX::RefCountObject**);

			virtual void DocProcessThread(Sonicteam::SoX::StepableThread*);






		};

	}
}




#endif


