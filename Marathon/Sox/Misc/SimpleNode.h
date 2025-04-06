#pragma once
#define nullptr NULL


//FINALLYT
template <typename T>
struct SimpleNode {
	unsigned int flags;      
	size_t time;           
	T* prev;              
	T* next;               
	T* depends_on;        
	T* required_by;       

	// Constructor
	SimpleNode()
		: flags(0), time(nullptr), prev(nullptr), next(nullptr), depends_on(nullptr), required_by(nullptr) {}



public:



	void CleanupOutgoingDependencies() {
		T* current = required_by;
		while (current) {
			T* parent = current->prev;
			current->depends_on = nullptr;
			current->next = nullptr;
			current->prev = nullptr;
			current = parent; 
		}
	}


	void HandleIncomingDependency() {
		T* parentTask = this->depends_on;
		if (parentTask) {
			T* prevTask = this->next;
			if (prevTask != this) {  
				if (parentTask->required_by == this) {
					parentTask->required_by = this->prev;  
					if (this->next) {
						this->next->prev = nullptr;  // 
					}
				} else {
					if (prevTask) {  //
						prevTask->prev = this->prev;  // 
					}
				}
				T* newParent = this->prev ? this->prev : (this->depends_on ? this->depends_on->required_by : nullptr);
				if (newParent) {  // Ensure newParent 
					newParent->next = this->next; 
				}
			}
			parentTask->required_by = nullptr; 
		}
	}


	// Method to initialize DependencyIn relationship
	void InitDependencyIn() {

		if (this->depends_on) {  // If there is an incoming dependency
			Task* DependencyOut = this->depends_on->required_by;

			if (DependencyOut) {  // If there's an outgoing dependency from the parent
				Task* v6 = DependencyOut->next;
				this->prev = nullptr;
				this->next = v6;

				if (v6) {  // Update child's parent pointer if valid
					v6->prev = (T*)this;
				}

				DependencyOut->next = (T*)this;  // Update parent's outgoing child pointer
			} else {  // If no outgoing dependency exists
				this->next = (T*)this;  // Set itself as its own child
				this->depends_on->required_by = (T*)this;  // Update parent's outgoing dependency pointer
				this->prev = nullptr;
			}

			
		} else {  // If there's no incoming dependency
			this->next = (T*)this;  // Set itself as its own child
			this->prev = nullptr;
		}
	}





	// CRUD Operations (inline for speed)
	void add_after(T* new_node) {
		new_node->prev = static_cast<T*>(this);
		new_node->next = this->next;
		if (this->next) this->next->prev = new_node;
		this->next = new_node;
	}


	//parent_task
	void add_dependency(T* parent_task) {

		this->depends_on = parent_task;                      // ParentTask
		this->time = 0;
		this->required_by = 0;
		T* DependencyIn = this->depends_on;
		if ( DependencyIn )
		{
			T* DependencyOut = (T*)DependencyIn->required_by;
			if ( DependencyOut )
			{
				T* v6 = DependencyOut->next;
				this->prev = 0;
				this->next = v6;
				DependencyOut->next->prev = (T*)this;
				DependencyOut->next = (T*)this;
			}
			else
			{
				this->next = (T*)this;
				DependencyIn->required_by = (T*)this;
				this->prev = 0;
			}
		}
		else
		{
			this->next = (T*)this;
			this->prev = 0;
		}
	}


	
	
	

	
	
	void unlink() {
		if (prev) prev->next = next;
		if (next) next->prev = prev;
		if (depends_on && depends_on->required_by == this) {
			depends_on->required_by = next;
		}
		prev = next = depends_on = required_by = nullptr;
	}

};


#include "SimpleNode.inl"