#ifndef SONICTEAM__PLAYER__INPUT_ILISTENER
#define SONICTEAM__PLAYER__INPUT_ILISTENER



#include <xtl.h>
#include <Sox/Input/Manager.h>
#include <Sox/Input/Listener.h>



namespace Sonicteam{
	namespace Player{



		namespace Input{
			//Root Scroll Node
		
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
			class IListener:Sonicteam::SoX::Input::Listener
			{
			public:
				IListener(void);
				~IListener(void);

				//virtual char* GetObjectType() override;
					
				DESTRUCTION_H;
				


				virtual void UpdateListener(SOXLISTENER_ARGS) = 0;
				virtual XMVECTOR* ListenerGetStickVector4(double delta,int flag) = 0;
				virtual float ListenerGetStickPower(unsigned long long flag = 0) = 0; // Stick power
				virtual unsigned int ListenerGetResult() = 0; // Result Input Action (Pressed Holded and etc)
				virtual int IsListenerEnabled() = 0; //always 1

			};

		};
		
	};
};

#endif