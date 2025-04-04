#ifndef CHAO__DESTRUCTION
#define CHAO__DESTRUCTION


#define CDESTRUCTION_H virtual void* DestroyObject(unsigned int flag)
#define CDESTRUCTION_HPP_EX(className,dealloc) \
	virtual void* DestroyObject(unsigned int flag) { \
	className::~className(); /*  */ \
	if ((flag & 1) != 0) { \
	dealloc(this);; /*  */ \
	} \
	return this;\
	}

#define CDESTRUCTION_HPP(className) CDESTRUCTION_HPP_EX(className,::operator delete)

#endif
