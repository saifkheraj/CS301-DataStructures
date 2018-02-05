#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
class ArrayList
{

	private:
		int maxSize;
		int length;
		Type *array;

	public:
		ArrayList(int size=100);
		~ArrayList();
		ArrayList& operator=(ArrayList<Type> & obj);
		void print()const;
		bool isEmpty()const;
		bool isFull()const;
		int listSize()const;
		int maxListSize()const;
		void sort();
		int search(Type searchItem);
		void insertAtFirst(Type item);
		void insertAtTop(Type& item);
		void insert(int location, Type item);
		void deleteItem(Type item);
		ArrayList<Type> operator+(ArrayList<Type> & otherList);
};


template <class Type>
ArrayList<Type>::ArrayList(int size)
{
	if(size<=0)
	{
		cout<<"size cannot be less than 0";

		maxSize=100;
		array=new Type[maxSize];

	}
	else
	{
		maxSize=size;
		length=0;
		array=new Type[maxSize];

		

	}

	
}

template <class Type>
ArrayList<Type>::~ArrayList()
{
	delete[] array;
}


template <class Type>
ArrayList<Type> ArrayList<Type>::operator+(ArrayList<Type> & otherList)
{
	
	ArrayList<Type> temp;

	temp.maxSize=maxSize+otherList.maxSize;
	temp.length=length+otherList.length;

	temp.array=new Type[temp.maxSize];

	int j=0;
	for(int i=0;i<length;i++)
	{
		temp.array[j]=array[i];
		j++;
	}

	for(int i=0;i<otherList.length;i++)
	{
		temp.array[j]=otherList.array[i];
		j++;
	}



	return temp;
}

template <class Type>
ArrayList<Type> & ArrayList<Type>::operator=(ArrayList<Type> & obj)
{
	if(this!=&obj)
	{
		if(array!=NULL)
			delete[] array;
		array=new Type[obj.maxSize];

		for(int i=0;i<obj.length;i++)
			array[i]=obj.array[i];
		this->maxSize=obj.maxSize;
		this->length=obj.length;
	}
	return *this;
}

template <class Type>
void ArrayList<Type>::print()const
{
	if(length!=0)
	{
		for(int i=0;i<length;i++)
			cout<<array[i]<<" ";
		cout<<endl;


	}
}

template <class Type>
bool ArrayList<Type>::isEmpty()const
{
	return (length==0);
}

template <class Type>
bool ArrayList<Type>::isFull()const
{
	return (length==maxSize);
}

template <class Type>
int ArrayList<Type>::listSize()const
{
	return length;
}

template <class Type>
int ArrayList<Type>::maxListSize()const
{
	return maxSize;
}

template <class Type>
void ArrayList<Type>::sort()
{
	assert(length!=0);
	Type temp;
	
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-1;j++)
		{	
			if(array[j+1]<array[j])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;

			}
		}
	}
}

template <class Type>
int ArrayList<Type>::search(Type searchItem)
{

	if(length!=0)
	{
		bool flag=false;

		int i=0;


		for(;i<length;i++)
		{	
			if(array[i]==searchItem)
			{
				flag=true;
				break;

			}

		}


		if(flag)
			return i;

	}
}

template <class Type>
void ArrayList<Type>::insertAtFirst(Type item)
{
	if(length!=maxSize)
	{

		if(length==0)
		{
			array[0]=item;
			length++;

		}
		else
		{

			int i=length;


			for(;i>0;i--)
			{
				array[i]=array[i-1];
				

			}
		
		array[i]=item;
		length++;


		}
	
	}
}

template <class Type>
void ArrayList<Type>::insertAtTop(Type& item)
{
	if(length!=maxSize)
	{
		array[length]=item;
		length++;
	}
}

template <class Type>
void ArrayList<Type>::insert(int location, Type item)
{
	if(length!=maxSize)
	{
		int i=length;

		for(;i>location;i--)
			array[i]=array[i-1];

		array[i]=item;
		length++;
	}

}

template <class Type>
void ArrayList<Type>::deleteItem(Type item)
{
	bool flag=false;

	int location=0;
	for(;location<length;location++)
	{
		if(array[location]==item)
		{
			flag=true;
			break;

		}
	}


	if(flag)
	{
		int i=location;


		for(;i<length-1;i++)
		{
			array[i]=array[i+1];

		}

		length--;
	}
	else
		cout<<"Item not in the list"<<endl;
}


#endif
