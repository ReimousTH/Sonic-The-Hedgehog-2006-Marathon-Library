#ifndef SONICTEAM__CSDRESOURCE
#define SONICTEAM__CSDRESOURCE
#include "Defs.h"


#include <Sox/Memory/IDestructible.h>
#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>


struct CSDFile{

};



namespace Sonicteam{



	//Or SonicTeamSoxComponent
	class CsdResouce:public Sonicteam::SoX::IResource
		{
		public:
			CsdResouce(void);
			~CsdResouce(void);

			CSDFile* CSDFile; // :)



	
			DESTRUCTION_H; //0x0 + 0x10



	};

};

#endif