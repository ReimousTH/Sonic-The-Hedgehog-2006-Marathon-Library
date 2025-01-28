#pragma once

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <Sox/AI/State.h>


namespace Sonicteam{
	namespace SoX{

		namespace AI{
			
			template<typename T>
			class StateMashine
			{
			public:
				StateMashine(void) {};
				virtual void DestroyObject(unsigned int flag);
			//	
				
				virtual void OnStateChange(boost::shared_ptr<Sonicteam::SoX::AI::State<T>>& NextState,T* context); // For now nothing
				virtual void OnStateUnk(boost::shared_ptr<Sonicteam::SoX::AI::State<T>>& NextState,T* context); // For now nothing
				virtual unsigned int Unk03(T* context) { return 0;}; // For now nothing
				virtual unsigned int Unk04() { return 0;}; // For now nothing
				virtual unsigned int Unk05() { return 0;}; // For now nothing
				virtual unsigned int Unk06() { return 0;}; // For now nothing

			public:
				//FIELDS
				boost::shared_ptr<Sonicteam::SoX::AI::State<T>> CurrentState; //0x4
				unsigned int field0xC; //0xC
				unsigned int field0x10; //0x10
				unsigned int field0x14; //0x14
				unsigned int field0x18; //0x18
				unsigned int field0x1C; //0x1C
				//end- ->0x20



			};

			template<typename T>
			void Sonicteam::SoX::AI::StateMashine<T>::OnStateUnk(boost::shared_ptr<Sonicteam::SoX::AI::State<T>>& NextState,T* context)
			{

			}
		

			template<typename T>
			void Sonicteam::SoX::AI::StateMashine<T>::DestroyObject(unsigned int flag)
			{

			}

			template<typename T>
			void Sonicteam::SoX::AI::StateMashine<T>::OnStateChange(boost::shared_ptr<Sonicteam::SoX::AI::State<T>>& NextState,T* context) //IContext
			{
				boost::shared_ptr<Sonicteam::SoX::AI::State<T>> _next = NextState;
				if (NextState){
					if (this->CurrentState) this->CurrentState->OnStateEnd();
					_next->OnStateStart(0);
				}
				this->CurrentState = _next;
			}
		}



	
	}
}
