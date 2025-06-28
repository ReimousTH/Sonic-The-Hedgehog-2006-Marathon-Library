#ifndef SONICTEAM__SCENEKHRONOSPARAM
#define SONICTEAM__SCENEKHRONOSPARAM


#include <ISceneParam.h>

namespace Sonicteam{




	class SceneKhronosParam:public Sonicteam::ISceneParam{
	public:
		SceneKhronosParam();
		~SceneKhronosParam();

		float khrono_prm_time; //14
		float khrono_prm_normalized_time; //18
		float unk0x1C;
		float unk0x20;


		DESTRUCTION_H;
		virtual const char* GetParamName();

	};

};





#endif