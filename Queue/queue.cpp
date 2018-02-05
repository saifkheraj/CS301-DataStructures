#include <iostream>
using namespace std;

class IntQueue
{
private:
	int *queueArray;
	int queueSize;
	int front;
	int rear;
	int numItems;
public:
	IntQueue(int);
   	~IntQueue(void);
   	void enqueue(int);
   	int dequeue(void);
   	bool isEmpty(void);
   	bool isFull(void);
   	void clear(void);
};



IntQueue::IntQueue(int s) //constructor
{
	queueArray = new int[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;
}

IntQueue::~IntQueue(void) //destructor
{
 delete [] queueArray;
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************

void IntQueue::enqueue(int num)
{
	if (isFull())
		cout << "The queue is full.\n";
	else
	{
		// Calculate the new rear position
		rear = (rear + 1) % queueSize;
		// Insert new item
		queueArray[rear] = num;
		// Update item count
		numItems++;
	}
	
	cout<<rear<<endl;
	cout<<front<<endl;
}

//*********************************************
// Function dequeue removes the value at the  *
// front of the queue, and copies t into num. *
//*********************************************

int IntQueue::dequeue(void)
{
	if (isEmpty())
		cout << "The queue is empty.\n";
	else
	{
		// Move front
		front = (front + 1) % queueSize;
		// Retrieve the front item
		int num = queueArray[front];
		// Update item count
		numItems--;
		
		cout<<front<<endl;
		cout<<rear<<endl;
		return num;
	}
	
	
	
	
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************

bool IntQueue::isEmpty(void)
{
	if (numItems)
		return false;
	else
		return true;
}


//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise.             *
//********************************************

bool IntQueue::isFull(void)
{
	if (numItems < queueSize)
		return false;
	else
		return true;
}


//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0.         *
//*******************************************

void IntQueue::clear(void)
{
	front = - 1;
	rear = - 1;
	numItems = 0;
}


//Program demonstrating the IntQueue class
int main(void)
{
	IntQueue iQueue(5);

	cout << "Enqueuing 5 items...\n";
	// Enqueue 5 items.
	for (int x = 0; x < 5; x++)
		iQueue.enqueue(x);


	iQueue.dequeue();
	iQueue.dequeue();
	
	
	iQueue.enqueue(10);
	
	iQueue.dequeue();

}
	
