#pragma once

#include <cstdlib>
#include <iostream>

#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>



namespace Sonicteam{
	namespace Combo{

		//size = 0x24 , there somewhere boost but it idk
		class ScoreManager 
		{
		public:
			ScoreManager(void);
			virtual ~ScoreManager(void);

		};



	}
}
