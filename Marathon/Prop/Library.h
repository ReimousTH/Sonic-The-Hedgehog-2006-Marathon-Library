


#ifndef Sonicteam_Prop_Library
#define Sonicteam_Prop_Library


#include "PropClass.h"
#include "AllocatedData.h"
#include "Class.h"
#include <map>
#include <string>
#include <vector>
#include <Sox/IResource.h>


namespace Sonicteam { namespace Prop {







	class Library:public Sonicteam::SoX::IResource{


	public:
		Library();
		~Library();

		std::map<std::string,int> LibraryPropIndex	; //.prop (index) //0x64
		void* PlacementFile; // right after bbina or name char*  //0x70
		REF_TYPE(Sonicteam::Prop::AllocatedData) LibraryAllocatedData; // look more if  //0x74
		std::vector<REF_TYPE(Sonicteam::Prop::Class)> LibraryPropClass;  //0x78
		//0x88


		virtual void DestroyObject(unsigned int flag) override;





	};

}}


#endif


