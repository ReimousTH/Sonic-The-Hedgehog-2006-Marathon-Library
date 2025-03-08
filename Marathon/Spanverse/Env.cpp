#include "Env.h"
using namespace Sonicteam::Spanverse;



Env::Env():SpanSPSB(0,0)
{

}
Env::~Env()
{

}


DESTRUCTION_CPP(Env,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);





