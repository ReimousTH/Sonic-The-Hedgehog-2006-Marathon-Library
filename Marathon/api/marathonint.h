#ifndef MARATHON_H
#define MARATHON_H



// ======================
// VFT Management System (Recompiled & Xenon)
// ======================


// Base VFT structure and macros
struct MVFT_Base {};


#ifndef _XBOX
// Core VFT structure
struct MVFT_Base {
    virtual ~MVFT_Base() = default;
};

// Macros for proper vtable overriding
#define BEGIN_VFT(Class, ...) \
    struct Class##_VFT : public MVFT_Base, ##__VA_ARGS__ { \
        using ThisClass = Class;

#define VFT_FUNC_H(Ret, Name, ...) \
    virtual Ret Name(##__VA_ARGS__)

#define END_VFT(Class) \
    }; \
    Class##_VFT* vft = nullptr;



#else
// Native implementation
#define BEGIN_VFT(Class, ...) 
#define VFT_FUNC_H(Ret, Name, ...) virtual Ret Name(##__VA_ARGS__)
#define END_VFT(Class)
#define OVERRIDE_VFT(Base, Class, Ret, Name, ...) Ret Name(##__VA_ARGS__) override
#endif

// =====
// Example #1
// ====


class Object {
    BEGIN_VFT(Object)
        VFT_FUNC_H(void, Destroy);
        VFT_FUNC_H(bool, Test);
    END_VFT(Object)
};

class Test : public Object {
    BEGIN_VFT(Test, Object)
        VFT_FUNC_H(void, NewMethod);
    END_VFT(Test)
};

class Object4 : public Test {
    BEGIN_VFT(Object4, Test)
    END_VFT(Object4)
};


// ======================
// Type System Replacement (Basic) (Recompiled & Xenon)
// ======================

#ifdef _XBOX

	//signed
	#define m_int8 byte
	#define m_int16 short
	#define m_int32 long
	#define m_int64 long long

	//unsigned
	#define m_uint8 unsigned m_int8
	#define m_uint16 unsigned m_uint16
	#define m_uint32 unsigned m_uint32
	#define m_uint64 unsigned m_uint64
	#define m_size_t size_t

	//floats
	#define m_float float
	#define m_double double
	
	//pointers
	#define m_ptr(type) type*
	

#else
	
	//signed
	#define m_int8   be<int8_t>
	#define m_int16  be<int16_t>
	#define m_int32  be<int32_t>
	#define m_int64  be<int64_t>

	//unsigned
	#define m_uint8  be<uint8_t>
	#define m_uint16 be<uint16_t>
	#define m_uint32 be<uint32_t>
	#define m_uint64 be<uint64_t>
	#define m_size_t be<uint32_t>

	//floats
	#define m_float be<float>
	#define m_double be<double>
	
	//pointers
	#define m_ptr(type) xpointer<type>


#endif

// ======================
// Type System Replacement (std) (Recompiled & Xenon)
// ======================


#ifdef _XBOX
	#define m_string std::string
	#define m_vector(T) std::vector<T>
	#define m_map(T,Y) std::map<T,Y>
	#define m_map(T,Y,A) std::map<T,Y,A>
#else
	#define m_string stdx::string
	#define m_vector(T) stdx::vector<T>
	#define m_map(T,Y) stdx::map<T,Y>
	#define m_map(T,Y,A) stdx::map<T,Y,A>
#endif






// ======================
// Type System Replacement (Boost) (Recompiled & Xenon)
// ======================

#define boost_shared_ptr(type) boost::shared_ptr<type>
#define boost_weak_ptr(type) bost::weak_ptr<type>





// ======================
// Destruction System Replacement  (Recompiled & Xenon)
// 
#ifndef _XBOX
#undef  DESTRUCTION_H
#undef  DESTRUCTION_CPP
#define DESTRUCTION_H(className) VFT_FUNC_H(className)
#define DESTRUCTION_CPP(className)
#define DESTRUCTION_CPP(className,dealloc)
#endif




#endif
