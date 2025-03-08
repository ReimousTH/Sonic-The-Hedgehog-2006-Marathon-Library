#ifndef SONICTEAM__CSDOBJECT
#define SONICTEAM__CSDOBJECT
#include "Defs.h"


#include <Sox/Memory/IDestructible.h>
#include <Sox/RefCountObject.h>
#include <CsdLink.h>
#include <Chao/CSD/CProject.h>
#include <CsdResource.h>


namespace Sonicteam{



	//Or SonicTeamSoxComponent
	class CsdObject:public Sonicteam::SoX::RefCountObject,public Sonicteam::CsdLink
		{
		public:
			CsdObject(void);
			~CsdObject(void);


		public:

	
			DESTRUCTION_H; //0x0 + 0x10

			virtual void CsdObject0x4(unsigned int);

			virtual void CsdLink0x4();
			virtual void CsdLink0x8(double);


		//CUSTOM ONE
			void MarathonPlaySceneAnimation(const char* Scene_Name,const char* Animation_Name);
			void MarathonStopSceneAnimation(const char* Scene_Name,const char* Animation_Name);

			void MarathonPlaySceneLoopAnimation(const char* Scene_Name,const char* Animation_Name);
			void MarathonStopSceneLoopAnimation(const char* Scene_Name);


			void MarathonSetSceneNodeText(const char* Scene_Name,const char* Node_Name,const char* value);
			void MarathonSetSceneNodeSpriteIndex(const char* Scene_Name,const char* Node_Name,int index);

			void SetFlag0x20(int);




			unsigned int FCsdObject0x20; //count?
			Chao::CSD::CProject* FCProject;// 0x24
			REF_TYPE(Sonicteam::CsdResouce) CsdResouce; //0x28




	};

};

#endif