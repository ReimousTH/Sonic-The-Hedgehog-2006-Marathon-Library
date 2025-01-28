#pragma once

#include <xtl.h>
#include <CMemoryAllocMarathon.h>





namespace Chao{
	namespace CSD{


	 
	//??????????
	class CScene
		{
		public:
			CScene(void);
			~CScene(void);




		public:
			virtual void DestroyObject(unsigned int flag); //0x0 + 0x10


	};
};
};