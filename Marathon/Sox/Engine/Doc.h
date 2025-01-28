#pragma once

#include "../MessageReceiver.h"
#include "GTask.h"
#include <xtl.h>
#include <Sox/ApplicationXenon.h>
#include <Sox/Engine/Task.h>
#include <Sox/RefCountObject.h>




namespace Sonicteam{

	namespace SoX{


		namespace Engine{

			
			typedef class Task;
			
			namespace{
			//Place 3 of them as anymoyus name space and use in class idk how
			class RootTask:Sonicteam::SoX::Engine::Task{
			public:
				virtual int OnMessageRecieved(Sonicteam::SoX::Message*);
				virtual char* GetObjectType(); //return change a later
				virtual void OnTaskUpdate();
			};
			class RootGTask:Sonicteam::SoX::Engine::GTask{
			public:
				virtual char* GetObjectType(); //return change a later

			};
			class DocModeExecutor:Sonicteam::SoX::Engine::Task{
			public:
				virtual int OnMessageRecieved(Sonicteam::SoX::Message*);
				virtual char* GetObjectType(); //return change a later 
				virtual void OnTaskUpdate();
			};
};
		



	

			class Doc:Sonicteam::SoX::RefCountObject
		{

		public:
			~Doc(void);
			virtual void EngineDocOnUpdate(float); //delta
			virtual void EngineDocDomeSome(); //CriticalNoIdea?s

		//s	unsigned int Duint0x4; //sems always 0x4 (refobjectcound)
			unsigned int DocCurrentMode; //CurrentMode (GameMode,MainMode)
			RootTask* RTask;
			RootGTask* RGTask;
			Sonicteam::SoX::ApplicationXenon* DocCurrentApplication; //ApplicationMarathon (reference &)
			unsigned int Duint0x18;
			DocModeExecutor* DMExecutor;
			unsigned int DRenderScheduler; //Sonicteam::SoX::Engine::RenderSchedule (RefCountObj Ok)
			CRITICAL_SECTION DocCriticalSectionFirst; //synchronization object
			CRITICAL_SECTION DocCriticalSectionSecond; //synchronization object
			
			

		};
	};
}
}
