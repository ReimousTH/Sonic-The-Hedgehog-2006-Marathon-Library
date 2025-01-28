#pragma once

#include "../MessageReceiver.h"
#include "../Component.h"
#include "Engine.h"

namespace Sonicteam{
	namespace SoX{
		namespace Engine{

			struct IO_TASK{
				//Fields
				unsigned int Tuint0x24; //Flag?
				unsigned int Tuint0x28; //Flag  // ????????
			public: IO_TASK();
			};

			class Task:public Sonicteam::SoX::Component,MessageReceiver,public IO_TASK,public SimpleLinkNode<Task>
		{
		public:
			friend class SimpleLinkNode<Task>;
			friend class IO_TASK;

			Task(Sonicteam::SoX::Engine::Doc*); //no idea THRERE TWO OF THEM
			Task(Sonicteam::SoX::Engine::Task*); //no idea THRERE TWO OF THEM
			~Task(void);



			virtual int OnMessageRecieved(Sonicteam::SoX::Message*); //_pure_call


			virtual char* GetObjectType();

			virtual void OnTaskUpdate(float) ; // pure_call

			virtual void DestroyObject(unsigned int flag) override;



/*
			Sonicteam::SoX::Engine::Task* NextTask; //NextTask //0x2c
			Sonicteam::SoX::Engine::Task* PrevTask; //PrevTask //0x30
			Sonicteam::SoX::Engine::Task* ParentTask;// CurrentMode (MainMode, and There Others) IGuess Task is IT //0x34
			Sonicteam::SoX::Engine::Task* ActiveTask;// ActiveTask //0x38
*/
		
	
			Sonicteam::SoX::Engine::Doc* TaskEngineDoc; // Sonicteam::SoX::Engine::Doc ,0x3C
			Sonicteam::SoX::LinkNodeList<Task> TaskList; //0x40 //0x44 //0x48


		};
	};
}
}
