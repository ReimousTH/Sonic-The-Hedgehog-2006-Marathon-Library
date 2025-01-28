#pragma once


#include "..\IPlugIn.h"
#include "..\IVariable.h"
#include "..\IDynamicLink.h"
#include "..\IFlagCommunicator.h"




namespace Sonicteam{

	namespace Player{
		namespace State{

		
			class IContext:public IPlugIn,IVariable,IDynamicLink,IFlagCommunicator
			{
			public:
				IContext(char*);
				~IContext(void);
				virtual void OnLink(Sonicteam::Player::IPlugIn*& plugin) override {};
				virtual void OnVarible(LuaSystem**) override = 0;

				//Original IContxext 0x0 Vfttable
				virtual void ICOnPostInputTick(void) = 0; // Used To Decide Who Controls Object::Player AI or Player and store input in 0x54
				virtual void ICOnInputTick(float) = 0; // Character.Core(Old name) update full character states per input tick (PostInputTick->InputTick)

				virtual void DestroyObject(unsigned int flag);





			

			};

		}

	}

}

