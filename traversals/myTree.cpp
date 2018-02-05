#include <iostream>
using namespace std;



template <class Type>
struct TreeNode
{
	TreeNode<Type> *left;
	Type data;
	TreeNode<Type> *right;
};



template <class Type>
class myTree
{
	private:
		TreeNode<Type> *root;
		void inorder(TreeNode<Type> *);
		void preorder(TreeNode<Type> *);
		void postorder(TreeNode<Type> *);
		
	public:
		myTree();//default constructor
		void insert(Type data);
		void printInorder();
		void printPreorder();
		void printPostorder();
		int leavesCount(TreeNode<Type> *current)
		{
			if(current==NULL)
			{
			
				return 1;
			}
			else
			{
				return ( leavesCount(current->left)+leavesCount(current->right) );
			}
		
		}
		
		void printLeaves()
		{
		
			cout<<leavesCount(root)<<endl;
		}
		
		
		int sum(TreeNode<Type> *current)
		{
			if(current!=NULL)
			{
				return current->data+( sum(current->left)+sum(current->right) );
				
			}
			else
			{
				return 0;
			}
		}
		
		void printsum()
		{
			cout<<sum(root)<<endl;
		}
		~myTree();
		
};

template <class Type>
myTree<Type>::~myTree()
{
	delete root;
}


template <class Type>
myTree<Type>::myTree()
{
	root=NULL;
}

template <class Type>
void myTree<Type>::inorder(TreeNode<Type> *current)
{

	if(current!=NULL)
	{
		inorder(current->left);
		cout<<current->data<<" ";
		inorder(current->right);
	}
}

template <class Type>
void myTree<Type>::preorder(TreeNode<Type> *current)
{

	if(current!=NULL)
	{
		cout<<current->data<<" ";
		preorder(current->left);
		preorder(current->right);
	}
}


template <class Type>
void myTree<Type>::postorder(TreeNode<Type> *current)
{

	if(current!=NULL)
	{
		postorder(current->left);
		postorder(current->right);
		cout<<current->data<<" ";
	}
}


template <class Type>
void myTree<Type>::printInorder()
{
	inorder(root);
}


template <class Type>
void myTree<Type>::printPreorder()
{
	preorder(root);
}

template <class Type>
void myTree<Type>::printPostorder()
{
	postorder(root);
}



template <class Type>
void myTree<Type>::insert(Type item)
{
	
	TreeNode<Type> *newNode;
	newNode=new TreeNode<Type>;
	newNode->data=item;
	newNode->left=NULL;
	newNode->right=NULL;

	
	if(root==NULL)
	{
		root=newNode;	
	}
	else
	{
		TreeNode<Type> *current=root;
		TreeNode<Type> *trail;
		
		while(current!=NULL)
		{
			if(item>current->data)
			{
				//traverse right
				trail=current;
				current=current->right;
				
			
			}
			else
			{
				//traverse left
				trail=current;			
				current=current->left;
			}
		}
		
		
		if(item>=trail->data)
		{
			trail->right=newNode;
		
		}
		else
		{
			trail->left=newNode;
		}
	}
}




int main()
{

	myTree<int> tree1;
	
	
	
	tree1.insert(78);
	tree1.insert(26);
	tree1.insert(94);
	tree1.insert(23);
	tree1.insert(43);
	tree1.insert(97);
	//tree1.insert('F');
	
	tree1.printsum();
	tree1.printLeaves();
	
	tree1.printPreorder();
	cout<<endl;

return 0;
}
