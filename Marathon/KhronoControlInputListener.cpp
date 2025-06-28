#include "KhronoControlInputListener.h"
using namespace Sonicteam;





KhronoControlInputListener::KhronoControlInputListener(KhronoControlInputListenerBFUNC func):Listener()
{
	this->func0x18 = func;

}

KhronoControlInputListener::~KhronoControlInputListener()
{

}



void KhronoControlInputListener::UpdateListener(SOXLISTENER_ARGS)
{
	
}
DESTRUCTION_CPP(KhronoControlInputListener);