#ifndef CHAO__CSD__CNODE
#define CHAO__CSD__CNODE


#include <Chao/CSD/Defs.h>
#include <Chao/Misc/utill.hpp>
#include <Chao/Misc/API_DEFS.h>

namespace Chao{
	namespace CSD{



		//CastInfo(SharpNeedle)
		struct NodeInfo{
			size_t HideFlag; //0
			CVector2 Translation; //4-8
			float Rotation; //C
			CVector2 Scale; //10-14
			float SpriteIndex;  //18
			CColor Color; //0x1C
			CColor GradientTopLeft; //0x20
			CColor GradientBottomLeft; //0x24
			CColor GradientTopRight; //0x28
			CColor GradientBottomRight; //0x2c
			unsigned int UserData0; //0x30
			unsigned int UserData1; //0x34
			unsigned int UserData2; //0x38
		};


		//Cast(SharpNeedle)
		struct Node
		{
		public:
			Node(void);
			~Node(void);

			enum NodeType:int{
				Null,
				Sprite,
				Font
			};
			//
			size_t Field00; //0
			NodeType Type; //4
			size_t Enabled; //8
			CVector2 TopLeft; //0xC-0x10
			CVector2 BottomLeft ; //0x14-0x18
			CVector2 TopRight ; //0x1c-0x20
			CVector2 BottomRight ; //0x24-0x28
			size_t unk0x2C; //0x2C
			NodeInfo* Info;//0x30
			size_t InheritanceFlags; //0x34
			size_t MaterialFlags; //0x38
			CCArray32<size_t> SpriteIndices; //0x3C-0x40
			const char* __ptr64 Text; //0x44-0x48?
			const char* __ptr64 FontName; //0x4C-0x50?
			char _padding_[4]; // ???? 0x54 or  Text/FontName (C64 Bit also  CCArray6432 where size_t is 32bit and pointer C64bit
			float FontKerning; //0x58
			// if (family.Scene.Version >= 3) seems yes
			size_t width; //0x5C
			size_t height; //0x60
			size_t unk0x58; //0x64
			size_t unk0x5C; //0x68
			CVector2 Origin; //6C-70
			CVector2 Position; //74-78
			size_t unk0x7C; //0x7C


			

		};
	};
};
#endif