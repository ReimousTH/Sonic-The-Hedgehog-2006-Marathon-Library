#ifndef SONICTEAM__SOX__MESSAGE_RECEIVER
#define SONICTEAM__SOX__MESSAGE_RECEIVER
#include <Sox/Memory/Destruction.h>

#define SoXMessageType void*


namespace Sonicteam{
	namespace SoX{


		
		template <unsigned int T>
		struct MessageTemplate {
			char MessageData[T];
			MessageTemplate(){};
			MessageTemplate(unsigned int value){this->SetValueAt(0,0x1300C);};

			template <typename Y>
			inline void SetValueAt(unsigned int pos, const Y& Value) {
				*reinterpret_cast<Y*>(&MessageData[pos]) = Value; // 
			}
			template <typename Y>
			inline Y GetValueAt(unsigned int pos) const {
				return *(Y*)(&MessageData[pos]); //
			}
			template <typename Y>
			inline Y* GetValueAtRef(unsigned int pos) const {
				return (Y*)(&MessageData[pos]); //
			}

		};

		struct Message : MessageTemplate<28> {
			Message() {}

			Message(unsigned int messageID);

			Message(unsigned int messageID, unsigned int data1);

			Message(unsigned int messageID, unsigned int data1, unsigned int data2);

			Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3);

			Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3,unsigned int data4);
			Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3,unsigned int data4,unsigned int data5);

		};




		class MessageReceiver
		{
		public:
			MessageReceiver(void);
			~MessageReceiver(void);

			DESTRUCTION_H
			virtual int OnMessageRecieved(SoXMessageType) = 0;
		};
	};
};

#endif
