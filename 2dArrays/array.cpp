#include <iostream>
using namespace std;\

int main()
{
	int myArray[]={10,20,30,40,50};
	
	cout<<"Base Address"<<endl;
	
	cout<<myArray<<endl;
	cout<<myArray+1<<endl;
	cout<<myArray+2<<endl;
	
	
	//using pointer to store address
	//ptr holds the address of first element
	int *ptr=myArray;
	cout<<ptr<<endl;
	cout<<*ptr<<endl;
	
	cout<< *(ptr+1)<<endl;
	
	
	//I can use pointer to print whole array in loop
	
	for(int i=0;i<5;i++)
	{
		cout<< *(ptr+i)<<" ";	
	}
	cout<<endl;
	

return 0;

}