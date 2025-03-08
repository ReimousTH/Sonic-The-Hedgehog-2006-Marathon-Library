#ifndef SONICTEAM__PACKAGEBINARY
#define SONICTEAM__PACKAGEBINARY


#include <Sox/IResource.h>
#include <vector>

namespace Sonicteam{


	//or BBINA, no idea what they do
	struct PackageData{
		unsigned int unk0x0;
		unsigned int unk0x4;
		unsigned int unk0x8;
		unsigned int unk0xC;
		unsigned int unk0x10;
		void* unk0x14; 
		void* unk0x18;
		void* unk0x1C;
		void* unk0x20;
		void* unk0x24;
	};


	class PackageBinary:public Sonicteam::SoX::IResource{
	public:
		PackageBinary();
		~PackageBinary();
		PackageData* PackageData; //0x64
		void* PackageFile;  //0x68
		//weird, does not get released in desturcotr, weird :|
		std::vector<REF_TYPE(Sonicteam::SoX::IResource)> PackageArcHandle; //0x6C
		DESTRUCTION_H;
	};

};





#endif