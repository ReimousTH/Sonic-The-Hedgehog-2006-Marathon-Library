#ifndef SONICTEAM__GE1PE__REFCOUNTOBJECT
#define SONICTEAM__GE1PE__REFCOUNTOBJECT

#include <Sox/Memory/Destruction.h>
#include <Sox/RefCountObject.h>



#define REF_TYPE_GE1PE(Type) Sonicteam::SoX::RefCountObjContainer<Type>


namespace Sonicteam{
	namespace GE1PE{


	
		//IT same as RefCountObject i think
		class RefCountObject:public Sonicteam::SoX::RefCountObject {
			DESTRUCTION_H;
		};

	


	}
}
#endif