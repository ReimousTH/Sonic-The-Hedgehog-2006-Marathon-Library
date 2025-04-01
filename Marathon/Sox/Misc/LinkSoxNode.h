#pragma once



template <typename T>
class LinkSoxNodeTemplateIterator {
public:
	T* Previous; 
	T* Next;

	LinkSoxNodeTemplateIterator(){
	}
	

	typedef LinkSoxNodeTemplateIterator<T> iterator;



	iterator& operator++() {
		return *static_cast<iterator*>(this->Next);
	}

	iterator operator++(int) {
		iterator temp = *this;
		this->Next = static_cast<T*>(this->Next); // Move to the next node
		return temp;
	}

	bool operator!=(const iterator& other) const {
		return this != &other;
	}


	void Connect(iterator* nextNode){

		nextNode->Previous->Next =  (T*)this;

		this->Next = (T*)nextNode;
		this->Previous = (T*)nextNode->Previous;


		nextNode->Previous = (T*)this;

	}
	//ListComponent, LinkComponent
	__inline  void Attach(iterator* nextNode){
		nextNode->Previous = (T*)this;
		nextNode->Next = (T*)this->Next;
		this->Next->Previous = (T*)nextNode;
		this->Next = (T*)nextNode;
	}

	//No Save Handle
	void Disconnect(){
		this->Previous->Next = (T*)this->Next;
		this->Next->Previous = (T*)this->Previous;
	}
	// With Safe
	void SafeDisconnect(){
		if (this->Previous) this->Previous->Next = (T*)this->Next;
		if (this->Next) this->Next->Previous = (T*)this->Previous;
	}
	void Empty() {
		
		for (iterator* it = static_cast<iterator*>(this->Next); it != static_cast<iterator*>(this); ) {
			iterator* next = it->Next; 
			it->Clear();                
			it = next;                
		}
		SafeDisconnect();
	}
	void Clear(){
		this->Previous = 0;
		this->Next = 0;
	}
	void InitLink(){
		Previous = (T*)this;
		Next = (T*)this;
	}

	//special
	
};

/*
for (LinkSoxNode<int>::iterator* it = uber++;it != uber;it++){
int* val = it->_this;
}
*/
template <typename T>
class LinkSoxNode : public LinkSoxNodeTemplateIterator<LinkSoxNode<T>> {
public:

	LinkSoxNode& operator++() {
		return *static_cast<LinkSoxNode*>(this->Next);
	}

	LinkSoxNode operator++(int) {
		LinkSoxNode temp = *static_cast<LinkSoxNode*>(this); // Create a copy
		this->Next = static_cast<LinkSoxNode*>(this->Next); // Move to the next node
		return temp;
	}


	T* _this; // Pointer to the current node
	typedef LinkSoxNode<T> iterator;
	LinkSoxNode(){}
	LinkSoxNode(T* t):LinkSoxNodeTemplateIterator<LinkSoxNode<T>>(),_this(t){}
	void* DestroyObject(unsigned int flag);
	void ForEachNode(void (*func)(T*)) ;

};

//sub_82581618, refuse to make exactly same as original, because exta do not even used in game
template <typename T>
void LinkSoxNode<T>::ForEachNode(void (*func)(T*))
{
	for (iterator* it = static_cast<iterator*>(this->Next); it != static_cast<iterator*>(this); ) {
		iterator* next = it->Next; 
		func(it->_this);
		it = next;                
	}
}

template <typename T>
void* LinkSoxNode<T>::DestroyObject(unsigned int flag)
{

	for (iterator* it = static_cast<iterator*>(this->Next); it != static_cast<iterator*>(this); ) {
		iterator* next = it->Next; 
		if (it->_this) it->_this->DestroyObject(1);
		it = next;                
	}
	return reinterpret_cast<void*>(flag);
}




