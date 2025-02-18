#ifndef SONICTEAM__MEMORY__DESTRUCTION
#define SONICTEAM__MEMORY__DESTRUCTION


#define DESTRUCTION_H virtual void* DestroyObject(unsigned int flag);

#define DESTRUCTION_CPP(className) \
	void* className::DestroyObject(unsigned int flag) { \
	className::~className(); /*  */ \
	if ((flag & 1) != 0) { \
	::operator delete(this); /*  */ \
	} \
	return this;\
	}

#define DESTRUCTION_HPP(className) \
	virtual void* DestroyObject(unsigned int flag) { \
	className::~className(); /*  */ \
	if ((flag & 1) != 0) { \
	::operator delete(this);; /*  */ \
	} \
	return this;\
	}


#define DESTRUCTION_CPP(className,dealloc) \
	void* className::DestroyObject(unsigned int flag) { \
	className::~className(); /*  */ \
	if ((flag & 1) != 0) { \
	dealloc(this); /*  */ \
	} \
	return this;\
	}

#endif


