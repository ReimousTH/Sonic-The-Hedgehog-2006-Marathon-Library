


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

		const char* ObjectName; //0
		const char* ObjectTypeName; //4


		char ObjectUnkFloatArray[3]; // 40 00 00 //8
		char StartInactive; //B

		float ObjectUnkFloat2; //=0 //C
		float ObjectUnkFloat3; //=0 //10
		float ObjectUnkFloat4; //=0 //14
		XMFLOAT3 Position; //18
		float DrawDistance; //40000 //0x24
		XMFLOAT4 Rotation; //0x28 (HOW It bypass aligment HOW?)

		unsigned int ParamsCount;
		InstanceSetDataParams* Params;

		InstanceSetData(const char* ObjectName,const char* ObjectTypeName,XMVECTOR Position,XMVECTOR Rotation);
		~InstanceSetData();
	};




	class Instance:public Sonicteam::Prop::SceneObject{


	public:
		Instance(Sonicteam::Prop::Scene* InstancePropScene,Sonicteam::Prop::InstanceSetData* PropInstanceSetData,REF_TYPE(Sonicteam::Prop::Class) PropClass);
		~Instance();

		DESTRUCTION_H override;

		Sonicteam::Prop::InstanceSetData* InstanceSetData;
		REF_TYPE(Sonicteam::Prop::Class) InstanceClass;

	};

}}


#endif


