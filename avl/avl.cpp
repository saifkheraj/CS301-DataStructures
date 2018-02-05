#include <iostream>
using namespace std;

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
		int Max(Type num1, Type num2); 
		
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
	//cout<<root->info;
	
}

template <class Type>
int AvlTree<Type>::Max(Type num1, Type num2)
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


int main()
{
	AvlTree<int> avl;
	avl.insertIntoTree(3);
 	avl.insertIntoTree(2);
  	avl.insertIntoTree(1);
 	avl.insertIntoTree(4);
  	avl.insertIntoTree(5);
 	avl.insertIntoTree(6);
 	avl.insertIntoTree(7);
 	avl.insertIntoTree(16);
 	avl.insertIntoTree(15);
 	avl.insertIntoTree(14);
 	avl.insertIntoTree(13);
 	avl.insertIntoTree(12);
 	avl.insertIntoTree(11);
 	avl.insertIntoTree(10);
 	avl.insertIntoTree(8);
 	
 	avl.printInorder();

return 0;
}
