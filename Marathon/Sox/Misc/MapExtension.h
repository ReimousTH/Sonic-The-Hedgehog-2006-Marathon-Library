#ifndef MAPEXTENSION_H
#define MAPEXTENSION_H

#include <Xboxmath.h>
#include <string>

struct STD_MAP_CONST_CHAR_PTR_COMPARATOR {
    bool operator()(const char* lhs, const char* rhs) const {
        return std::strcmp(lhs, rhs) < 0; // Compare based on string content
    }
};

#endif
