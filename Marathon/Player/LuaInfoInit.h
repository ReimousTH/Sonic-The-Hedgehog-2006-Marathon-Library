#ifndef SONICTEAM__PLAYER__LUAINFOINIT
#define SONICTEAM__PLAYER__LUAINFOINIT

#include <list>
#include <Sox/Misc/Array.h>

namespace Sonicteam{
	namespace Player{

		struct AnimIDMap;
		struct UACSATIndexTable;


	


		struct AnimIDMap{
			size_t ID;
			int param1;
			int extra;
			float param2; //15.0
			float param3; // 15.0
			size_t TargetID;	 //enum la
			float param4; // == NAN
		};
		struct UACSATIndexTable{
			char buffer[9]; // no idea
		};

	
		
		struct SPlayerAnimationTable {
			ArrayPtr<const char*> Animation;
			AIMArray<AnimIDMap> AnimationMAP;
			ArrayPtr<const char*> AnimationHead;
			AIMArray<AnimIDMap> AnimationHeadMAP;
			ArrayPtr<UACSATIndexTable> IndexTable;

			
			SPlayerAnimationTable(
				const char** anim, int animSize,
				const char** head, int headSize,
				UACSATIndexTable* idxTable, int idxSize);
		};




		extern SPlayerAnimationTable PlayerAnimTable[];  // Declaration of the array


	

		
	}
}

#endif