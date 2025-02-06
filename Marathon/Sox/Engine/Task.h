#pragma once

#include "../MessageReceiver.h"
#include "../Component.h"
#include "Engine.h"
#include <Sox/Misc/SimpleNode.h>



namespace Sonicteam{
	namespace SoX{
		namespace Engine{



			class Task:public Sonicteam::SoX::Component,MessageReceiver,public SimpleNode<Task>
		{
		public:
		
			friend class IO_TASK;

			Task(Sonicteam::SoX::Engine::Doc*); //no idea THRERE TWO OF THEM
			Task(Sonicteam::SoX::Engine::Task*); //no idea THRERE TWO OF THEM
			~Task(void);



			virtual int OnMessageRecieved(Sonicteam::SoX::Message*) override; //_pure_call

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
