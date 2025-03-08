#include "AcroartsPostLoad.h"
using namespace Sonicteam::Spanverse;





AcroartsPostLoad::AcroartsPostLoad()
{

}

AcroartsPostLoad::~AcroartsPostLoad()
{

}



DESTRUCTION_CPP(AcroartsPostLoad,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);
