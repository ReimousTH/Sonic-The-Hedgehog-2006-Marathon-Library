#pragma  once



namespace Sonicteam{
	namespace SoX{


	

		template <typename T>
		Sonicteam::SoX::LinkNode<T>::~LinkNode()
		{

		
		}



		template <typename T>
		int* Sonicteam::SoX::LinkNodeList<T>::ForEach(void (*clear_func)(T*))
		{
			Sonicteam::SoX::LinkNodeList<T>* PThread_1 = this->PThread;
			Sonicteam::SoX::LinkNodeList<T>* RootComp = this; 
			Sonicteam::SoX::LinkNodeList<T>* v10; 
			T* v9;
			if ( this->PThread != this )
			{
				do
				{
					v9 = PThread_1->TThread;
					v10 = PThread_1->PThread;
					if ( v9 )
						clear_func(v9);
					PThread_1 = v10;
				}
				while ( v10 != RootComp );
			}

			return 0;
		}


		//should be 
		template <typename T>
		int Sonicteam::SoX::LinkNodeList<T>::ForEach(int v)
		{
	
			Sonicteam::SoX::LinkNodeList<T>* PThread_1 = this->PThread;
			Sonicteam::SoX::LinkNodeList<T>* RootComp = this; 
			Sonicteam::SoX::LinkNodeList<T>* v10; 
			T* v9;
			if ( this->PThread != this )
			{
				do
				{
					v9 = PThread_1->TThread;
					v10 = PThread_1->PThread;
					if ( v9 )
						v9->DestroyObject(1);
					PThread_1 = v10;
				}
				while ( v10 != RootComp );
			}

			return v;
		
		}


		template <typename T>
		int Sonicteam::SoX::LinkNodeList<T>::EachClear()
		{
			Sonicteam::SoX::LinkNodeList<T>* PThread_1 = this->PThread;
			Sonicteam::SoX::LinkNodeList<T>* RootComp = this; 
			Sonicteam::SoX::LinkNodeList<T>* v10; 
			T* v9;
			if ( this->PThread != this )
			{
				do
				{
					v9 = PThread_1->TThread;
					v10 = PThread_1->PThread;
					EachClearADV(v9);
					PThread_1 = v10;
				}
				while ( v10 != RootComp );
			}

			return v;

		}



		template <typename T>
		int Sonicteam::SoX::LinkNodeList<T>::EachClearADV(T*)
		{
			return 0;
		}


		template <typename T>
		void Sonicteam::SoX::LinkNodeList<T>::Empty()
		{

			Sonicteam::SoX::LinkNodeList<T> *v1; // r11
			Sonicteam::SoX::LinkNodeList<T> *v2; // r10
			Sonicteam::SoX::LinkNodeList<T> *v3; // r11

			v1 = this->PThread;
			if ( v1 != this )
			{
				do
				{
					v2 = v1->PThread;
					v1->NThread = 0;
					v1->PThread = 0;
					v1 = v2;
				}
				while ( v2 != this );
			}
			if ( this->NThread )
				this->NThread->PThread = this->PThread;
			v3 = this->PThread;
			if ( v3 )
				v3->NThread = this->NThread;

		}


		template <typename T>
		void Sonicteam::SoX::LinkNodeList<T>::Add(T* element)
		{
 
		}



	

	};

		
};



//NEW ONE


