#pragma once




#include <Player/State/Object2.h>
#include "IMachine.h"
#include "IContext.h"
#include "CommonContext.h"
#include "../../Sox/StateMachine.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <functional>


using namespace Sonicteam::SoX::AI;


typedef boost::shared_ptr<Sonicteam::Player::State::Object2> *(*StateConstructor)(Sonicteam::Player::State::IMachine*);


namespace Sonicteam{

	namespace Player{
		namespace State{

	
			//8200BAD8
			class Machine2:public StateMashine<IContext>,IMachine
			{
			public:
				Machine2(void);
				~Machine2(void);


				virtual void DestroyObject(unsigned int flag) override;

				///IMachine
				virtual void OnMashineTick(float)  override;
				virtual boost::shared_ptr<IContext> GetMashineContext() override;
				virtual unsigned int ChangeMashineState(int) override;
				virtual unsigned int AlternativeChangeMashineState(int) override;
				virtual void ResetStateFlagsA() override;
				virtual void ResetStateFlagsB() override;
				virtual unsigned int CompleteChangeMashineState(int) override;
				virtual unsigned int GetCurrentMashineStateID() override;

			
		
				//Mashine Fields
				//unsigned int field_0x3C; // why did i even add this????????
				std::vector<std::pair<int,StateConstructor>> MashineStates; //0x40
				unsigned int PreState; // -1 (at constuctor)
				unsigned int PostState;
						 byte MashineStateFlag1; //0x58
						 byte MashineStateFlag2; //0x59
						 byte MashineStateFlag3; //0x5A
						 byte Unk0x5B; //0x5B
				unsigned int Unk0x5C; //0x5C
				unsigned int Unk0x60; //0x60
				unsigned int Unk0x64; //0x64
				unsigned int Unk0x68; //0x68
				unsigned int Unk0x6C; //0x6C
				boost::shared_ptr<IContext> MashineContext; //0x70
				
				



			};

		}

	}

}

