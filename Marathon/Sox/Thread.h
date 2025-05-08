#pragma once

#include <xtl.h>
#include <string>
#include <list>




#include <deque>
#include "Perfomance.h"


#include <bitset>
//#include <cstdint>
#include <iostream>


#include "Sox/Misc/List.h"
#include <SoX/Memory/IDestructible.h>
#include <Sox/Memory/DEFINITIONS.hpp>

#include <Sox/Memory/Destruction.h>
#include <Sox/Misc/LinkSoxNode.h>



namespace Sonicteam{
	namespace SoX{


	


		
		class Thread {
        public:
			LinkSoxNode<Thread> LinkNode;
            HANDLE StartEvent; //0x10
            HANDLE EndEvent; //0x14
            LPDWORD m_ThreadID;        //0x18 // ThreadID
            HANDLE m_ThreadHandle;  // 0x1C   Assuming HANDLE is used for thread identifier
			
			char IsExecutable; //0x20
			char ThreadFlag2; //0x21
			char ThreadFlag3; //0x22
			char ThreadFlag4; //0x23

			float ThreadDelta; //Performance //0x24
			int m_Field4; //0x28
			DWORD TPerfScale; //0x2c Perfomance scale * 0.00001 = delta time
			const char* m_ThreadName;
			int StepElapsedTime ; //0x34
	
			char ThreadFlag5;//0x38
			char UseEvent; //0x39
			char ThreadFlag7; //0x3A
			char ThreadFlag8; //0x3B

			unsigned int ThreadFrame; //0x3C
			
			

        public:
            Thread(const char* ThreadName,int Procc,int EventFlag);


			DESTRUCTION_H;
			virtual void ThreadPerfomance();
			virtual void ThreadExecutor();
			virtual void ThreadStep(double delta);

			void Join();
			void Resume();




 
            ~Thread();


			/*

			static const int Constructor = 42; // This is allowed
			static Thread* Create(const char* a1,const char* a2){

				Thread* _MEM_  = (Thread*)malloc(sizeof(Thread));
				//should call function(with my args) OMG
				__asm{
					mr r12,Constructor
					mtctr r12
					bctrl
				}
				
				return _MEM_;
			}*/

			_MARATHON_DEFINE_CONSTRUCTOR_(Thread,0x825867A8,const char* ThreadName,int Priority,int Flag);


		

//			_MARATHON_DEFINE_CONSTRUCTOR_(Thread,BASE1,const char*);

			
			//((Thread** (__fastcall *)(...))0x8200)(const char*);

		
			//_DEFINE_MARATHON_CLASS_CONSTRUCTOR_(C1);




	

  
		};



	//	_DEFINE_MARATHON_CLASS_CONSTRUCTOR_OFFSET(Thread, C1, 0x825867A8);



	};
};