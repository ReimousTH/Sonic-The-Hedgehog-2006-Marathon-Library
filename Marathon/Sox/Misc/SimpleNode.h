#pragma once



template <typename T>
struct SimpleNode {
	T* parent;    // Pointer to the parent node.
	T* previous;  // Pointer to the previous sibling or node.
	T* next;      // Pointer to the next sibling or node.
	T* sibling;   // Pointer to the first sibling at the same level.

	// Constructor
	SimpleNode()
		: parent(0), previous(0), next(0), sibling(0) {}

	// Add a child node
	void AddChild(T* child);
	// Add a sibling node
	void AddSibling(T* siblingNode);
	// Custom clear function (like ReleaseFrameLayer2)
	// Iterate through siblings and apply a custom function
	void ForEachSibling(void (*func)(T*)) ;

	// Remove this node from the hierarchy (unlink without deletion).
	void RemoveLink();
};




#include "SimpleNode.inl"