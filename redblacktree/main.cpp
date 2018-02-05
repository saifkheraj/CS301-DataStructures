#include <iostream>
using namespace std;


class RBTree;

class TreeNode
{
public:
	TreeNode(int newData)
	{
		data = newData;
		left = NULL;
		right = NULL;
		color = 0;
		parent = NULL;
	}

private:

	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	int color;
	friend class RBTree;
};

class RBTree
{
public:
	RBTree()
	{
		root = NULL;
	}
	void Insert(int data)
	{
		if(root==NULL)
			{
			root = new TreeNode(data);
			root->color = 1;
			}
		else
			Insert(data,root, NULL);
	}


private:

	
	void Insert(int data, TreeNode* nodePtr, TreeNode* parent)
	{
		if(data < nodePtr->data)
		{
			if(nodePtr->left==NULL)
				{
				nodePtr->left = new TreeNode(data);
				nodePtr->left->parent = nodePtr;
				FixInsert(nodePtr->left);
				}
			else
				Insert(data, nodePtr->left, nodePtr);
		}

		else if(data > nodePtr->data)
		{
			if(nodePtr->right==NULL)
				{
				nodePtr->right = new TreeNode(data);
				nodePtr->right->parent = nodePtr;
				FixInsert(nodePtr->right);
				}
			else
				Insert(data, nodePtr->right, nodePtr);
		}
		else
			cout << "duplicate not allowed" << endl;

	
	}

	void FixInsert(TreeNode* z)
	{
		while(z!=NULL && z->parent!=NULL && z->parent->color==0)
		{
			if(z->parent==NULL || z->parent->parent==NULL)
				return;
			
			if(z->parent == z->parent->parent->left)
			{
				TreeNode* y = z->parent->parent->right;
				if(y!=NULL && y->color==0) // case #1
				{
					z->parent->color = 1;
					y->color = 1;
					z->parent->parent->color = 0;
					z = z->parent->parent;
					
				}
				else
				{
					if(z == z->parent->right) // case #2
					{
						z = z->parent;
						LEFT_ROTATE(z);
					}
					z->parent->color = 1; // case#3
					z->parent->parent->color = 0;
					RIGHT_ROTATE(z->parent->parent);
				}	
			}
			else
			{
				TreeNode* y = z->parent->parent->left;
				if(y!=NULL && y->color==0) // case #1
				{
					z->parent->color = 1;
					y->color = 1;
					z->parent->parent->color = 0;
					z = z->parent->parent;
					
				}
				else
				{
					if(z == z->parent->left) // case #2
					{
						z = z->parent;
						RIGHT_ROTATE(z);
					}
					z->parent->color = 1; // case#3
					z->parent->parent->color = 0;
					LEFT_ROTATE(z->parent->parent);
				}	
			}
		}
		root->color = 1;
	
	}

	void LEFT_ROTATE(TreeNode* x)
	{
		if(x==NULL)
			return;

		TreeNode* y = x->right; // set y

		if(y!=NULL)	
		{
			x->right = y->left; 
			y->parent = x->parent;
		}

		if(x->parent==NULL)
			root = y;

		else if(x==x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		if(y!=NULL)	
			y->left = x;

		x->parent = y;

	}

	void RIGHT_ROTATE(TreeNode* y)
	{
		if(y==NULL)
			return;
		
		TreeNode* x = y->left; 

		
		if(x!=NULL)
		{
			y->left = x->right; 
			x->parent = y->parent;
		}

		if(y->parent==NULL)
			root = x;
		else if(y==y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;

		if(x!=NULL)
			x->right = y;

		y->parent = x;

		
	}

	
private:

	TreeNode*  root;
};

int main()
{
	int array1[] = {5,7,4,1,2,22,21,23,9,8,44,55,67,33,456,231};

	RBTree tree;

	for(int i = 0 ; i < sizeof(array1)/sizeof(int) ; i++)
		tree.Insert(array1[i]);


	



	return 0;

}