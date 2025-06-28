#include "Listener.h"
using namespace Sonicteam::SoX::Input;
DESTRUCTION_CPP(Listener);


Listener::Listener(void)
{
	this->LinkInput.InitLink();
	this->LinkInput._this= this;
	this->flag0x10 = 1;
	this->flag0x11 = 0;

}

Listener::~Listener(void)
{
	LinkInput.SafeDisconnect();
}
