




#ifndef Sonicteam_Prop_GenerateArea
#define Sonicteam_Prop_GenerateArea

#include "PropClass.h"
#include "Manager.h"

#include <xtl.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <boost/shared_ptr.hpp>
#include <Sox/RefCountObject.h>


namespace Sonicteam { namespace Prop {


	class Manager;
	//0x4C
	class GenerateArea:Sonicteam::SoX::RefCountObject{
		Sonicteam::Prop::Manager* PropManager; //0x8
		unsigned int unk0xC;
		float posX1; //pos-x //0x10
		float posY1; //pos-y //0x14
		float posZ1; //pos-z //0x18
		float unk0x1C; //timer???

		float posX2; //pos-x //0x20
		float posY2; //pos-y //0x24
		float posZ2; //pos-z //0x28
		float unk0x2C; //timer???

		float unk0x30; // 0
		float unk0x34; // 0
		float unk0x38; // 0
		float unk0x3C; // 1 usualy

		//either XMFLOAT, or no idea

		XMFLOAT4 AreaRank;  // (Width/Height/Depth) //0x40


		LinkSoxNode<GenerateArea> LinkArea;
		unsigned int unk0x5C;

		float rotX; //0x60
		float rotY; //0x64
		float rotZ; //0x68
		float rotW; //0x6C



		float posX3; //pos-x //0x70
		float posY3; //pos-y //0x74
		float posZ3; //pos-z //0x78
		float unk0x7C; //timer??? //0x7C

		unsigned int unk0x80; //Flag1
		unsigned int unk0x84; // 0x84
		unsigned int unk0x88; // 0x88
		unsigned int unk0x8C; // 0x8C	




		GenerateArea();
		~GenerateArea();
		virtual void DestroyObject(unsigned int flag);
	};

}}

#define Sonicteam_Prop_GenerateArea
#endif


