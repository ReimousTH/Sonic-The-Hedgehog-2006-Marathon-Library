#include "Class.h"

using namespace Sonicteam::Prop;

DESTRUCTION_CPP(Class);


Sonicteam::Prop::Class::~Class()
{

}

Sonicteam::Prop::Class::Class(ClassPropParamData* ClassPropData,REF_TYPE(Sonicteam::Prop::AllocatedData) ClassPropAllocatedData):
ClassPropData(ClassPropData),
ClassPropAllocatedData(ClassPropAllocatedData)
{

}
