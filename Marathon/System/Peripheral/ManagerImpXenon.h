#pragma once
#include <xtl.h>
#include <xinputdefs.h>
#include <iostream>
#include <utility>

#define XENON_GAMEPAD_DPAD_UP			0x40     
#define XENON_GAMEPAD_DPAD_DOWN         0x80
#define XENON_GAMEPAD_DPAD_LEFT         0x100
#define XENON_GAMEPAD_DPAD_RIGHT        0x200
#define XENON_GAMEPAD_START             0x40
#define XENON_GAMEPAD_BACK              0x800
#define XENON_GAMEPAD_LEFT_THUMB        0x10000
#define XENON_GAMEPAD_RIGHT_THUMB       0x20000
#define XENON_GAMEPAD_LEFT_SHOULDER     0x1000
#define XENON_GAMEPAD_RIGHT_SHOULDER    0x2000
#define XENON_GAMEPAD_A                 0x1
#define XENON_GAMEPAD_B                 0x2
#define XENON_GAMEPAD_X                 0x8
#define XENON_GAMEPAD_Y                 0x10

namespace Sonicteam{
	namespace System{
		namespace Peripheral{


		
			struct XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE_STRUCT {
				unsigned int From;
				unsigned int To;
			};
			
			static const XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE_STRUCT XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE[14] = {
				{ XINPUT_GAMEPAD_DPAD_UP,			XENON_GAMEPAD_DPAD_UP },
				{ XINPUT_GAMEPAD_DPAD_DOWN,			XENON_GAMEPAD_DPAD_DOWN },
				{ XINPUT_GAMEPAD_DPAD_LEFT,			XENON_GAMEPAD_DPAD_LEFT },
				{ XINPUT_GAMEPAD_DPAD_RIGHT,		XENON_GAMEPAD_DPAD_RIGHT },
				{ XINPUT_GAMEPAD_START,				XENON_GAMEPAD_START },
				{ XINPUT_GAMEPAD_BACK,				XENON_GAMEPAD_BACK },
				{ XINPUT_GAMEPAD_LEFT_THUMB,		XENON_GAMEPAD_LEFT_THUMB },
				{ XINPUT_GAMEPAD_RIGHT_THUMB,		XENON_GAMEPAD_RIGHT_THUMB },
				{ XINPUT_GAMEPAD_LEFT_SHOULDER,		XENON_GAMEPAD_LEFT_SHOULDER },
				{ XINPUT_GAMEPAD_RIGHT_SHOULDER,	XENON_GAMEPAD_RIGHT_SHOULDER },
				{ XINPUT_GAMEPAD_A,					XENON_GAMEPAD_A },
				{ XINPUT_GAMEPAD_B,					XENON_GAMEPAD_B },
				{ XINPUT_GAMEPAD_X,					XENON_GAMEPAD_X },
				{ XINPUT_GAMEPAD_Y,					XENON_GAMEPAD_Y }
			};



			//0x10
			#pragma pack(push, 4) 
			typedef struct {
				unsigned int bActive; // 0x0
				unsigned int wButtons; //0x4,       
				short sThumbLX;        // 0x8  0xFFFF8000  ->  0x8001; 
				short sThumbLY;        // -sThumbLY  0xA 
				short sThumbRX; // 0xC
				short sThumbRY; // 0xE //-sThumbLY 
			} XINPUT_GAMEPAD_STATE;
			#pragma pack(pop)






			//0x58
#pragma pack(push,4)
			class ManagerImpXenon
			{
			public:
				ManagerImpXenon(void);
				~ManagerImpXenon(void);

				byte IsActive;  //it works
				_XINPUT_CAPABILITIES GAMEPAD_CAPABILITIES[4];


				virtual void DestroyObject(unsigned int flag);
				virtual void ManagerUnk01();
				virtual int ManagerGetMaxInputCount();
				virtual int MangerProcessInput(XINPUT_GAMEPAD_STATE* _buffer_,int _buffer_count);
				virtual int ManagerGetThumbstickValues(unsigned int index,short* buffer);
			};
#pragma pack(pop)


		}
	}
}

