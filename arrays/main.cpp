#include <iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
	int a=5;
	ArrayList<int> list1(20);
	ArrayList<int> list2(20);
	ArrayList<int> list3(20);
	list1.insertAtFirst(5);
	list1.insertAtFirst(5);
	list1.insertAtFirst(6);
	list1.insertAtFirst(4);
		
	list1.print();
	list2=list1;
	
	list2.print();
	

	
	//long *abc=new long[1000000000000000];


return 0;
}
