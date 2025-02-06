#pragma once
#define nullptr NULL


//FINALLYT
template <typename T>
struct SimpleNode {
	unsigned int Flag;      
	void* custom;           
	T* Parent;              
	T* Child;               
	T* DependencyIn;        
	T* DependencyOut;       

	// Constructor
	SimpleNode()
		: Flag(0), custom(nullptr), Parent(nullptr), Child(nullptr), DependencyIn(nullptr), DependencyOut(nullptr) {}


	void CleanupOutgoingDependencies() {
		T* current = DependencyOut;
		while (current) {
			T* parent = current->Parent;
			current->DependencyIn = nullptr;
			current->Child = nullptr;
			current->Parent = nullptr;
			current = parent; 
		}
	}


	void HandleIncomingDependency() {
		T* parentTask = this->DependencyIn;
		if (parentTask) {
			T* prevTask = this->Child;
			if (prevTask != this) {  
				if (parentTask->DependencyOut == this) {
					parentTask->DependencyOut = this->Parent;  
					if (this->Child) {
						this->Child->Parent = nullptr;  // 
					}
				} else {
					if (prevTask) {  //
						prevTask->Parent = this->Parent;  // 
					}
				}
				T* newParent = this->Parent ? this->Parent : (this->DependencyIn ? this->DependencyIn->DependencyOut : nullptr);
				if (newParent) {  // Ensure newParent 
					newParent->Child = this->Child; 
				}
			}
			parentTask->DependencyOut = nullptr; 
		}
	}


	// Method to initialize DependencyIn relationship
	void InitDependencyIn() {

		if (this->DependencyIn) {  // If there is an incoming dependency
			Task* DependencyOut = this->DependencyIn->DependencyOut;

			if (DependencyOut) {  // If there's an outgoing dependency from the parent
				Task* v6 = DependencyOut->Child;
				this->Parent = nullptr;
				this->Child = v6;

				if (v6) {  // Update child's parent pointer if valid
					v6->Parent = (T*)this;
				}

				DependencyOut->Child = (T*)this;  // Update parent's outgoing child pointer
			} else {  // If no outgoing dependency exists
				this->Child = (T*)this;  // Set itself as its own child
				this->DependencyIn->DependencyOut = (T*)this;  // Update parent's outgoing dependency pointer
				this->Parent = nullptr;
			}

			
		} else {  // If there's no incoming dependency
			this->Child = (T*)this;  // Set itself as its own child
			this->Parent = nullptr;
		}
	}

};


#include "SimpleNode.inl"