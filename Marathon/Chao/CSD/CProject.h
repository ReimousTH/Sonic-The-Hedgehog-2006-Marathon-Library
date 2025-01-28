#pragma once

#include <xtl.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Memory/DEFINITIONS.hpp>

#include <string>
#include "Project.h"
#include "RCObject.h"
#include "CResourceBase.h"






#include <xtree>





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


			SceneHead FCProject0x10; //HEAD 
		//	unsigned int FCProject0x10;
		//	unsigned int FCProject0x14;
		//	unsigned int FCProject0x18;

			SceneHead FCProject0x1C; //HEAD
			//unsigned int FCProject0x1C;
			//unsigned int FCProject0x20;
			//unsigned int FCProject0x24;


			unsigned int FCProject0x28;

			// RCPtr<TexList>, later
			RCObject<unsigned char> CPTexList;
			//
			unsigned int FCProject0x30;
			unsigned int FCProject0x34;
			unsigned int FCProject0x38;
			unsigned int FCProject0x3C;
			unsigned int FCProject0x40;
			unsigned int FCProject0x44;
		

	};
};
};