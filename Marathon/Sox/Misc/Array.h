#ifndef SONICTEAM__SOX__ARRAY
#define SONICTEAM__SOX__ARRAY



template <typename Class, size_t Count>
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



template <typename T>
struct ArrayPtr {
    T* items;  // Initialize to null
    int count;

    // Default constructor (empty array)
	ArrayPtr() : items(NULL), count(0) {}

    // Pre-initialization constructor
    explicit ArrayPtr(int size) : 
        items(new T[size]()),  // Zero-initialize
        count(size) {}


	ArrayPtr(T* ptr, int size)
			: items(ptr), count(size) {}

    // Destructor (if ownership is needed)
    ~ArrayPtr() { delete[] items; }

    T& operator[](size_t index) {
        return items[index];
    }

    // Disable copy for simplicity (or implement properly)
    ArrayPtr(const ArrayPtr&);
    ArrayPtr& operator=(const ArrayPtr&);
};



template <typename T>
struct AIMArray {
	T* items;         // Raw pointer array of T
	int LastItemID;   // Track last valid ID
	int EndItemID;    // Marks capacity boundary

	// Pre-allocate and initialize array
	explicit AIMArray(int size) 
		: items(new T[size]()),  // Value-initialize each element
		LastItemID(-1),
		EndItemID(size - 1) {}

	// Pre-allocate and initialize array
	// Constructor that wraps an existing array (no ownership)
	AIMArray(T* existingItems, int size)
		: items(existingItems), LastItemID(size - 1), EndItemID(size - 1){}

	// Cleanup
	~AIMArray() {
		delete[] items;
		items = NULL;
	}

private:
	// Disable copying (prevent double-free)
	AIMArray(const AIMArray&);
	AIMArray& operator=(const AIMArray&);

public:
	// Access element with bounds checking
	T& at(size_t index) {
		if(index > static_cast<size_t>(EndItemID)) {
			throw std::out_of_range("AIMArray index out of bounds");
		}
		return items[index];
	}

	// Const version for const objects
	const T& at(size_t index) const {
		if(index > static_cast<size_t>(EndItemID)) {
			throw std::out_of_range("AIMArray index out of bounds");
		}
		return items[index];
	}
};




#endif
