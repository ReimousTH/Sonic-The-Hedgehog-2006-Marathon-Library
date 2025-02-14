#include "MessageReceiver.h"


using namespace Sonicteam::SoX;


MessageReceiver::MessageReceiver(void)
{

}



MessageReceiver::~MessageReceiver(void)
{

}

DESTRUCTION_CPP(MessageReceiver);

//Message

Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1)
{
	this->SetValueAt(0,data1);
}

Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2)
{
	this->SetValueAt(0,data1);
	this->SetValueAt(4,data2);
}


Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3)
{
	this->SetValueAt(0,data1);
	this->SetValueAt(4,data2);
	this->SetValueAt(8,data3);
}

Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3,unsigned int data4)
{
	this->SetValueAt(0,data1);
	this->SetValueAt(4,data2);
	this->SetValueAt(8,data3);
	this->SetValueAt(12,data4);
}



Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3,unsigned int data4,unsigned int data5)
{
	this->SetValueAt(0,data1);
	this->SetValueAt(4,data2);
	this->SetValueAt(8,data3);
	this->SetValueAt(12,data4);
	this->SetValueAt(16,data5);
}



