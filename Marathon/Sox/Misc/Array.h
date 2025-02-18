#ifndef SONICTEAM__SOX__ARRAY
#define SONICTEAM__SOX__ARRAY

#include <algorithm> // Required for std::for_each, std::sort, etc.

template <typename Class, typename Count>
struct Array {
	Class data[Count];

	// Constructor
	Array() {}

	// Access element at index (with bounds checking)
	Class& operator[](size_t index) {
		if (index >= Count) {
			throw std::out_of_range("Array index out of bounds");
		}
		return data[index];
	}

	// Access element at index (const version)
	const Class& operator[](size_t index) const {
		if (index >= Count) {
			throw std::out_of_range("Array index out of bounds");
		}
		return data[index];
	}

	// Get the size of the array
	size_t size() const { return Count; }
	// Iterators
	Class* begin() { return data; }
	Class* end() { return data + Count; }
	const Class* begin() const { return data; }
	const Class* end() const { return data + Count; }
};



template <typename Class>
struct ArrayPtr {
	Class* data;
	int Count;

	// Constructor
	Array(int count) {
		data  = new Class[count];
	}

	// Access element at index (with bounds checking)
	Class& operator[](size_t index) {
		if (index >= Count) {
			throw std::out_of_range("Array index out of bounds");
		}
		return data[index];
	}

	// Access element at index (const version)
	const Class& operator[](size_t index) const {
		if (index >= Count) {
			throw std::out_of_range("Array index out of bounds");
		}
		return data[index];
	}

	// Get the size of the array
	size_t size() const { return Count; }
	// Iterators
	Class* begin() { return data; }
	Class* end() { return data + Count; }
	const Class* begin() const { return data; }
	const Class* end() const { return data + Count; }
};



#endif
