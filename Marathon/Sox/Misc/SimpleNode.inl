
template <typename T>
void SimpleNode<T>::AddChild(T* child)
{

	if (!child) return;

	child->parent = static_cast<T*>(this);
	if (!this->sibling) {
		this->sibling = child; // First child
	} else {
		T* lastSibling = this->sibling;
		while (lastSibling->next) {
			lastSibling = lastSibling->next; // Find the last sibling
		}
		lastSibling->next = child;
		child->previous = lastSibling;
	}
}

template <typename T>
void SimpleNode<T>::AddSibling(T* siblingNode)
{

	if (!siblingNode || !this->parent) return;

	siblingNode->parent = this->parent;

	T* lastSibling = (T*)this;
	while (lastSibling->next) {
		lastSibling = lastSibling->next; // Find the last sibling
	}
	lastSibling->next = siblingNode;
	siblingNode->previous = lastSibling;
}



template <typename T>
void SimpleNode<T>::ForEachSibling(void (*func)(T*))
{

	T* current = this->sibling;
	while (current) {
		T* previousNode = current->previous;
		func(current);   // Apply the custom function to the current node
		current = previousNode; // Move to the previous sibling
	}
}


template <typename T>
void SimpleNode<T>::RemoveLink()
{

	if (this->parent) {
		// Handle sibling relationship at parent level
		if (this->parent->sibling == this) {
			this->parent->sibling = this->previous;
		} else if (this->next) {
			this->next->previous = this->previous;
		}

		// Handle previous and next sibling links
		if (this->previous) {
			this->previous->next = this->next;
		} else if (this->parent) {
			// If no previous, update parent's sibling
			this->parent->sibling = this->next;
		}
	}

	// Nullify the node's links
	this->parent = 0;
	this->previous = 0;
	this->next = 0;
}

