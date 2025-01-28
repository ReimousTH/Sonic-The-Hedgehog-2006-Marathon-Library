#pragma once

namespace Sonicteam{
	namespace SoX{
		
		struct Message{
			unsigned int MessageInfo; // (just number)
			unsigned int MessageInfo2; // send message back  (here example 82206070)
			unsigned int MessageInfo3; // send message back  (here example 82206070)

			unsigned int MessageInfo4; // send message back  (here example 82206070)
			unsigned int MessageInfo5; // send message back  (here example 82206070)
			unsigned int MessageInfo6; // send message back  (here example 82206070)
			Message(unsigned int a1,unsigned int a2,unsigned int a3){
				this->MessageInfo =a1;
				this->MessageInfo2 =a2;
				this->MessageInfo3 =a3;
			};
			Message(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4){
				
				this->MessageInfo =a1;
				this->MessageInfo2 =a2;
				this->MessageInfo3 =a3;
				this->MessageInfo4 =a4;
			}
			Message(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4,unsigned int a5){

				this->MessageInfo =a1;
				this->MessageInfo2 =a2;
				this->MessageInfo3 =a3;
				this->MessageInfo4 =a4;
				this->MessageInfo5 =a5;
			}
		
		

		};
		class MessageReceiver
		{
		public:
			MessageReceiver(void);
			~MessageReceiver(void);

			virtual void DestroyObject(unsigned int flag) ;
			virtual int OnMessageRecieved(Message*) = 0;
		};
	};
};