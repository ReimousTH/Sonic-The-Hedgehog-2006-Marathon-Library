#ifndef SONICTEAM__SCENETIMELIGHT
#define SONICTEAM__SCENETIMELIGHT



#include <vector>

#include <System/Singleton.h>
#include <System/CreateStatic.h>


namespace Sonicteam{



	struct SSLVECTOR{
		float x;
		float y;
		float z;
		float a;
	};
	struct SSLCOLOR:SSLVECTOR{
	};

	struct SceneTimeLightTable{
	public:

		SceneTimeLightTable();
		~SceneTimeLightTable();
		float Time;
		SSLCOLOR SunColor;
		SSLCOLOR AmbientColor;
		SSLCOLOR LightColor0;
		SSLCOLOR LightColor1;
		SSLVECTOR BRay;
		SSLVECTOR BMie;
		float G;
		float Bloom_MinThr;
		float Bloom_MaxThr;
		float Bloom_Scale;

	};


	
	
	class SceneTimeLight:public SSINGLETON(SceneTimeLight){

	public:
		SceneTimeLight();
		~SceneTimeLight();

		std::vector<SceneTimeLightTable> TLTable; // 0
		std::string TLFile; // wvo_table.lua //0x10
	
	};

};





#endif