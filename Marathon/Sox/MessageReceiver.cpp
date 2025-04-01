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
	this->SetValueAt(0,messageID);
	this->SetValueAt(4,data1);
}

Message::Message(unsigned int messageID)
{
	this->SetValueAt(0,messageID);
}

Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2)
{
	this->SetValueAt(0,messageID);
	this->SetValueAt(4,data1);
	this->SetValueAt(8,data2);
}


Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3)
{
	this->SetValueAt(0,messageID);
	this->SetValueAt(4,data1);
	this->SetValueAt(8,data2);
	this->SetValueAt(0xC,data3);
}

Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3,unsigned int data4)
{
	this->SetValueAt(0,messageID);
	this->SetValueAt(4,data1);
	this->SetValueAt(8,data2);
	this->SetValueAt(0xC,data3);
	this->SetValueAt(0x10,data4);
}



Sonicteam::SoX::Message::Message(unsigned int messageID, unsigned int data1, unsigned int data2,unsigned int data3,unsigned int data4,unsigned int data5)
{
	this->SetValueAt(0,messageID);
	this->SetValueAt(4,data1);
	this->SetValueAt(8,data2);
	this->SetValueAt(0xC,data3);
	this->SetValueAt(0x10,data4);
	this->SetValueAt(0x14,data5);
}



