#pragma once

#include "IMachine.h"
#include "..\..\Sox\AI\State.h"
#include "IContext.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


namespace Sonicteam{

	namespace Player{
		namespace State{

		
			//8200BAD8
			class Object2:public Sonicteam::SoX::AI::State<Sonicteam::Player::State::IContext>
			{
			public:
				Object2(IMachine*);
				~Object2(void);
				
				virtual void DestroyObject(unsigned int flag) override;
	



				//or IMachine*
				IMachine* ObjectMashine; //State




				virtual unsigned int* StateConstant() override; // idk what real name 
				virtual void OnStateStart(Sonicteam::Player::State::IContext* context) override; //OnStateStart
				virtual void OnStateUpdate(float) override; //OnStateUpdate
				virtual void OnStateEnd() override; //OnStateEnd
				virtual unsigned int StateUnknown() override; // li r3 ,0x0 blr






				virtual void Object2Start() = 0;	
				virtual unsigned int Object2Update(float) = 0;	
				virtual void Object2End() = 0;

				virtual void Object2PreUpdateCmn(float) = 0;
				virtual void Object2PostUpdateCmn(float) = 0;



			

			};

		}

	}

}

