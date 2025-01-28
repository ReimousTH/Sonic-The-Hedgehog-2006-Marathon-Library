#pragma once

#include "IPlugIn.h"
#include "IVariable.h"
#include "IStepable/IStepable.h"
#include "IScore.h"
#include <xtl.h> //replace to xbox math soon


namespace Sonicteam{
	namespace Player{

		
		class Score:IScore
		{
		public:
			Score(int*,int*,int,int*);
			~Score(void);
		
			




			///Fields

			int RingsCount; //0x28
			int ScoreCount; //0x2C ????? (Rings PR Count)

			int PtrRootFrame; //0x30
			int PtrObjectPlayer; //0x34

			int unk0x38; // 0x38
			int unk0x3C; // 0x3C

			XMFLOAT4 unkvector; //0x40

			int PtrGameImpulse; //0x50
			int PtrPackageBinary; //0x54

			int unkfield0x58;
			int unkfield0x5C;
			int unkfield0x60;

			int unkfield0x64;
			int unkfield0x68;
			int unkfield0x6C;




			///vfttable
			virtual void AddRings(int);
			virtual void TakeDamage(void);
			virtual void TakeDamageOld();
			virtual void TakeDamageLittle();
			virtual int GetRings();
			virtual void SetRings(int);
			virtual void SetUnknownVector(XMFLOAT4*); //or just XMFLOAT4


			virtual void OnVarible(void);
			virtual void OnStepable(float);

		};

	}
}

