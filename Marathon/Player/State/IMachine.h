#pragma once


#include "..\IPlugIn.h"
#include "IContext.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


namespace Sonicteam{

	namespace Player{
		namespace State{

		
			//8200BAD8
			class IMachine:IPlugIn
			{
			public:
				IMachine(void);
				~IMachine(void);


				virtual void DestroyObject(unsigned int flag) override;
				virtual void OnMashineTick(float) = 0; //delta (origin = 8221EBE8)
				virtual boost::shared_ptr<IContext> GetMashineContext() = 0;
				virtual unsigned int ChangeMashineState(int) = 0; // StateI
				virtual unsigned int AlternativeChangeMashineState(int) = 0; // StateI
				virtual void ResetStateFlagsA() = 0; //Not Sure about names
				virtual void ResetStateFlagsB() = 0; //Not Sure about names
				virtual unsigned int CompleteChangeMashineState(int) = 0; // With All Flags
				virtual unsigned int GetCurrentMashineStateID() = 0;




			};

		}

	}

}

