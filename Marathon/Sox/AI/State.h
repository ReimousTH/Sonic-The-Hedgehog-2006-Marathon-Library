#pragma once

#include <Sox/Memory/IDestructible.h>
namespace Sonicteam{
	namespace SoX{


		namespace AI{
			//OBSOLETE CLASS 
			template <typename IContextType>
			class State
			{
			public:
	
				~State(void);
				 DESTRUCTION_HPP(State);


				virtual unsigned int* StateConstant() = 0; // idk what real name 
				virtual void OnStateStart(IContextType*) = 0; //OnStateStart
				virtual void OnStateUpdate(float) = 0; //OnStateUpdate
				virtual void OnStateEnd() = 0; //OnStateEnd
				virtual unsigned int StateUnknown() = 0; // li r3 ,0x0 blr


		


			};

	

			template <typename IContextType>
			Sonicteam::SoX::AI::State<IContextType>::~State(void)
			{

			}

		};
	}
}
