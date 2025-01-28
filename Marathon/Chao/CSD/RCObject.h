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
			virtual void DestroyObject(unsigned int flag); //0x0 + 0x10

		protected:
			CType* CObject;
			size_t RefCount;
			void* m_pDealloctor; //https://github.com/blueskythlikesclouds/BlueBlur/blob/master/CSD/Manager/csdmRCObject.h
			size_t m_eDealloctor; 
			unsigned int CSE_TYPE;	



	};

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