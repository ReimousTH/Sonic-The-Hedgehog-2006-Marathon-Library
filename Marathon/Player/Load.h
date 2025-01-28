#pragma once
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


namespace Sonicteam{
	namespace Player{


		//UNK 
		struct PLoadBodyPackage{
			PLoadBodyPackage();
			~PLoadBodyPackage();


			char buffer[0x30];

		};

		struct PLoadHeadPackage{
			PLoadHeadPackage();
			~PLoadHeadPackage();
	

			char buffer[0x34];

		};


		
		class Load:public ILoad
		{
		public:
			Load(Sonicteam::SoX::Engine::Doc* doc);
			~Load(void);


			//YES IT IS  std::_Tree<std::_Tmap_traits< match 
			virtual void DestroyObject(unsigned int flag) override;

			std::map<std::string,PLoadBodyPackage*> PackageBody;
			std::map<std::string,PLoadHeadPackage*> PackageHead; //not sure
			unsigned int unk0x38;
			unsigned int unk0x40;
			unsigned int unk0x44;
			unsigned int unk0x48;
			Sonicteam::SoX::Engine::Doc* EDoc;
		

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

