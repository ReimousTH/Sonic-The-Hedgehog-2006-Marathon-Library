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





namespace Sonicteam{
	namespace SoX{


		template <typename T>
		struct ThreadLinkNode {
			ThreadLinkNode<T>* PThread;
			ThreadLinkNode<T>* NThread;
			T* TThread;

		public:
			ThreadLinkNode() : PThread(NULL), NThread(NULL), TThread(NULL) {}
			ThreadLinkNode(T* OBJ) : PThread(NULL), NThread(NULL), TThread(OBJ) {}

			void RemoveLink(){
				PThread->NThread = NThread;
				NThread->PThread = PThread;
				NThread = NULL;
				PThread = NULL;
	
			}

			~ThreadLinkNode() {
				if (PThread)
					PThread->NThread = NThread;
				if (NThread)
					NThread->PThread = PThread;
				
			}
		};



		
		class Thread {
        public:
			ThreadLinkNode<Thread> Link;
        //    int m_Field1; //0x4 
          //  int m_Field2; //0x8
			//Thread* instance; //0xC
			
            HANDLE m_Event1; //0x10
            HANDLE m_Event2; //0x14
            LPDWORD m_ThreadID;        //0x18 // ThreadID
            HANDLE m_ThreadHandle;  // 0x1C   Assuming HANDLE is used for thread identifier
			int ThreadFlag1; //0x20
			float m_Field3; //Performance //0x24
			int m_Field4; //0x28
			int m_Field5; //0x2c
			const char* m_ThreadName;
			int m_Field6; //0x34
			int ThreadFlag2; //0x38
			void* empty; //0x38
			
			

        public:
            Thread(const char* ThreadName,int Priority,int Flag);


			virtual void DestroyObject(unsigned int Flag);
			virtual void ThreadPerfomance();
			virtual void ThreadExecutor();
			virtual void ThreadStep(double delta);




 
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