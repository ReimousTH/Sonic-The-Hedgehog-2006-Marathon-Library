


#ifndef Sonicteam_Prop_Instance
#define Sonicteam_Prop_Instance


#include "PropClass.h"
#include "SceneObject.h"
#include "Class.h"
#include <xtl.h>


namespace Sonicteam { namespace Prop {





	//from DebugLogV2  (0x14 - size)
	struct InstanceSetDataParams{
	public:
		int Type;
		__declspec(align(1)) union InstanceSetDataParamsTypeValue {
			unsigned int _bool_;          // 0
			int _int32_;          // 1
			float _single_;       // 2
			const char* _string_; // 3
			char _vector_[0x10];    // 4 (Vector-will be unstable)
			int _u5_;             // 5
			int _u6_;             // 6
		} Value;

		void SetTValue(bool value);
		void SetTValue(int value);
		void SetTValue(float value);
		void SetTValue(const char* value);
		void SetTValue(XMVECTOR value);

		~InstanceSetDataParams();

	
		//Getters, no template or .inl :)


	};


	struct InstanceSetData{

		const char* ObjectName;
		const char* ObjectTypeName;


		char ObjectUnkFloatArray[3]; // 40 00 00
		char StartInactive; //0

		float ObjectUnkFloat2; //=0
		float ObjectUnkFloat3; //=0
		float ObjectUnkFloat4; //=0
		XMFLOAT3 Position;
		float ObjectUnkFloat5; //40000
		XMFLOAT4 Rotation;

		unsigned int ParamsCount;
		InstanceSetDataParams* Params;

		InstanceSetData(const char* ObjectName,const char* ObjectTypeName,XMVECTOR Position,XMVECTOR Rotation);
		~InstanceSetData();
	};




	class Instance:public Sonicteam::Prop::SceneObject{


	public:
		Instance();
		~Instance();

		virtual void DestroyObject(unsigned int flag) override;

		Sonicteam::Prop::InstanceSetData* InstanceSetData;
		REF_TYPE(Sonicteam::Prop::Class) InstanceClass;



	};

}}


#endif


