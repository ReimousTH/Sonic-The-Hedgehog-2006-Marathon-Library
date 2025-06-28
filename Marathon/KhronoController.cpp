#include "KhronoController.h"
#include <DocMarathonImp.h>
#include <KhronoControlInputListener.h>


#include <boost/function.hpp>
#include <boost/bind.hpp>


using namespace Sonicteam;







void KhronoController::OnTaskUpdate(float)
{
	
}



KhronoController::KhronoController(Sonicteam::SoX::Engine::Task* task):Task(task)
{
	this->KhronoCIListener = 0;
	this->khrono_game_time = 0;
	this->khrono_time = 0;
	this->khrono_time_pass = 10.0;
	this->khrono_time_bias = 0;
	this->khrono_flag_0x60 = 1;



	KhronoControlInputListenerBFUNC func = 
		boost::bind(&KhronoController::UpdateKhronoTime, this, _1);

	this->KhronoCIListener = new Sonicteam::KhronoControlInputListener(func);
	Sonicteam::DocMarathonImp* doc =  (Sonicteam::DocMarathonImp*)this->TaskEngineDoc;




	doc->QueueControllerInputByIndex(reinterpret_cast<Sonicteam::SoX::Input::Listener*>(this->KhronoCIListener),doc->GetRealControllerID(0));
	

}

KhronoController::~KhronoController()
{

}

DESTRUCTION_CPP(KhronoController);

void KhronoController::UpdateKhronoTime(double delta)
{
	this->khrono_time_pass = delta; //thats how IT DONE in original why time wstucks, then seems function must be runned from khronocontroller as boost
}
