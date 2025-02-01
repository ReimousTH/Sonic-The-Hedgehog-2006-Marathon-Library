#ifndef SONICTEAM__MEMORY__DESTRUCTION
#define SONICTEAM__MEMORY__DESTRUCTION


#define DESTRUCTION_H virtual void DestroyObject(unsigned int flag);

#define DESTRUCTION_CPP(className) \
	void className::DestroyObject(unsigned int flag) { \
	className::~className(); /*  */ \
	if ((flag & 1) != 0) { \
	delete this; /*  */ \
	} \
	}

#endif


