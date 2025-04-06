#ifndef CHAOS__CSD__CSCENEOBSERVER
#define CHAOS__CSD__CSCENEOBSERVER


#include <Chao/CSD/Defs.h>
//#include <Chao/CSD/CScene.h>
#include <Chao/CSD/CObserverBase.h>
#include <map>


#define CSCENE_OBSERVER_LIST_RC_TYPE(size_t,Type) std::map<size_t,Chao::CSD::RCObject<Type>*>


namespace Chao{
	namespace CSD{

	

		class CSceneObserver:Chao::CSD::CObserverBase<Chao::CSD::CScene>
		{
		public:
			CSceneObserver();
			~CSceneObserver();
			CMADestuctionHPP(CSceneObserver); 

			virtual void SyncScene1(Chao::CSD::CScene*); //index-1 +0x14
			virtual void SyncScene2(Chao::CSD::CScene*); //index-2 +0x18
			virtual void CSceneObserverimp3(); // ?
			virtual void CSceneObserverimp4(); // ?
			virtual void CSceneObserverimp5(); //?
			virtual void CSceneObserverimp6(); //?


			CSCENE_OBSERVER_LIST_RC_TYPE(size_t,unsigned char) CSOx4; //4-8-C




		};
	};
};
#endif
