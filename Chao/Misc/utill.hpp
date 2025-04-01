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

	struct csize_t {
		union {
			unsigned __int64 full; 
			struct {
				unsigned __int64 low : 32;  
				unsigned __int64 high : 32; 
			};
		};
		csize_t(unsigned __int64 value = 0) : full(value) {}
		operator size_t() const {
			return static_cast<size_t>(full); 
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
	template <typename PointerType = Element* __ptr32>
	struct CArrayEX {
		PointerType values; 
	};

	//counted
	template <typename size_t,typename PointerType = Element* __ptr32>
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

	};




#pragma pack(push, 8)
	template <typename Type>
	struct C64BIT {
		Type value; 
		Type Get() {
			return value;
		}
	};
#pragma pack(pop)

	typedef std::pair<C64BIT<const char*>,C64BIT<size_t>> IndexValueName;



	template <typename T>
	struct CDictionary{
		csize_t count;
		CArray64<T> Items;
		CArray64<IndexValueName> NameTable;
	};

};




#endif
