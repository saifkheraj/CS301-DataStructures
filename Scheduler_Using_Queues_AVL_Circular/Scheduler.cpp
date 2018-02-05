#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

template <class Type>
struct Node
{
	Node<Type> *link;
	Type info;
};



//simple linear queue using linked list because it is more efficient in terms of free locations 
template <class Type>
class Queue
{
	private:
		Node<Type> *queueFront;
		Node<Type> *queueRear;

	public:
		Queue();
		bool isEmptyQueue();
		bool isFullQueue();
		void destroyQueue();
		Type front();
		Type back();
		void enqueue(Type& newElement) ;
		Type dequeue() ;
		~Queue();
};

template <class Type>
Queue<Type>::Queue()
{
	queueFront=NULL;
	queueRear=NULL;
}

template <class Type>
bool Queue<Type>::isEmptyQueue()
{

	return (queueFront==NULL);	
}

template <class Type>
bool Queue<Type>::isFullQueue()
{
	return false;
}

template <class Type>
void Queue<Type>::destroyQueue()
{
	Node<Type> *temp;//to traverse

	if(!isEmptyQueue() )
	{
	
		while(queueFront!=NULL)
		{
			temp=queueFront;
			queueFront=queueFront->link;
			delete temp;
		}

		queueRear=NULL;
	}
}

template <class Type>
Type Queue<Type>::front()
{
	if(queueFront!=NULL)
		return queueFront->info;
}

template <class Type>
Type Queue<Type>::back()
{
	if(queueRear!=NULL)
		return queueRear->info;
}

template <class Type>
void Queue<Type>::enqueue(Type& newElement)
{
	Node<Type> *newNode;
	newNode=new Node<Type>;
	newNode->info=newElement;

	if(queueFront==NULL)
	{
		queueFront=newNode;
		queueFront->link=NULL;
		queueRear=newNode;
	}
	else
	{
		
		queueRear->link=newNode;
		queueRear=newNode;
		queueRear->link=NULL;

	}
}

template <class Type>
Type Queue<Type>::dequeue()
{
	Node<Type> *temp;
	if(!isEmptyQueue())
	{

		temp=queueFront;
		Type returnValue=queueFront->info;
		queueFront=queueFront->link;
		delete temp;

		if(queueFront==NULL)
		{
			queueRear=NULL;
		}
		
		return returnValue;

	}

}

template <class Type>
Queue<Type>::~Queue()
{

	destroyQueue();
}

/* SIMPLE QUEUE ENDS */



/* CIRCULAR QUEUE STARTS USING POINTER  */

template <class Type>
class CircularQueue
{
	private:
		Node<Type> *back;	//to maintain circular link
	
	public:
		CircularQueue();
		bool isEmptyQueue() const;
		void enqueue(Type& newElement) ;
		Type dequeue() ;
		~CircularQueue();
};

template <class Type>
bool CircularQueue<Type>::isEmptyQueue() const
{

	return (back==NULL);
}

template <class Type>
CircularQueue<Type>::CircularQueue()
{
	back=NULL;
}

template <class Type>
CircularQueue<Type>::~CircularQueue()
{

	Node<Type> *temp;//to traverse

			if(!isEmptyQueue() )
			{
	
				while(back!=NULL)
				{
					temp=back;
					back=back->link;
					delete temp;
				}

			}
		
			


}

template <class Type>
void CircularQueue<Type>::enqueue(Type& newElement)
{
	Node<Type> *newNode;
	newNode=new Node<Type>;
	newNode->info=newElement;
	
	if(back==NULL)
	{
		newNode->link=newNode; 	//pointing to itself
		back=newNode;
	}
	else
	{
		newNode->link=back->link;
		back->link=newNode;
		back=newNode;	
	}
}

template <class Type>
Type CircularQueue<Type>::dequeue()
{
	Node<Type> *temp;
	
	if(back!=NULL)
	{
	
		if(back->link==back)
		{
			temp=back->link;
			Type returnValue=temp->info;
			if(temp==back)		//if only 1 node exist
			{
				back=NULL;
			}
			
			delete temp;
			
			return returnValue;
		}
		else		//if more than 1 node exist
		{
	
			temp=back->link;
			Type returnValue=temp->info;
			back->link=temp->link;
			delete temp;
	
			return returnValue;
	
		}
	}
	
	

}

/*CIRCULAR QUEUE ENDS */


/* AVL tree starts */


template <class Type>
struct AvlNode
{

	Type info;
	AvlNode *left;
	AvlNode *right;
	
	int height;

};




template <class Type>
class AvlTree
{
	private:
		AvlNode<Type> *root;
		
		int Height(AvlNode<Type> *node);		
		AvlNode<Type> *insert(Type item,AvlNode<Type> *node);
		AvlNode<Type> *singleRotateRight(AvlNode<Type> *node);
		
		AvlNode<Type> *doubleRotateRight(AvlNode<Type> *node);
		AvlNode<Type> *singleRotateLeft(AvlNode<Type> *node);
		AvlNode<Type> *doubleRotateLeft(AvlNode<Type> *node);
		int Max(int num1, int num2); 
		
		void inorder(AvlNode<Type> *current);
		void destroyTree(AvlNode<Type> *current);
	
	public:
		AvlTree();
		void insertIntoTree(Type item);
		void printInorder();
		
		~AvlTree();
		
		
		
	


};

template <class Type>
AvlTree<Type>::AvlTree()
{
	root=NULL;
}

template <class Type>
AvlTree<Type>::~AvlTree()
{
	destroyTree(root);

}

template <class Type>
void AvlTree<Type>::destroyTree(AvlNode<Type> *current)
{
	if(current!=NULL)
	{
		destroyTree(current->left);
		destroyTree(current->right);
		
		delete current;
	
	
	}

}

template <class Type>
int AvlTree<Type>::Height(AvlNode<Type> *node)
{

			if(node==NULL)
				return -1;
			else
				return node->height;
		

}


template <class Type>
void AvlTree<Type>::inorder(AvlNode<Type> *current)
{

	if(current!=NULL)
	{
		inorder(current->left);
		cout<<current->info<<" ";
		inorder(current->right);
	}
}

template <class Type>
void AvlTree<Type>::printInorder()
{
	inorder(root);
	
}

template <class Type>
int AvlTree<Type>::Max(int num1, int num2)
{
	int temp;
 
  	 if (num1 > num2)
      		temp = num1;
 	 else
      		temp = num2;
 
   return temp;

}

template <class Type>
AvlNode<Type>*  AvlTree<Type>::insert(Type item,AvlNode<Type> *node)
{
	if(node==NULL)
	{
		node=new AvlNode<Type>;
		node->info=item;
		node->height=0;
		node->left=node->right=NULL;	
	}
	else
	{
		if(item<node->info)
		{
			node->left=insert(item,node->left);
			if( ( Height(node->left)-Height(node->right) )==2)
			{
				if(item<node->left->info)
				
					node=singleRotateLeft(node);
				
				else
					node=doubleRotateLeft(node);
			
			}
			
		}
		else if(item>node->info)
		{
			node->right=insert(item,node->right);
			if( (Height(node->right)-Height(node->left) )==2)
			{
				if(item>node->right->info)
				
					node=singleRotateRight(node);
				
				else
					node=doubleRotateRight(node);
			
			
			
			}
		
		
		
		}
	
	}
	
	
	//update height
	
	node->height=Max( Height(node->left),Height(node->right) ) + 1;

	return node;
}

template <class Type>
void AvlTree<Type>::insertIntoTree(Type item)
{
	
	root=insert(item,root);

}

template <class Type>
AvlNode<Type>* AvlTree<Type>::singleRotateRight(AvlNode<Type> *PPtr)
{
    AvlNode<Type> *BPtr;

    BPtr = PPtr->right;
    PPtr->right = BPtr->left;
    BPtr->left = PPtr;
    PPtr->height = Max( Height(PPtr->left), Height(PPtr->right) ) + 1;
    BPtr->height = Max( Height(BPtr->right), PPtr->height ) + 1;
    return BPtr;  

}

template <class Type>
AvlNode<Type>* AvlTree<Type>::doubleRotateRight(AvlNode<Type> *PPtr)
{

    PPtr->right = singleRotateLeft( PPtr->right );
    return singleRotateRight(PPtr);
}

template <class Type>
AvlNode<Type>* AvlTree<Type>::singleRotateLeft(AvlNode<Type> *PPtr)
{
	AvlNode<Type>* APtr;

 	APtr = PPtr->left;
	PPtr->left = APtr->right;
	APtr->right = PPtr;
   	PPtr->height = Max( Height(PPtr->left), Height(PPtr->right) ) + 1;
   	APtr->height = Max( Height(APtr->left), PPtr->height ) + 1;
   
   	return APtr;  

}

template <class Type>
AvlNode<Type>* AvlTree<Type>::doubleRotateLeft(AvlNode<Type> *PPtr)
{
     PPtr->left = singleRotateRight( PPtr->left );
     return singleRotateLeft( PPtr );
}

/*AVL TREE ENDS */


/*processInfo starts stores basic info such as name of task and cpu time which is then enqueued to the queue */

struct processInfo
{

	string nameOfTask;
	double timeOfTask;
	string arrivaltime;
	
	processInfo()
	{
		nameOfTask="";
		timeOfTask=0;
	}
	
	friend ostream& operator<< (ostream &out, processInfo &info);
	bool operator<(const processInfo& info);
	bool operator>(const processInfo& info);
	bool operator==(const processInfo& info);
	
};


ostream& operator<< (ostream &out, processInfo &info)
{
	
    	out<<"ProcessID/Name: "<<info.nameOfTask<<endl;
    	out<<"Arrival Time "<<info.arrivaltime;
    	out<<"Time Of Task: "<<info.timeOfTask<<endl;
    	out<<"execution completed successfully"<<endl;
    	
    	
    	cout<<endl;
    	
    	return out;
}

//overloading operators so that it can be used with generic class and template.
bool processInfo::operator <(const processInfo& info)
{
	return (timeOfTask<info.timeOfTask);

}

bool processInfo::operator >(const processInfo& info)
{
	return (timeOfTask>info.timeOfTask);
}

bool processInfo::operator==(const processInfo& info)
{
	return (timeOfTask==info.timeOfTask);

}
/*Process info ends */

/*ROUND ROBIN STARTS IMPLEMENTS CIRCULAR QUEUE */
class RoundRobin
{

	private:
		CircularQueue<processInfo> rrQueue;
	
	public:
		RoundRobin();
		void sumulator();
		void addToScheduler(processInfo *info,int numTask);
};

RoundRobin::RoundRobin()
{
	//this is just for initializing

}

void RoundRobin::sumulator()
{
	/*in round robin, if the time of cpu is greater than 10, it will be served upto 10 and remaining time will be queued again to process so goes on until queue is empty */


	processInfo temp;
	
	while(!rrQueue.isEmptyQueue())
	{
		temp=rrQueue.dequeue();
		
		if(temp.timeOfTask>10)
		{
			cout<<"ProcessID/Name: "<<temp.nameOfTask<<endl;
			cout<<"Arrival Time: "<<temp.arrivaltime;
			cout<<"CPU TIME: "<<10<<"ms"<<endl;
			cout<<"Interuppted after 10ms"<<endl;
			
			temp.timeOfTask-=10;
			cout<<"Remaining CPU Time: "<<temp.timeOfTask<<"ms, Process is going back in queue."<<endl;
			cout<<endl;
			rrQueue.enqueue(temp);	
		
		}
		else
		{
			cout<<"ProcessID/Name: "<<temp.nameOfTask<<endl;
			cout<<"Arrival Time: "<<temp.arrivaltime;
			cout<<"CPU Time: "<<temp.timeOfTask<<endl;
			cout<<"Task successfully ended"<<endl;
			cout<<endl;
		}
	
	}
	

}

void RoundRobin::addToScheduler(processInfo *info,int numTask)
{
	for(int i=0;i<numTask;i++)
	{
		
		rrQueue.enqueue(info[i]);	
	
	}
}

/*ROUND ROBIN ENDS */


/*FCFS starts here */

class FCFS
{
	private:
		Queue<processInfo> fcfsQueue;
	
	
	public:
		FCFS();
		void addToScheduler(processInfo *info,int numTask);
		void sumulator(); 	
};



FCFS::FCFS()
{
	
}


void FCFS::addToScheduler(processInfo *info,int numTask)
{
	for(int i=0;i<numTask;i++)
	{
		
		fcfsQueue.enqueue(info[i]);	
	
	}

}


void FCFS::sumulator()
{
	processInfo temp;

	
	//in fcfs processes will be served based on first come first serve so according to simple queue and not on priority bases
	
	while(!fcfsQueue.isEmptyQueue())
	{
		
		temp=fcfsQueue.dequeue();	//get peeked element
		cout<<"Process ID/Name: "<<temp.nameOfTask<<endl;
		cout<<"Arrival Time: "<<temp.arrivaltime;
		cout<<"CPU Time: "<<temp.timeOfTask<<endl;
		cout<<"Execution Completed"<<endl;
	
		cout<<endl;
	}

} 	


/* FCFS ENDS*/


/*CFS STARTS HERE */

class CFS
{
	
	private:
		
		AvlTree<processInfo> cfsQueue;
	
	public:
		CFS();
		void sumulator();
		void addToScheduler(processInfo *info,int numTask);
			

};

CFS::CFS()
{
	//just initializing the constructor
}


void CFS::sumulator()
{
	/*sumulator : processes will served which has small time first according to inorder traversal, which
	is used specifically for first going towards small and then large so process with small time will be served first*/

	cfsQueue.printInorder();	
}


void CFS::addToScheduler(processInfo *info,int numTask)
{

	//adding to the scheduler in the queue for cfs avl is used

	for(int i=0;i<numTask;i++)
	{
		
		cfsQueue.insertIntoTree(info[i]);	
	
	}
}


/*CFS ENDS */






//function to get processes

void getTask(processInfo *info, int numTask);



int main()
{
	processInfo *info;

	int numTask;

	//because this is a menu based program we need to first store the information of processes within list that I have stored
	//in struct and then user will choose which type of scheduler to be performed 

	cout<<"Enter Number of tasks"<<endl;	
	cin>>numTask;	//get number of task
	
	
	info=new processInfo[numTask];	//allocate memory
	
	getTask(info, numTask);
	
	//initializing objects for fcfs, rr and cfs
	FCFS fcfs_scheduler;
	RoundRobin roundrobin;
	CFS cfs;
	
	//below will be the menu
	
	int option;
	char sentinal;
	
	
	
	//scheduler menu comes here
	
	do
	{
		cout<<"-----------------Scheduler Menu---------------"<<endl;
		cout<<"1. FCFS (First Come First Serve)"<<endl;
		cout<<"2. Round Robin (RR)"<<endl;
		cout<<"3. Completely Fair Scheduler (CFS)"<<endl;
		
		cin>>option;
		
		
		switch(option)
		{
			case 1:
				//FCFS
				
				fcfs_scheduler.addToScheduler(info,numTask);
				fcfs_scheduler.sumulator();
			
				break;
			case 2:
				//RR
				roundrobin.addToScheduler(info,numTask);
				roundrobin.sumulator();
				break;
				
			case 3:
				//CFS
				cfs.addToScheduler(info,numTask);
				cfs.sumulator();
				break;
		
			default:
				cout<<"Sorry you entered incorrect option"<<endl;
		
		}
	
	cout<<"Do you want to go to Scheduler Menu again, press c to go or any key to exit"<<endl;
	cin>>sentinal;		
	
	}while(sentinal=='c' || sentinal=='C');
	
	
	//scheduler menu ends
	
	//free memory
	delete[] info;

return 0;
}



//get task and informatio from the user
void getTask(processInfo *info, int numTask)
{



	//for local current time for arrival
	time_t strtime;
 	struct tm * informationOfTime;

	string name;	//name of the task
	double taskTime;	//time of the task 

	for(int i=0;i<numTask;i++)
	{
		cout<<"Enter the name of task number "<<i+1<<" : ";
		cin>>name;
		cout<<"Enter the time for "<<name<<" : ";
		cin>>taskTime;
		
		
		time (&strtime);
  		informationOfTime=localtime(&strtime);
  		int milli=strtime/1000;
  	
		string arrivaltime=asctime(informationOfTime);	//store time in string
		
		//store in struct of process accordingly
		info[i].nameOfTask=name;
		info[i].timeOfTask=taskTime;
		info[i].arrivaltime=arrivaltime;		
	}



}
