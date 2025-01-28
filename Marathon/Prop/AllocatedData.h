

#ifndef Sonicteam_Prop_AllocatedData
#define Sonicteam_Prop_AllocatedData


#include "PropClass.h"
#include <Sox/RefCountObject.h>
#include <xtl.h>

namespace Sonicteam { namespace Prop {






	

	class AllocatedData:public Sonicteam::SoX::RefCountObject{

		AllocatedData();
		~AllocatedData();
		virtual void DestroyObject(unsigned int flag) override;


		void* PlacementSetFile;
		size_t PlacementSetFileSize;


	};


}};

#endif

