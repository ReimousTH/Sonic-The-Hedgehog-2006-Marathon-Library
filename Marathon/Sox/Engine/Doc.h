
#ifndef SONICTEAM__SOX__ENGINE__DOC
#define SONICTEAM__SOX__ENGINE__DOC


#include <Sox/Engine/Defs.h>
#include "../MessageReceiver.h"
#include "GTask.h"
#include <xtl.h>
#include <Sox/Engine/Application.h>
#include <Sox/Engine/Task.h>
#include <Sox/RefCountObject.h>




namespace Sonicteam{

	namespace SoX{


		namespace Engine{


			class Task;

			namespace{
			

				class RootTask:public Sonicteam::SoX::Engine::Task{
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






			class Doc
			{

			public:	
				~Doc(void);

				DESTRUCTION_H;
				virtual void EngineDocOnUpdate(float); //delta
				virtual void EngineDocDomeSome(); //CriticalNoIdea?s

				unsigned int Duint0x4; //NOT REF OBJECT
				unsigned int DocCurrentMode; //CurrentMode (GameMode,MainMode)
				RootTask* RTask; //0xC
				RootGTask* RGTask;
				Sonicteam::SoX::Engine::Application* DocCurrentApplication; //ApplicationMarathon (reference &)
				unsigned int Duint0x18;
				DocModeExecutor* DMExecutor;
				unsigned int DRenderScheduler; //Sonicteam::SoX::Engine::RenderSchedule (RefCountObj Ok)
				CRITICAL_SECTION DocCriticalSectionFirst; //synchronization object
				CRITICAL_SECTION DocCriticalSectionSecond; //synchronization object



			};
		};
	}
}
#endif