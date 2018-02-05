#include <iostream>
using namespace std;

int main()
{
	int X[2][3]={
		{1,5,6},
		{7,8,3}
	};
	
	cout<<X<<endl;
	cout<<X+1<<endl;
	
	cout<<X[0]<<endl;
	cout<<X[1]<<endl;
	
	cout<<*X<<endl;
	cout<<*(X+1)<<endl;
	
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<< *(*(X+i)+j)<<" ";	
		}
		cout<<endl;
	}
	
	
	return 0;
}