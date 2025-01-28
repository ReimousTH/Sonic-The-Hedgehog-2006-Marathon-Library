


#ifndef Sonicteam_Prop_ClassRegistry
#define Sonicteam_Prop_ClassRegistry

#include "PropClass.h"
#include "Class.h"
#include <Sox/RefCountObject.h>
#include <xtl.h>
#include <map>


namespace Sonicteam { namespace Prop {





	

	class ClassRegistry{
	public:

		std::map<std::string,Sonicteam::Prop::Class*> _registry_;

		ClassRegistry();
		~ClassRegistry();
	


	};


}};

#endif

