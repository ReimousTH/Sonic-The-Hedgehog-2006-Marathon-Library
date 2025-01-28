	#pragma once


#include "IPlugIn.h"
namespace Sonicteam{
	namespace Player{

		
		class IModel:Sonicteam::Player::IPlugIn
		{
		public:
			IModel(char* plugname);

			virtual unsigned int GetAnimationID1();
			virtual unsigned int GetAnimationID2();
			virtual unsigned int GetAnimationData(); //IAnimation base


			
		};

	}
}

