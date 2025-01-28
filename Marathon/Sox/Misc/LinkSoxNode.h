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
		return *this->Next;
	}


	iterator operator++(int) {
		return this->Next
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
	void Disconnect(){
		this->Previous->Next = (T*)this->Next;
		this->Next->Previous = (T*)this->Previous;
	}
	void InitLink(){
		Previous = this;
		Next = this;
	}

};

/*
for (LinkSoxNode<int>::iterator* it = uber++;it != uber;it++){
int* val = it->_this;
}
*/
template <typename T>
class LinkSoxNode : public LinkSoxNodeTemplateIterator<LinkSoxNode<T>> {
public:
	T* _this; // Pointer to the current node

	typedef LinkSoxNode<T> iterator;
	LinkSoxNode(){}
	LinkSoxNode(T* t):LinkSoxNodeTemplateIterator<LinkSoxNode<T>>(),_this(t){}


};





