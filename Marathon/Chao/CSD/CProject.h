#pragma once

#include <xtl.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Memory/DEFINITIONS.hpp>

#include <Sox/Misc/MapExtension.h>

#include <string>
#include "Project.h"
#include "RCObject.h"
#include "CResourceBase.h"


#include <Chao/CSD/CScene.h>
#include <Chao/CSD/RCObject.h>




#include <map>


namespace Chao{
	namespace CSD{

		//BRUH 
		//I GUESS LinkedNodeList :(
		//maybe some kind of List , Scene poiners to ,1,2,3 if nothing then all == or no idea but pointers 
		// DO NOT EXIST IN GAME
		struct SceneInfo:Sonicteam::SoX::LinkNode<SceneInfo>{
			const char* NodeName;
			const char* NodePTR;
		};

		struct SceneHead{
			SceneInfo* Elements;
			unsigned int ECount;
			unsigned int EUnk0xC;
		};




		
	//No INFO so empty
		class CProject:Chao::CSD::CResourceBase<Chao::CSD::Project>
		{
		public:
			CProject(void);
			~CProject(void);

			virtual void CResourceBase0x4(void*);

			//Scenes
			public:
			unsigned int FCProject0xC;


			// Chao::CSD::RCObject<Chao::CSD::CScene>
			std::map<const char*,Chao::CSD::RCObject<Chao::CSD::CScene>*,STD_MAP_CONST_CHAR_PTR_COMPARATOR> CProjectScene; //later
			std::map<void*,void*> CProjectMap0x1C; //later


			unsigned int FCProject0x28;

			// RCPtr<TexList>, later
			RCObject<unsigned char> CPTexList; //0x2C
			//
			unsigned int FCProject0x30;
			unsigned int FCProject0x34;// ?
			unsigned int FCProject0x38;
			unsigned int FCProject0x3C;
			unsigned int FCProject0x40; // ?
			unsigned int FCProject0x44; 
		

	};
};
};