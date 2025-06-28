#ifndef SONICTEAM__KHRONOCONTROLLER
#define SONICTEAM__KHRONOCONTROLLER


#include <Defs.h>


#include <boost/function.hpp>
#include <Sox/Engine/Task.h>




namespace Sonicteam{




	class KhronoController:public Sonicteam::SoX::Engine::Task{

	public:
		KhronoController(Sonicteam::SoX::Engine::Task*); //no idea THRERE TWO OF THEM
		~KhronoController();


		Sonicteam::KhronoControlInputListener* KhronoCIListener; //0x4C
		float khrono_game_time; //0x50
		float khrono_time; //0x54
		float khrono_time_bias; //0x58, higher, timer slower
		float khrono_time_pass; //0x5C
		char khrono_flag_0x60; //0x60
		//free 3 bytes next :)
		


		DESTRUCTION_H;



		virtual void OnTaskUpdate(float);

		void UpdateKhronoTime(double);

	};

};




#endif