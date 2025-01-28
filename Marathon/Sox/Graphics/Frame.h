#ifndef Sonicteam__SOX__Graphics
#define Sonicteam__SOX__Graphics


#include "../MessageReceiver.h"
#include <SoX/RefCountObject.h>
#include <xtl.h>
#include <Sox/Misc/List.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Memory/DEFINITIONS.hpp>

#include "Defs.h"




namespace Sonicteam{
	namespace SoX{
		namespace Graphics{
			class Frame;




			///////FRAME//////////
			struct IO_FRAME{
				////
				unsigned int FrameRefFlag; // 0x8
				Sonicteam::SoX::RefCountObject* instance; // 0xC
			};



			//TODO Original Destructor 
			class Frame:public Sonicteam::SoX::RefCountObject,IO_FRAME,public Sonicteam::SoX::SimpleLinkNode<Frame> //Need Aditional Methods, FullClearLink()
			{

			public:
				Frame();
				~Frame();

				virtual void DestroyObject(unsigned int flag) override;


				//Virtual Methods
				virtual int FrameUnk01();
				virtual int FrameUnk02();

				virtual XMMATRIX FrameGetTransformMatrix1() = 0;
				virtual XMMATRIX FrameGetTransformMatrix2() = 0;
				virtual void FrameSetTransformMatrix2(XMMATRIX&) = 0;
				virtual void FrameUnk06(XMMATRIX&) = 0;
				virtual void FrameUnk07() = 0;

				virtual int FrameUnk08();


				//0x8
				//0xC

				//	Frame* Next; //0x10 
				//	Frame* Prev; //0x14 
				//	Frame* Active; //0x18  
				//	Frame* Parent; //0x1c

				Sonicteam::SoX::LinkNodeListA<FrameObserver> OFrame; //0x20, since FrameObserver ~= Frame , then TThead == 0, Clear with based on class (0x10 size) (need look still)
				//unsigned int Fuint0x2C; //proable padding
				Sonicteam::SoX::Graphics::FrameSynchronizer* FrameSynchronizer; //Poitner only, 


				//MAYBE , NODE structure with FIrst is Pointer, Other Just Elements, I have almost same in DocMarathon

				Sonicteam::SoX::RNodeF<Frame> BNF0x34;	

				//	ListEX03_06<Sonicteam::SoX::RefCountObject> Fuint0x34;
				//	unsigned int Fuint0x34; //PointToFrame(base) + 0x34
				//	unsigned int Fuint0x38; ////PointToFrame(base) + 0x34 (different or can be same), not in constructor :|
				//Sonicteam::SoX::RefCountObject& Fuint0x3C;

				//40 16 84 EC((to this point) ) 40 16 84 EC(to previous point) 00 00 00 00 40 16 84 F8 40 16 84 F8  (only point to exactly this point,both)

				Sonicteam::SoX::RNodeF<Frame> BNF0x40;
				//	ListEX03_06<Sonicteam::SoX::RefCountObject> Fuint0x40;
				//unsigned int Fuint0x40; //Points To Frame Base + 0x40, but this this it seems always changing
				//unsigned int Fuint0x44; //44 same they both changing between
				//Sonicteam::SoX::RefCountObject& Fuint0x48;


			};
		};
	}
}

#endif

