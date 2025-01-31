#pragma once
#ifndef SONICTEAM__PLAYER__IMODEL

#include "Defs.h"
#include <boost/function.hpp>
#include <Sox/Scenery/Clump.h>
#include <Player/IPlugIn.h>

namespace Sonicteam{
	namespace Player{


		class IModel:public Sonicteam::Player::IPlugIn
		{
		public:
			IModel(char* plugname);

			virtual unsigned int IModelGetAnimID1() = 0;
			virtual unsigned int IModelGetAnimID2() = 0;
			virtual unsigned int IModelGetExportAnimID() = 0; //IAnimation base
			virtual void IModelSetFunc(unsigned int Flag, boost::function<int(void*)> setfunc) = 0;
			virtual void OnIModelFlag(unsigned int Flag) = 0;
			virtual REF_TYPE(Sonicteam::SoX::Scenery::Clump) IModelGetSceneryClump() = 0;
			virtual void IModelSetAnimationFrameTime(double delta) = 0;
			virtual void IModelProcess() = 0; // ? 

		};

	}
}

#define SONICTEAM__PLAYER__IMODEL
#endif





