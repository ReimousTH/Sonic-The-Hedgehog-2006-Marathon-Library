#ifndef __Sonicteam__SOX__INPUT__MANAGER__
#define  __Sonicteam__SOX__INPUT__MANAGER__



#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/Input/Defs.h>

#define SO_GAMEPAD_RAW_BUTTON_A 1
#define SO_GAMEPAD_RAW_BUTTON_B 2
#define SO_GAMEPAD_RAW_BUTTON_X 8
#define SO_GAMEPAD_RAW_BUTTON_Y 0x10

#define SO_GAMEPAD_RAW_BUTTON_DPAD_UP 0x40
#define SO_GAMEPAD_RAW_BUTTON_DPAD_DOWN 0x80
#define SO_GAMEPAD_RAW_BUTTON_DPAD_LEFT 0x100
#define SO_GAMEPAD_RAW_BUTTON_DPAD_RIGHT 0x200


namespace Sonicteam{
	namespace SoX{
		namespace Input{



			//825863D8
			struct MGamepad{

				unsigned int wLastButtons; //Triggers & DPAD includ //0x10 :
				unsigned int ComplementwLastButtons; //Binary One's Complement (in short = ~wLastButtons) //0x14

				unsigned int unk18;
				unsigned int unk1C;

				// Thumb stick values converted to range [-1,+1]
				float      fX1; //0x20
				float      fY1; //0x24

				//Left thumbstick x-axis value. Each of the thumbstick axis members is a signed value describing the position of the thumbstick. A value of 0 is centered. Negative values signify down or to the left. Positive values signify up or to the right. The controller typically does not generate thumbstick values within a dead zone, or marginal input region around the center position. The constants XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE or XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE can be used as a positive and negative value to filter a thumbstick input around the dead zone. 
				short sThumbLX; //
				short sThumbLY;

				//sThumbLX -> sThumbLY (merged to one, weird??)


				// Thumb stick values converted to range [-1,+1]
				float      fX2; //0x2C
				float      fY2; //0x30
				short sThumbRX; //ref to XINPUT_GAMEPAD_STICK VALUES
				short sThumbRY;

				//sThumbLX -> sThumbLY (merged to one, weird??)

				//Next is Unk and not sure 
			};




			class Manager
			{
			public:

				Manager();
				~Manager();
				size_t ControllerID; //0x0
				LinkSoxNode<Sonicteam::SoX::Input::Listener> Listener; //4-8-c
				MGamepad Gamepad; //0x10
				size_t unk0x38;
				size_t unk0x3C;
				size_t unk0x40;
				size_t unk0x44;
				size_t unk0x48;
				size_t unk0x4C;
				size_t unk0x50;
				size_t unk0x54;
				size_t unk0x58;
				size_t unk0x5C;

			};

		};

	};
};
#endif