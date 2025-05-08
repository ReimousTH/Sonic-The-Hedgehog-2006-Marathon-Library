#ifndef SONICTEAM__SCENECOLLECTION
#define SONICTEAM__SCENECOLLECTION
#include "Defs.h"
#include <vector>
#include <boost/weak_ptr.hpp>



namespace Sonicteam{


	template <typename Element>
	class SceneCollection
	{

		SceneCollection();
		~SceneCollection();
		std::vector<boost::weak_ptr<Element>> _collection; //0x0

	public:
		boost::weak_ptr<Element>& operator[](size_t index);

	};

	template <typename Element>
	Sonicteam::SceneCollection<Element>::~SceneCollection()
	{

	}

	template <typename Element>
	Sonicteam::SceneCollection<Element>::SceneCollection()
	{

	}

	template <typename Element>
	boost::weak_ptr<Element>& Sonicteam::SceneCollection<Element>::operator[](size_t index)
	{
		return _collection[index];
	}

};

#endif