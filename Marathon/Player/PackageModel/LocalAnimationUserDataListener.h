#pragma once


#include <Sox/RefCountObject.h>
#include <Sox/Memory/DEFINITIONS.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <Sox/Physics/Entity.h>




namespace Sonicteam{
	namespace Player{
		namespace PackageModel{




		 ////////////////////////EXAMPLE///////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		/* 
		boost::function<int(int, int)> fnc1 = boost::bind(&MyClass::multiply, &obj, _1, _2); Hoow To use For Example :) (where _a1,_a2 custom args) , yes place inside class(this yea too)

		*/
		///////////////////////////////////////////////////////////////////////////



			class LocalAnimationUserDataListener:Sonicteam::SoX::RefCountObject
			{
			public:
				LocalAnimationUserDataListener(boost::function<void*(Sonicteam::SoX::Physics::Entity*&)>);
				~LocalAnimationUserDataListener(void);


				//YES IT IS  std::_Tree<std::_Tmap_traits< match 
				virtual void DestroyObject(unsigned int flag) override;

				virtual void ProcessFunc(Sonicteam::SoX::Physics::Entity*&);

				//MyPhantom, i use Entity for now
				boost::function<void*(Sonicteam::SoX::Physics::Entity*&)> ListenerFunc;
	


				_MARATHON_DEFINE_CONSTRUCTOR_(LocalAnimationUserDataListener,0x8222DD78,boost::function<void*(Sonicteam::SoX::Physics::Entity*&)> func);


			};


		};

	}
}

