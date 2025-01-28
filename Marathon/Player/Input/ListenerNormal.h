#pragma once


#include <list>
#include "IListener.h"
#include "../IPlugIn.h"
#include "../IVariable.h"
#include "../IStepable/IStepable.h"

#define LN_GAMEPAD_BUTTON_A_PRESS 3
#define LN_GAMEPAD_BUTTON_A_HOLD 2
#define LN_GAMEPAD_BUTTON_A_RELEASE 4

#define LN_GAMEPAD_BUTTON_X_PRESS 0x2340
#define LN_GAMEPAD_BUTTON_X_HOLD 0x200
#define LN_GAMEPAD_BUTTON_X_RELEASE 0x5500
#define LN_GAMEPAD_BUTTON_X_AFTER_HOLD_RELEASE 0x5C00



#define LN_GAMEPAD_BUTTON_RT_PRESS 0x30000
#define LN_GAMEPAD_BUTTON_RT_HOLD 0x20000
#define LN_GAMEPAD_BUTTON_RT_RELEASE 0x40000

#define LN_GAMEPAD_BUTTON_Y_PRESS 0x8010


#define LN_GAMEPAD_DPAD_LEFT_PRESS 0x200000
#define LN_GAMEPAD_DPAD_RIGHT_PRESS 0x100000

#define LN_GAMEPAD_FORWARD_BACKWARD_PRESS 8


namespace Sonicteam{
	namespace Player{


		namespace Input{


			//size 0x18
			class ListenerNormal:Sonicteam::Player::Input::IListener,Sonicteam::Player::IPlugIn,Sonicteam::Player::IVariable,Sonicteam::Player::IStepable
			{
			public:

				ListenerNormal(unsigned int,unsigned int);
				~ListenerNormal(void);

				virtual void ListenerOnUpdate(int,float);

				virtual XMFLOAT4* ListenerGetStickVector4();

				virtual float ListenerGetStickPower();

				virtual unsigned int ListenerGetResult();

				virtual int Listener5();

				virtual void OnVarible(LuaSystem**);

				virtual void OnStepable(float);

				unsigned int ptr0x40;
				unsigned int ptr0x44;
				unsigned int unk0x48;
				float StickPower; 
				XMFLOAT4 StickVector; //0x50 

				
				//unsigned int ptr0x60; //???// type size with 0x14 (vector(no any about vector) std::list maybe )
				//std::list<unsigned int> unkList0x60;

				byte unkgap0x60[0x14];


				float unkfloat0x74;

				IListenerInputStruc02 ILISunk0x78; // A Button
				IListenerInputStruc03 ILISunk0x88; // X Button
				unsigned int unk0x9c; //always=1 
				unsigned int unk0xA0; //always=8
				unsigned int unk0xA4; //always=0x10
				unsigned int unk0xA8; //always=0x8000 
				IListenerInputStruc02 ILISunk0xAC;	 //RT Button
				float c_input_border; //  0.1 

		
			


			


	
			};

		}
		
	}
}

