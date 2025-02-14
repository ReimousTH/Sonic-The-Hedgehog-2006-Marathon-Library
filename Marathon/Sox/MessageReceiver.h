#ifndef SONICTEAM__SOX__MESSAGE_RECEIVER
#define SONICTEAM__SOX__MESSAGE_RECEIVER
#include <Sox/Memory/Destruction.h>

#define SoXMessageType void*


namespace Sonicteam{
	namespace SoX{


		
		template <unsigned int T>
		struct MessageTemplate {
			unsigned int MessageID; // (just number)
			//since ,start from 0x4, padded struct :)
			char MessageData[T];
			MessageTemplate(){}
			MessageTemplate(unsigned int messageID) : MessageID(messageID) {}

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

		struct Message : MessageTemplate<20> {
			Message() {}

			Message(unsigned int messageID) : MessageTemplate<20>(messageID) {}

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
