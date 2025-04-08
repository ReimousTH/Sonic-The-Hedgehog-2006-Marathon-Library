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


#include <map>








#define CSCENE_DEFAULT_LIST_RC_TYPE(size_t,Type) std::list<RCOBJREF(Type)>
namespace Chao{



	namespace CSD{





		struct CSceneMotionProject{
			Chao::CSD::Manager::csdmProject First;
//			Chao::CSD::Manager::csdmNodeBase Second;
		};


	
		class CScene:public Chao::CSD::CResourceBase<Chao::CSD::Scene>,public Chao::CSD::SubjectBase<Chao::CSD::CSceneObserver,Chao::CSD::CScene>,public Chao::CSD::CBase
		{
		public:
			CScene(void);
			~CScene(void);

		public:
			CMADestuctionHPP(CScene);


			//Either std::map / std::list (size should be 0xC no idea)
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap01; // 0x20-0x24-0x28
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap02; // 0x2C-0x30-0x34
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap03; // 0x38-0x3c-0x40
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap04; // 0x44-0x48-0x4C
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap05; // 0x50-0x54-0x58
			CSCENE_DEFAULT_LIST_RC_TYPE(size_t,unsigned char) RCMap06; // 0x5C-0x60-0x64

			Chao::CSD::Manager::csdmProject* CMProject1; //0x68
			Chao::CSD::Manager::csdmProject* CMProject2; //0x6C
			Chao::CSD::Manager::csdmProject* CMProject3; //0x70

			float CKeyFramePre; //0x74
			float CKeyFramePost; //0x78 
			float CKeyFrameRate; // 1.0 = default 0x7C

			size_t CFrameStart; //0x80
			size_t CFrameEnd; //0x84

			RCOBJREF(unsigned char) RC0x88;
			RCOBJREF(unsigned char) RC0x8C;
			size_t IsMotionEnd;
			Chao::CSD::CSceneObserver CSCObserver; //CSceneMotionRepeat (later) 0x94

			size_t CCSFlag1; //a4
			size_t MotionRepeatMode; //a8 (0-no repeat, 1 - repeat, 2 - reverse animation, 3 - remove after)
			size_t CCSFlag3; //aC
			size_t MotionIndex; //B0 (
			float CCSFlag6; //Out-Time??? 0xB4
			std::map<size_t,RCOBJREF(unsigned char)> RCMap07; //0xB8-0xBC-0xC0
			const char* CSName; //SceneName 0xC4
			size_t CSS0xC8;

			Chao::CSD::CProject* CSCProject; //0xCC
			CSceneMotionProject* CSPMotion; //0xD0



		};
	};
};
#endif
