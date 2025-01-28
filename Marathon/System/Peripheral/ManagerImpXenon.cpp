#include "ManagerImpXenon.h"
using namespace Sonicteam::System::Peripheral;

void Sonicteam::System::Peripheral::ManagerImpXenon::DestroyObject(unsigned int flag)
{

}

void Sonicteam::System::Peripheral::ManagerImpXenon::ManagerUnk01()
{

}

int Sonicteam::System::Peripheral::ManagerImpXenon::ManagerGetMaxInputCount()
{

	return 4;
}

int Sonicteam::System::Peripheral::ManagerImpXenon::MangerProcessInput(XINPUT_GAMEPAD_STATE* _buffer_,int _buffer_count)
{
	XINPUT_STATE _buffer_state;
	if (this->IsActive && _buffer_count){
		for (int i = 0;i<_buffer_count;i++){
			_buffer_[i].wButtons = 0;
			_buffer_[i].sThumbLX = 0;
			_buffer_[i].sThumbLY = 0;
			_buffer_[i].sThumbRX = 0;
			_buffer_[i].sThumbRY = 0;
			_buffer_[i].bActive = 1;
		}

	}
	if (_buffer_count ) {
		for (int i = 0; i < _buffer_count; i++) {
			int input_state = XInputGetState(i, &_buffer_state);	
			if (input_state == 0) {
				if (_buffer_[i].bActive) XInputGetCapabilities(i, 1u, &this->GAMEPAD_CAPABILITIES[i]);
				int wbuttons = 0;
				int sThumbLX = 0;
				int sThumbLY = 0;
				int sThumbRX = 0;
				int sThumbRY = 0;

				for (int j = 0; j < 0xE; j++) {
					if ((Sonicteam::System::Peripheral::XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE[j].From & _buffer_state.Gamepad.wButtons) != 0) {
						wbuttons |= Sonicteam::System::Peripheral::XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE[j].To;
						if (wbuttons != 0){

						}
					}
				}

				if (_buffer_state.Gamepad.bLeftTrigger > 0x1Eu)
					wbuttons |= 0x4000u;
				if (_buffer_state.Gamepad.bRightTrigger > 0x1Eu)
					wbuttons |= 0x8000u;

				sThumbLX = _buffer_state.Gamepad.sThumbLX;
				if (_buffer_state.Gamepad.sThumbLX == 0xFFFF8000)
					sThumbLX = 0x8001;
				sThumbLY = _buffer_state.Gamepad.sThumbLY;
				if (_buffer_state.Gamepad.sThumbLY == 0xFFFF8000)
					sThumbLY = 0x8001;
				sThumbRX = _buffer_state.Gamepad.sThumbRX;
				if (_buffer_state.Gamepad.sThumbRX == 0xFFFF8000)
					sThumbRX = 0x8001;
				sThumbRY = _buffer_state.Gamepad.sThumbRY;
				if (_buffer_state.Gamepad.sThumbRY == 0xFFFF8000)
					sThumbRY = 0x8001;



				_buffer_[i].wButtons = wbuttons;
				_buffer_[i].sThumbLX = sThumbLX;
				_buffer_[i].sThumbLY = -sThumbLY;
				_buffer_[i].sThumbRX = sThumbRX;
				_buffer_[i].sThumbRY = -sThumbRY;
				_buffer_[i].bActive = input_state;

			}
		}
	}
	return 1;
}

int Sonicteam::System::Peripheral::ManagerImpXenon::ManagerGetThumbstickValues(unsigned int index,short* buffer)
{
	buffer[0] = 0x21F1;
	buffer[1] = 0x21F1;
	buffer[2] = 0x5E0E;
	buffer[3] = 0x5E0E;
	return 1;
}
