#pragma once


#include <Sox/Thread.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>




namespace Sonicteam{
	namespace SoX{

	    ////////////////////////EXAMPLE///////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		/* 
		boost::function<int(int, int)> fnc1 = boost::bind(&MyClass::multiply, &obj, _1, _2); Hoow To use For Example :) (where _a1,_a2 custom args) , yes place inside class(this yea too)

		*/
		///////////////////////////////////////////////////////////////////////////


		
		class StepableThread:Thread {
        public:

			boost::function<void*()> func1;
			boost::function<void*(double)> func2;
			unsigned int StepableThreadFlag;
        
			

        public:
			StepableThread(const char* ThreadName,boost::function<void*()> fnc1,boost::function<void*(double)> fnc2,int Priority);



 
            ~StepableThread	();


	

			_MARATHON_DEFINE_CONSTRUCTOR_(StepableThread,0x82618E78,const char* ThreadName,boost::function<int()> fnc1,boost::function<int()> fnc2,int Priority);

			virtual void ThreadStep(double delta) override;

			virtual void ThreadPerfomance();






	

  
		};






	};
};