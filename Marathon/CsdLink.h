#pragma once


#include <Sox/Memory/IDestructible.h>
#include <Sox/RefCountObject.h>




namespace Sonicteam{


	//Or SonicTeamSoxComponent
	class CsdLink
		{
		public:
			CsdLink(void);
			~CsdLink(void);


		public:
			virtual void DestroyObject(unsigned int flag); //0x0 + 0x10
			virtual void CsdLink0x4() = 0;
			virtual void CsdLink0x8(double) = 0;
			

		protected:
			unsigned int FCsdLink0x4;
			unsigned int FCsdLink0x8;
				   float FCsdLink0xC;
			unsigned int FCsdLink0x10;
			unsigned int FCsdLink0x14;
	


		
		


	


	};

};