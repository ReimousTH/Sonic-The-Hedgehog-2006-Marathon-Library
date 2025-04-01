#ifndef CHAOS__CSD__CSCENE
#define CHAOS__CSD__CSCENE


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CResourceBase.h>
#include <Chao/CSD/SubjectBase.h>
#include <Chao/CSD/Scene.h>
#include <Chao/CSD/CSceneObserver.h>





namespace Chao{



	namespace CSD{




	
	
		class CScene:Chao::CSD::CResourceBase<Chao::CSD::Scene>,Chao::CSD::SubjectBase<Chao::CSD::CSceneObserver,Chao::CSD::CScene>
		{
		public:
			CScene(void);
			~CScene(void);

		public:
			CMADestuctionHPP(CScene);


		




			//0x90 (anim -flag ?) play 


		};
	};
};
#endif
