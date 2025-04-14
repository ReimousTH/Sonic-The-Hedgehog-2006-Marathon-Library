#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>




namespace Chao{
	struct CVector2{
	public:
		float x;
		float y;
		CVector2(float x,float y){
			this->x = x;
			this->y = y;
		}
	};

	struct CColor {
		union {
			struct {
				unsigned char r; 
				unsigned char g; 
				unsigned char b; 
				unsigned char a; 
			};
			unsigned int color; // Combined color value (32 bits)
		};
	};


	struct csize_t {
		union {
			unsigned __int64 full; 
			struct {
				unsigned __int32 low;
				unsigned __int32 high;
			};
		};
		csize_t(unsigned __int64 value = 0) : full(value) {}


		operator size_t() const {
			return static_cast<size_t>(high); 
		}

		csize_t& operator=(unsigned __int64 value) {
			full = value;
			return *this;
		}

		csize_t operator+(const csize_t& other) const {
			return csize_t(static_cast<size_t>(*this) + static_cast<size_t>(other));
		}

		csize_t operator-(const csize_t& other) const {
			return csize_t(static_cast<size_t>(*this) - static_cast<size_t>(other));
		}

		friend std::ostream& operator<<(std::ostream& os, const csize_t& obj) {
			os << static_cast<size_t>(obj); // Print only the relevant bits
			return os;
		}
	};



	//ptr
	template <typename PointerType = Element>
	struct CArrayEX {
		PointerType values; 
	};

	//counted
	template <typename size_t,typename PointerType = Element>
	struct CCArrayEX {
		size_t Count;           // Size field (e.g., uint32_t or uint64_t)
		PointerType values;     // Pointer type (__ptr32 or __ptr64)
	};


	template <typename Element>
	struct CCArray32 : CCArrayEX<size_t, Element* __ptr32> {};

	template <typename Element>
	struct CCArray64 : CCArrayEX<csize_t, Element* __ptr64> {};



	template <typename Element>
	struct CArray32 : CArrayEX<Element* __ptr32> {};

	template <typename Element>
	struct CArray64 : CArrayEX<Element* __ptr64> {};







	struct CSprite{
	public:
		unsigned int TextureIndex;
		CVector2 TopLeft;
		CVector2 BottomRight;
	};




	struct CastInfo{
		const char* CastName; //Check Later
		unsigned int CastNamePadding; // 
		unsigned int FamilyIdx;
		unsigned int CastIdx;
	};

	struct Motion{
		size_t index;
		void* MotionData;
	};




#pragma pack(push, 8)
	template <typename Type>
	struct C64BIT {
		Type value; 
		Type get() {
			return value;
		}
	};
#pragma pack(pop)



	template <typename Element>
	struct CArray86 : CArrayEX<C64BIT<Element*>> {};



	typedef std::pair<C64BIT<const char*>,C64BIT<size_t>> IndexValueName;


	template <typename size_t,typename CArrayItem,typename CArrayIndex>
	struct CDictionaryEX{
		size_t count;
		CArrayItem Items;
		CArrayIndex NameTable;
	};

	template <typename Item>
	struct CDictionary64:CDictionaryEX<csize_t,CArray64<Item>,CArray64<IndexValueName>>{};

	template <typename Item>
	struct CDictionary86:CDictionaryEX<C64BIT<size_t>,CArray86<Item>,CArray86<IndexValueName>>{};



};




#endif
