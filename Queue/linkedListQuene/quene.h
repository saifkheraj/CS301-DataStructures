#ifndef QUENE_LINKEDLIST
#define QUENE_LINKEDLIST

#include <iostream>
#include <cassert>
#include "nodeType.h"
#include "queneADT.h"

template <class Type>
class Quene : public queneADT<Type>
{
	private:
		nodeType<Type> *queneFront;
		nodeType<Type> *queneRear;

	public:
		Quene();
		bool isEmptyQueue() const;
		bool isFullQueue() const ;
		void initializeQueue() ;
		Type front() const ;
		Type back() const ;
		void addQueue(const Type& newElement) ;
		void deleteQueue() ;
		~Quene();
};

template <class Type>
Quene<Type>::Quene()
{
	queneFront=NULL;
	queneRear=NULL;
}

template <class Type>
bool Quene<Type>::isEmptyQueue() const
{

	return (queneFront==NULL);	
}

template <class Type>
bool Quene<Type>::isFullQueue() const
{
	return false;
}

template <class Type>
void Quene<Type>::initializeQueue()
{
	nodeType<Type> *temp;//to traverse

	if(!isEmptyQueue() )
	{
	
		while(queneFront!=NULL)
		{
			temp=queneFront;
			queneFront=queneFront->link;
			delete temp;
		}

		queneRear=NULL;
	}
}

template <class Type>
Type Quene<Type>::front() const
{
	assert(queneFront!=NULL);
	return queneFront->info;
}

template <class Type>
Type Quene<Type>::back() const 
{
	assert(queneRear!=NULL);
	return queneRear->info;
}

template <class Type>
void Quene<Type>::addQueue(const Type& newElement)
{
	nodeType<Type> *newNode;
	newNode=new nodeType<Type>;
	newNode->info=newElement;

	if(queneFront==NULL)
	{
		queneFront=newNode;
		queneFront->link=NULL;
		queneRear=newNode;
	}
	else
	{
		
		queneRear->link=newNode;
		queneRear=newNode;
		queneRear->link=NULL;

	}
}

template <class Type>
void Quene<Type>::deleteQueue()
{
	nodeType<Type> *temp;
	if(!isEmptyQueue())
	{

		temp=queneFront;

		queneFront=queneFront->link;
		delete temp;

		if(queneFront==NULL)
		{
			queneRear=NULL;
		}
		

	}
	else
	{
		cout<<"The list is not empty";
	}

}

template <class Type>
Quene<Type>::~Quene()
{

	initializeQueue();
}


#endif
