#pragma once


#include "Object2.h"
#include "IContext.h"
#include "CommonContext.h"





namespace Sonicteam{

	namespace Player{
		namespace State{


		

		
			//8200BAD8
			class CommonObject:public Object2
			{
			public:
				CommonObject(IMachine*);
				~CommonObject(void);



				virtual void Object2Start() override  = 0 ;
				virtual unsigned int Object2Update(float) override;
				virtual void Object2End() override = 0;	

				virtual void Object2PreUpdateCmn(float) override;	
				virtual void Object2PostUpdateCmn(float) override;	

				virtual void DestroyObject(unsigned int flag) override;



				//IContext* CObjContext;
				//FILEDS
				CommonContext* CObjContext;



			

			};

		}

	}

}

