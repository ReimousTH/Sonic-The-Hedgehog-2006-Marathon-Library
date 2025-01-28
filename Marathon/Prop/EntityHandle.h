#pragma once


#include "PropClass.h"
#include "Scene.h"
#include "Instance.h"
#include <xtl.h>
#include <Sox/RefCountObject.h>



namespace Sonicteam { namespace Prop {




	class EntityHandle:public Sonicteam::SoX::RefCountObject{ 
	public:
		Sonicteam::Prop::Scene* PropScene; //0x8
		unsigned int ID; //0xC
		unsigned int unk0x10; //0x10
		unsigned int unk0x14; //0x14
		REF_TYPE(Sonicteam::Prop::Instance) PropInstance;
		virtual void DestroyObject(unsigned int flag) override;

	};


}};