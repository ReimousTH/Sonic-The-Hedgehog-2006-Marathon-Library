#pragma  once





namespace Sonicteam{
	namespace SoX{


		//UPDATED	



		template <typename T> // inheritance_only
		struct SimpleLinkNode{
			T* Parent;
			T* Prev;
			T* Next;
			T* Active;
			SimpleLinkNode():Parent( NULL),Prev(NULL),Next(NULL),Active(NULL){}
			void ClearLink(){
				if (Parent)
					Parent->Prev = Prev;
				if (Prev)
					Prev->Next = Parent;
				Prev = NULL;
				Parent = NULL;
				Next = NULL;	
			}
			void Empty(T* root){
				
				if (Active){
					T* current = root;
					T* nextNode = 0;
					do 
					{
						nextNode = current->Next;

						current->Parent = 0;
						current->Prev = 0;
						current->Next = 0;
						current = nextNode;
					} while (nextNode);
					
				}

			} 
			//Separate Between Classes
			void Disconnect(){

				if (Active){
					T* current = root;
					T* nextNode = 0;
					do 
					{
						nextNode = current->Next;
						DisconnectActions();
						current = nextNode;
					} while (nextNode);

				}
			}
			//here for custom class DO Algoright , example 82594590
			void DisconnectActions();

			static T* FindNonActiveNode(T* a1,T* a2){

				T* v3 = a1->Active;
				for ( a1->instance = a2; v3; v3 = v3->Prev )
					a1 = FindNonActiveNode(v3,a2)
				return a1;
			}

				

			void __forceinline  EmptyParent(T* root){
				if (Next == NULL) return;
				T* ParentTask = Next;
				T* PrevTask;
				T* NextTask;
				T* v11;
				if ( ParentTask )
				{
					PrevTask = Prev;
					if ( PrevTask != root ) //a1
					{
						if (ParentTask->Active == root ) //a1
						{
							ParentTask->Active = root->Next;
							root->Prev->Next = 0;
							v11 = root->Next;
							if ( !v11 )
								goto LABEL_12;
						}
						else
						{
							PrevTask->Next = root->Next;
							v11 = root->Next;
							if ( !v11 )
								v11 = root->Parent->Active;
						}
						v11->Prev = root->Prev;
						goto LABEL_12;
					}
					ParentTask->Active = 0;
				}
LABEL_12:
				v11= 0; //just
			}





		};


		template <typename T>
		struct LinkNodeBase {
			T* NThread;
			T* PThread;

		public:
			LinkNodeBase() : NThread(0), PThread(0) {  
				
	//			this->PThread = 0;
	//			this->NThread = (T*)this;
			
			}

			void ClearLink(){
				NThread->PThread = PThread;
				PThread->NThread = NThread;
				PThread = NULL;
				NThread = NULL;

			}
			void Link(){
				this->PThread = (T*)this;
				this->NThread = (T*)this;
			}
			 void RemoveLink(){
				 if (PThread)
					 PThread->NThread = NThread;
				 if (NThread)
					 NThread->PThread = PThread;
			}

			~LinkNodeBase() {
			}
		};

		template <typename T>
		struct LinkNodeBaseA {
			T* ThisObject;
			T* PThread;
			T* NThread;

		public:
			LinkNodeBaseA() : PThread(NULL), NThread(NULL) {}

			void RemoveLink(){
				ThisObject = 0;
				PThread->NThread = NThread;
				NThread->PThread = PThread;
				NThread = NULL;
				PThread = NULL;

			}

			__forceinline ~LinkNodeBaseA() {
				if (PThread)
					PThread->NThread = NThread;
				if (NThread)
					NThread->PThread = PThread;

			}
		};




	
		template <typename T>
		struct LinkNode:LinkNodeBase<LinkNode<T>> {
		public:
			T* TThread;
			LinkNode() {}
			__forceinline ~LinkNode();
			LinkNode(T* TThread) : LinkNodeBase<LinkNode<T>>(),TThread(TThread) {} // use link separated

		


		};

		template <typename T,size_t N>
		struct LinkNodeCounted{
			int count;
			LinkNode<T> _array[N];
		};



		template <typename T>
		struct LinkNodeList:LinkNodeBase<LinkNodeList<T>> {
		public:
			T* TThread;
			LinkNodeList() {this->Link();}
			LinkNodeList(T* TThread) : LinkNodeBase<LinkNodeList<T>>(), TThread(TThread) {this->Link();}

			//More like, little improve of original (sub_82581618)
			int* ForEach(void (*clear_func)(T*));
			int ForEach(int v); //should be static seems, and different in each others

			int EachClear();
			static int EachClearADV(T*);
	
			void Empty();
			void Add(T*);
		};

	



	

		//LOOK MORE, 0x0 T*, 0x4,0x8 (*Without 0x0)
		template <typename T>
		struct LinkNodeA:LinkNodeBaseA<LinkNodeA<T>> {
		public:
			T* TThread;
			LinkNodeA() : LinkNodeBaseA<LinkNodeA<T>>() {}
			LinkNodeA(T* TThread) : LinkNodeBaseA<LinkNodeA<T>>(), TThread(TThread) {}

		};

		



		//LOOK MORE, 0x0 T*, 0x4,0x8 (*Without 0x0)
		template <typename T>
		struct LinkNodeListA:LinkNodeBaseA<LinkNodeListA<T>> {
		public:
			T* TThread;
			LinkNodeListA() : LinkNodeBaseA<LinkNodeListA<T>>() {}
			LinkNodeListA(T* TThread) : LinkNodeBaseA<LinkNodeListA<T>>(), TThread(TThread) {}


			int ForEach(int v); //should be static seems, and different in each others
			void Empty();

		};



	
	













		template <typename T = int>
		class RNodeH {
		public:
			RNodeH* Previous;
			RNodeH* Next;

			inline ~RNodeH(){
				if (this->Previous){
					this->Previous->Next = this->Next;
				}
				if (this->Next){
					this->Next->Previous = this->Previous;
				}
			}
			inline void Reset(){this->Previous->Next = this->Next;this->Next->Previous = this->Previous;this->Next =0;this->Previous = 0;}
			// Constructor
			RNodeH() : Previous(0), Next(0) {}
		};

		template <typename T>
		class RNodeF : public RNodeH<T> {
		public:
			// Constructor
			RNodeF() : RNodeH<T>(), FObject(0) {}
			RNodeF(T* FO) : RNodeH<T>(), FObject(FO) {}
			inline ~RNodeF(){FObject = 0;}
			T* FObject;
		};	

		template <typename T,typename Y>
		class RNodeFH : public RNodeH<T> {
		public:
			// Constructor
			RNodeFH() : RNodeF<T>(), HObject(0) {}
			Y* HObject;
		};	

		//template <typename Z = RNodeF<T>>
		template <typename Z>
		static void RNodeFClear(Z* PREV,Z* NEXT,unsigned int Flag){

			Z* temp = NEXT;
			Z* temp2 = 0;
			if (PREV != NEXT){
				do 
				{
					temp2 = (Z*)(temp->Next);
					temp->FObject->DestroyObject(Flag);
					temp = temp2;
				} while (temp2 != NEXT);
			}
		};

		template <typename Z = RNodeF<T,Y>,typename Y = RNodeH<int>>
		class LinkedNodeListB:Y{
		public:

			LinkedNodeListB(){this->Next = this; this->Previous = this;}
			~LinkedNodeListB()
			{
				Z* temp = (Z*)Next;
				Z* temp2 = 0;
				if ((Z*)this !=(Z*) Next){
					do 
					{
						temp2 = (Z*)(temp->Next);
						temp->Previous = 0;		
						temp->Next = 0;
						temp = temp2;


					} while ((Z*)temp2 != (Z*)this);
				}


			}
		

			//T Have Should have non virtual method OnRNodeHClear, whi

			inline void Clear(){
				Z* temp = (Z*)Next;
				Z* temp2 = 0;
				if ((Z*)this != (Z*)Next){ //Just Do twice for fun later
					do 
					{
						temp2 = (Z*)(temp->Next);		
						temp2->FObject->OnRNodeHClear();
						temp = temp2;
	
					} while ((Z*)temp2 != (Z*)this);
				}

			}

			//used in Component destructor :


		};




	
	};
};


#include "List.inl"


//NEW ONE


