#ifndef CHAOS__CSD__CSCENE
#define CHAOS__CSD__CSCENE


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CResourceBase.h>
#include <Chao/CSD/SubjectBase.h>
#include <Chao/CSD/Scene.h>
#include <Chao/CSD/CSceneObserver.h>
#include <Chao/CSD/Manager/csdmProject.h>
#include <Chao/CSD/CBase.h>
#include <Chao/CSD/CProject.h>
#include <Chao/CSD/Manager/csdmProject.h>

#include <Chao/CSD/CTransform_1.h>
#include <Chao/CSD/CTransform_2.h>
#include <Chao/CSD/CTransform_3.h>


#include <map>










#define CSCENE_DEFAULT_LIST_RC_TYPE(size_t,Type) std::list<RCOBJREF(Type)>
namespace Chao{



	namespace CSD{





		struct CSceneMotionProject{
			Chao::CSD::Manager::csdmProject First;
//			Chao::CSD::Manager::csdmNodeBase Second; //0x20 (CTransform_1 also weird but how is it :))
		};


	
		class CScene:public Chao::CSD::CResourceBase<Chao::CSD::Scene>,public Chao::CSD::SubjectBase<Chao::CSD::CSceneObserver,Chao::CSD::CScene>,public Chao::CSD::CBase
		{
		public:
			CScene(void);
			~CScene(void);

		public:
			CMADestuctionHPP(CScene);

			virtual void OnUpdateFirst(double);
			virtual void OnUpdateSecond(size_t);


			//Either std::map / std::list (size should be 0xC no idea)
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap01; // 0x20-0x24-0x28
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap02; // 0x2C-0x30-0x34
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap03; // 0x38-0x3c-0x40
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap04; // 0x44-0x48-0x4C
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap05; // 0x50-0x54-0x58
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap06; // 0x5C-0x60-0x64


			//test
			Chao::CSD::CTransform_1* CSMotionData; //0x68 (For Animation) (class new later:)) (825CB034-> where used to )
			Chao::CSD::CTransform_2* CMTransform2; //0x6C
			Chao::CSD::CTransform_3* CMTransform3; //0x70


			//(Continue INitialzation 825C9E38 )
			float MotionKeyFramePre; //0x74
			float MotionKeyFramePost; //0x78 
			float MotionKeyFrameRate; // 1.0 = default 0x7C

			float MotionKeyFrameStart; //0x80
			float MotionKeyFrameEnd; //0x84

			RCOBJREF(unsigned char) RC0x88;
			RCOBJREF(unsigned char) RC0x8C;
			size_t IsMotionEnd; //0x90
			Chao::CSD::CSceneObserver CSCObserver; //CSceneMotionRepeat (later) 0x94

			size_t CCSFlag1; //a4
			size_t MotionRepeatMode; //a8 (0-no repeat, 1 - repeat, 2 - reverse animation, 3 - remove after)
			size_t CCSFlag3; //aC
			size_t MotionIndex; //B0 (
			float CCSFlag6; //Out-Time??? 0xB4
			std::map<size_t,RCOBJREF64(Chao::CSD::CNode)> CNodeMap; //0xB8-0xBC-0xC0  (CNode)
			const char* CSName; //SceneName 0xC4
			size_t CSS0xC8;

			Chao::CSD::CProject* CSCProject; //0xCC
			CSceneMotionProject* CSPMotion; //0xD0



		};
	};
};
#endif
