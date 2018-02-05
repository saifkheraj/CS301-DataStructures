#ifndef QUENE_ARRAY
#define QUENE_ARRAY

#include "queneADT.h"
#include <cassert>

//change the name of quene to queue

template  <class Type>
class quene : public queneADT<Type>
{
	private:
		int queneFront;
		int queneRear;
		int count;
		int maxQueneSize;
		Type *list;
	public:
		quene(int size);
		~quene();
		bool isEmptyQueue() const;
		bool isFullQueue() const;
		void initializeQueue();
		Type front()const;	
		Type back() const ;
		void addQueue(const Type& newElement);
		void deleteQueue(); 

};

template <class Type>
quene<Type>::quene(int size)
{
	if(size<=0)
	{
		cout<<"you entered negative or less than equal to zero"<<endl;
		cout<<"initializing list of 100";
		maxQueneSize=100;
		
			
		
	}
	else
	{
		this->maxQueneSize=size;
		list=new Type[maxQueneSize];	
		
	}

	list=new Type[maxQueneSize];
	count=0;
	queneFront=0;
	queneRear=maxQueneSize-1;
}

template <class Type>
quene<Type>::~quene()
{
	delete [] list;
}

template <class Type>
bool quene<Type>::isEmptyQueue() const
{
	return (count==0);
}

template <class Type>
bool quene<Type>::isFullQueue() const
{
	return (count==maxQueneSize);
}

template <class Type>
void quene<Type>::initializeQueue()
{
	count=0;
	queneFront=0;
	queneRear=maxQueneSize-1;
}

template <class Type>
Type quene<Type>::front()const
{
	assert(!isEmptyQueue());
	return list[queneFront];
}

template <class Type>
Type quene<Type>::back() const
{
	assert(!isEmptyQueue());
	return list[queneRear];
}

template <class Type>
void quene<Type>::addQueue(const Type& newElement)
{
	if( !isFullQueue() )
	{
		//new element enters from queneRear and exits from queueFront in Queue system
		
		//finding index number in the circular index		
		queneRear=(queneRear+1) % maxQueneSize;
		count++;
		list[queneRear]=newElement;


	}
	else
	{
		cout<<"The list is full"<<endl;
	}

}

template <class Type>
void quene<Type>::deleteQueue()
{
	if(!isEmptyQueue())
	{
		queneFront=(queneFront+1) % maxQueneSize;
		count--;
	}
	else	
	{
		cout<<"The list is empty"<<endl;
	}
}

#endif
