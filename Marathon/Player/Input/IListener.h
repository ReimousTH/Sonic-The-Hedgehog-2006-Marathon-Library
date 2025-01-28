#pragma once


#include "../../Sox/Object.h"
#include <xtl.h>

#define SO_GAMEPAD_RAW_BUTTON_A 1
#define SO_GAMEPAD_RAW_BUTTON_B 2
#define SO_GAMEPAD_RAW_BUTTON_X 8
#define SO_GAMEPAD_RAW_BUTTON_Y 0x10

#define SO_GAMEPAD_RAW_BUTTON_DPAD_UP 0x40
#define SO_GAMEPAD_RAW_BUTTON_DPAD_DOWN 0x80
#define SO_GAMEPAD_RAW_BUTTON_DPAD_LEFT 0x100
#define SO_GAMEPAD_RAW_BUTTON_DPAD_RIGHT 0x200

namespace Sonicteam{
	namespace Player{



		namespace Input{
			//Root Scroll Node
			struct IListenerInputStruc01{
				unsigned int unk00; //0x0
				Sonicteam::SoX::Object* PtrMyInputObj; //0xx4
				Sonicteam::SoX::Object* PtrKhronoControlInputListener; //0x8
				unsigned int unk0xC; //0xC
				unsigned int wLastButtons; //Triggers & DPAD includ //0x10 :
				unsigned int ComplementwLastButtons; //Binary One's Complement (in short = ~wLastButtons) //0x14

				unsigned int unk18;
				unsigned int unk1C;
				
				// Thumb stick values converted to range [-1,+1]
				FLOAT      fX1;
				FLOAT      fY1;
				unsigned int fX1Y1Unk; // (0-2 Left,2-4 Right) fx1(y1) > 0   =  0x8001 , fx1(y1) < 0 = -0x8001 

				// Thumb stick values converted to range [-1,+1]
				FLOAT      fX2;
				FLOAT      fY2;
				unsigned int fX2Y2Unk; // (0-2 Left,2-4 Right) fx2(y2) > 0   =  0x8001 , fx2(y2) < 0 = -0x8001
				//Next is Unk and not sure 
			};
			struct IListenerInputStruc02{

				float float0;
				unsigned int dword4;
				char byte8;
				char byte9;
				char byteA;
				char byteB;
				float c_dclick_time;

				IListenerInputStruc02(){

				}
				IListenerInputStruc02(int a1,float a2){
					this->float0 = 0.0;
					this->dword4 = a1;
					this->c_dclick_time = a2;
					this->byte8 = 0;
					this->byte9 = 0;
					this->byteA = 0;
					this->byteB = 0;


				}


			};
			struct IListenerInputStruc03{

				unsigned int dword0;
				char byte4;
				char byte5;
				char byte6;
				char gap7;
				float float8;
				float c_lclick_time;
				//_BYTE byte10;
				unsigned int byte10; //  or maybe byte just aligned to 4

				IListenerInputStruc03(){

				}
				IListenerInputStruc03(int a1){
					this->dword0 = a1;
					this->float8 = 0.0;
					this->c_lclick_time = 0.0;
					this->byte4 = 0;
					this->byte5 = 0;
					this->byte6 = 0;
					this->gap7 = 0;
					this->byte10 = 0;

				};
			};


			//size 0x18
			class IListener:Sonicteam::SoX::Object,Sonicteam::SoX::IOObject
			{
			public:
				IListener(void);
				~IListener(void);

				//virtual char* GetObjectType() override;
					
				

				virtual void ListenerOnUpdate(int,float) = 0;
				virtual XMFLOAT4* ListenerGetStickVector4() = 0;
				virtual float ListenerGetStickPower() = 0; // Stick power
				virtual unsigned int ListenerGetResult() = 0; // Result Input Action (Pressed Holded and etc)
				virtual int Listener5() = 0; //always 1

				byte IL0x10;
				byte IL0x11;
				byte IL0x12;
				byte IL0x13;
				unsigned int IL0x14; //-0x18

	
			};

		}
		
	}
}

