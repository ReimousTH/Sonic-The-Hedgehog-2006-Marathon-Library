
#ifndef CHAO__CSD__CREADFILE
#define CHAO__CSD__CREADFILE

#include <Chao/CSD/Defs.h>

#include <xtl.h>
#include <Sox/Memory/IDestructible.h>
#include <CMemoryAllocMarathon.h>
#include <string>





namespace Chao{
	namespace CSD{



		//Or SonicTeamSoxComponent
		class CReadFile
		{
		public:
			CReadFile(void);
			~CReadFile(void);


		public:

			virtual void CReadFile0x0() = 0;
			virtual void CReadFile0x4() = 0;
			DESTRUCTION_H; //0x0 + 0x10

		protected:
			std::string CFileName;	









		};
	};
};
#endif