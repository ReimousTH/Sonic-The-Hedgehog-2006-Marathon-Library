#ifndef CHAOS__CSD__SCENE
#define CHAOS__CSD__SCENE


#include <Chao/CSD/Defs.h>
#include <utility>
#include <string>
#include <Chao/Misc/utill.hpp>
#include <Chao/Misc/Aligment.hpp>

namespace Chao{



	namespace CSD{


		struct Family{

		};


		//?

		#pragma pack(push, 1) 
		struct Scene
		{
		public:
			Scene();
			~Scene();

			//from sharpneedle
			unsigned int Version; //0
			float Priority ; //4
			float AnimationFramerate; //8
			unsigned int AnimationFramerateStart; //C
			unsigned int AnimationFramerateEnd; //10
			Chao::CCArray32<Chao::CVector2> _Texture; //14-18
			Chao::CCArray64<Chao::CSprite> _Sprite; //1C-20 (1C-20-24-28)
			Chao::CCArray64<Chao::CSD::Family> _Family; //2C-30-34-38
			Chao::CCArray64<Chao::CastInfo> _CastInfo; //3C-40-44-48
			Chao::CDictionary64<Chao::Motion> _Motion; //4C-50-54-58-5C-60
			char _padding_[12];
			Chao::CArray64<std::pair<float,float>> _FrameInfo;  //70-74


			size_t GetMotionIndexFromName(const char* animation);

		};
		 #pragma pack(pop) 
	};
};
#endif
