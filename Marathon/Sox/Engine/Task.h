
#ifndef SONICTEAM__SOX__ENGINE__TASK
#define SONICTEAM__SOX__ENGINE__TASK


#include <Sox/Engine/Defs.h>
#include "../MessageReceiver.h"
#include "../Component.h"
#include "Engine.h"
#include <Sox/Misc/SimpleNode.h>



#define SSETaskInherit(ClassName) 0






namespace Sonicteam{
	namespace SoX{
		namespace Engine{



			class Task:public Sonicteam::SoX::Component,MessageReceiver,public SimpleNode<Task>
			{
				enum TaskFlags {
					TASK_DESTROY_OBJECT = 0x1000000,  
					TASK_ASYNC          = 0x4000000   
				};



			public:

				friend class IO_TASK;

				Task();
				Task(Sonicteam::SoX::Engine::Doc*); //no idea THRERE TWO OF THEM
				Task(Sonicteam::SoX::Engine::Task*); //no idea THRERE TWO OF THEM
				~Task(void);



				virtual int OnMessageRecieved(SoXMessageType) override; //_pure_call

				virtual char* GetObjectType();
				virtual void OnTaskUpdate(float) ; // pure_call

				DESTRUCTION_H;



				/*
				Sonicteam::SoX::Engine::Task* NextTask; //NextTask //0x2c
				Sonicteam::SoX::Engine::Task* PrevTask; //PrevTask //0x30
				Sonicteam::SoX::Engine::Task* ParentTask;// CurrentMode (MainMode, and There Others) IGuess Task is IT //0x34
				Sonicteam::SoX::Engine::Task* ActiveTask;// ActiveTask //0x38
				*/


				Sonicteam::SoX::Engine::Doc* TaskEngineDoc; // Sonicteam::SoX::Engine::Doc ,0x3C
				LinkSoxNode<Task> TaskList; //0x40 //0x44 //0x48


			};
		};
	}
}
#endif