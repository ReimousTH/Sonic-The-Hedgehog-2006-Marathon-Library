
#ifndef CHAOS__CSD__SUBJECTBASE
#define CHAOS__CSD__SUBJECTBASE


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CMemoryAlloc.h>
#include <list>





namespace Chao{
	namespace CSD{



		//No INFO so empty
		template <typename Observer,typename Node>
		class SubjectBase	
		{
		public:
			SubjectBase(void);
			~SubjectBase(void);	
			CDESTRUCTION_HPP(SubjectBase);
			virtual Node* GetSubject();

			//NO IDEA ABOUT STRUCTURE MAYBE CUSTOM OR VERY WEIRD AT LEAST O_O , std::list maybe close no idea
			std::list<Observer*> ÑSubjectObservers; //4,8,C  


		
		};

		template <typename Observer,typename Node>
		Chao::CSD::SubjectBase<Observer, Node>::~SubjectBase(void)
		{

		}

		template <typename Observer,typename Node>
		Chao::CSD::SubjectBase<Observer, Node>::SubjectBase(void)
		{

		}

		template <typename Observer,typename Node>
		Node* Chao::CSD::SubjectBase<Observer, Node>::GetSubject()
		{
			return 0;
		}


	
	};
};
#endif
