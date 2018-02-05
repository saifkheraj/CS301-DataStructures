#include <iostream>
#include "BinaryTree.h"
using namespace std;


int main()
{
	int a=1;
	int b=2;
	int c=3;
	int d=4;
	int e=5;
	int f=6;


	BinaryTree<int> tree1;
	tree1.insert(f);
	tree1.insert(a);
	tree1.insert(b);
	tree1.insert(c);
	tree1.insert(e);
	tree1.insert(d);


	tree1.inorderTraversal();


	cout<<endl;


	tree1.postorderTraversal();


return 0;
}
