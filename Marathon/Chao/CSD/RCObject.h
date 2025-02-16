#pragma once

#include <xtl.h>
#include <CMemoryAllocMarathon.h>


//MB
#define CSEITEM_TYPE_NONE		0
#define CSEITEM_TYPE_FOLDER		1
#define CSEITEM_TYPE_SCENE		2
#define CSEITEM_TYPE_FACE		3
#define CSEITEM_TYPE_CASTNODE	4


namespace Chao{
	namespace CSD{


	 
	//??????????
	template <typename CType>
	class RCObject
		{
		public:
			RCObject(void);
			~RCObject(void);


		public:
			virtual void DestroyObject(unsigned int flag); 
			CType* get();

		protected:
			CType* CObject;
			size_t RefCount;
			unsigned int unk0xC;
			unsigned int CSE_TYPE;	



	};

	template <typename CType>
	CType* Chao::CSD::RCObject<CType>::get()
	{
		return this->CObject;

	}

	template <typename CType>
	void Chao::CSD::RCObject<CType>::DestroyObject(unsigned int flag)
	{
		if ( (flag & 1) != 0){
			Sonicteam::CMemoryAllocMarathon::GetInstance()->FFreeMemoryA((void*)this);
		}
	}

	template <typename CType>
	Chao::CSD::RCObject<CType>::~RCObject(void)
	{

	}

	template <typename CType>
	Chao::CSD::RCObject<CType>::RCObject(void)
	{

	}

	};
};