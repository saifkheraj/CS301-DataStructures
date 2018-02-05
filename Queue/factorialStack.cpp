#include <iostream>
using namespace std;


template <class Type>
struct Node
{
	Type data;
	Node<Type> *next;
};


template <class Type>
class stack
{
	private:
		Node <Type> *Top;
		int stacklength;
	public:
		stack();
		~stack();		
		bool isEmpty()const;
		void push(Type item);	
		Type pop();
		Type top()const;
};


template <class Type>
stack<Type>::stack()
{
	Top=NULL;
	stacklength=0;
}

template <class Type>
stack<Type>::~stack()
{
	Node<Type> *temp;
	while(Top!=NULL)
	{
		//free memory
		temp=Top;
		Top=Top->next;
		delete temp;
	}
}

template <class Type>
bool stack<Type>::isEmpty()const
{
	return (Top==NULL);
}

template <class Type>
void stack<Type>::push(Type item)
{
	//will be inserted at the stack top
	//we make a new node, insert data into it, and point it to the top to link 		//it to the node that was at the top before, then make Top point to the 	//newNode
	Node<Type> *NewNode=new Node<Type>;
	NewNode->data=item;
	NewNode->next=Top;
	Top=NewNode;
	stacklength++;
}

template <class Type>
Type stack<Type>::pop()
{
	if(Top==NULL)
	{
		cout<<"empty"<<endl;
	}
	else
	{
		Type value;
		Node<Type> *temp=Top;
		value=Top->data;
		Top=Top->next;
		delete temp;
		
		stacklength--;
		
		return value;
	}
}

template <class Type>
Type stack<Type>::top()const
{
	if(Top!=NULL)
	{
		return Top->data;
	}
}

void func(int num,stack<int> s1)
{

	
}


int main()
{
	stack<int> s1;
	int num;
	
	cout<<"enter number";
	cin>>num;
	
	s1.push(-1);
	
	for(int i=num;i>=1;i--)
	{
		s1.push(i);
	}
	
	
	int value1,value2;
	int result=0;
	
	
	/*
	while(s1.top()!=-1)
	{
		value1=s1.pop();
		value2=s1.pop();
		result=value1*value2;
		s1.push(result);
	}

	*/
	
	
	while(!s1.isEmpty())
	{
		value1=s1.pop();
		value2=s1.pop();
		
		if(value1==-1 || value2==-1)
			break;
		
		result=value1*value2;
		
		
		s1.push(result);
	}
	

	cout<<result<<endl;
	

}
