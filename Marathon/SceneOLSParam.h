#ifndef SONICTEAM__SCENEBLOOMPARAM
#define SONICTEAM__SCENEBLOOMPARAM


#include <ISceneParam.h>
#include <xtl.h>

namespace Sonicteam{




	class SceneOLSParam:public Sonicteam::ISceneParam{
	public:
		SceneOLSParam();
		~SceneOLSParam();

		float unk14; //14
		float unk18; //18
		float unk1C; //1C

		XMVECTOR SunColor; //0x20
		XMVECTOR BRay; //0x30
		XMVECTOR BMie; //0x40
		float G;
		//other to 0x60, seems just empty space or padding
	


		DESTRUCTION_H;
		virtual const char* GetParamName();

	};

};





#endif