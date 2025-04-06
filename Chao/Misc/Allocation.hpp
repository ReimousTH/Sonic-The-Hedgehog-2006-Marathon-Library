#ifndef CHAO__ALLOCATION
#define CHAO__ALLOCATION


#define CALLOCATION_HPP_NEW(ALLOCATOR) static void* operator new(size_t size) { return ALLOCATOR(size,__FILE__,__LINE__);}
#define CALLOCATION_HPP_DELETE(DEALLOCATOR) static void operator delete(void* ptr) { DEALLOCATOR(ptr); }


#endif
