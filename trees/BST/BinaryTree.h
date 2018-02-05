#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include "NodeType.h"
using namespace std;



template <class Type>
class BinaryTree
{
	private:
		NodeType<Type> *root;
		void copyTree(NodeType<Type> *&CopyTree, NodeType<Type> *otherTree);
		void inorder(NodeType<Type> *p);
		void preorder(NodeType<Type> *p);
		void postorder(NodeType<Type> *p);
		int height(NodeType<Type> *p);
		int nodeCount(NodeType<Type> *p);
		int leavesCount(NodeType<Type> *p);
		void destroy(NodeType<Type> *&p);

	public:
		BinaryTree();
		BinaryTree(BinaryTree &otherTree);
		~BinaryTree();

		BinaryTree& operator=(const BinaryTree &otherTree);
		

		bool isEmpty()const;

		void inorderTraversal();
		void preorderTraversal();
		void postorderTraversal();
		

		int max(int x, int y);
		
		int treeHeight();
		
		int treeNodeCount();
		
		int treeLeavesCount()const;

		
		void insert(Type& otherItem);
};


template <class Type>
BinaryTree<Type>::BinaryTree()
{
	root=NULL;
}

template <class Type>
BinaryTree<Type>::BinaryTree(BinaryTree &otherTree)
{
	if(otherTree==NULL)
		root=NULL;
	else
		copyTree(root,otherTree.root);
}

template <class Type>
BinaryTree<Type>::~BinaryTree()
{
	destroy(root);
}

template <class Type>
BinaryTree<Type>& BinaryTree<Type>::operator=(const BinaryTree &otherTree)
{
	if(this!=&otherTree)
	{
		if(root!=NULL)
			destroy(root);
		copyTree(root,otherTree.root);
	}

	return *this;
}


template <class Type>
void BinaryTree<Type>::copyTree(NodeType<Type> *&CopyTree, NodeType<Type> *otherTreeRoot)
{
	if(otherTreeRoot==NULL)
		CopyTree=NULL;
	else
	{
		CopyTree=new NodeType<Type>;
		CopyTree->info=otherTreeRoot->info;
		copyTree(CopyTree->left,otherTreeRoot->left);
		copyTree(CopyTree->right, otherTreeRoot->right);

	}


}

template <class Type>
bool BinaryTree<Type>::isEmpty()const
{
	return (root==NULL);
}


template <class Type>
void BinaryTree<Type>::inorder(NodeType<Type> *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->info<<" ";
		inorder(p->right);
	}
}

template <class Type>
void BinaryTree<Type>::preorder(NodeType<Type> *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

template <class Type>
void BinaryTree<Type>::postorder(NodeType<Type> *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->info<<" ";
	}

}

template <class Type>
void BinaryTree<Type>::inorderTraversal()
{

	inorder(root);

}

template <class Type>
void BinaryTree<Type>::preorderTraversal()
{
	preorder(root);

}

template <class Type>
void BinaryTree<Type>::postorderTraversal()
{
	postorder(root);

}

template <class Type>
int BinaryTree<Type>::max(int x, int y)
{
	if(x>=y)
		return x;
	else
		return y;
}

template <class Type>
int BinaryTree<Type>::height(NodeType<Type> *p)
{

	if(p==NULL)
		return 0;
	else
		return 1+max(height(p->right),height(p->left));

}

template <class Type>
int BinaryTree<Type>::treeHeight()
{
	return height(root);
}

template <class Type>
int BinaryTree<Type>::nodeCount(NodeType<Type> *p)
{

	if(p==NULL)
		return 0;
	else
		return 1+(nodeCount(p->left)+nodeCount(p->right));

}

template <class Type>
int BinaryTree<Type>::treeNodeCount()
{

	return nodeCount(root);
}

template <class Type>
int BinaryTree<Type>::leavesCount(NodeType<Type> *p)
{
	if(p==NULL)
		return 1;
	else
		return leavesCount(p->left)+leavesCount(p->right);
}


template <class Type>
int BinaryTree<Type>::treeLeavesCount()const
{
	return leavesCount(root);
}

template <class Type>
void BinaryTree<Type>::destroy(NodeType<Type> *&p)
{

	if(p!=NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p=NULL;
	}
}

template <class Type>
void BinaryTree<Type>::insert(Type& otherItem)
{
	NodeType<Type> *current;
	NodeType<Type> *trailCurrent;
	NodeType<Type> *newNode;


	newNode=new NodeType<Type>;
	newNode->info=otherItem;
	newNode->left=NULL;
	newNode->right=NULL;

	if(root==NULL)
		root=newNode;
	else
	{
		current=root;

		while(current!=NULL)
		{
			trailCurrent=current;

			if(current->info==otherItem)
				cout<<"Cannot insert duplicate"<<endl;
			if(current->info>otherItem)
				current=current->left;
			else
				current=current->right;
		}


		if(trailCurrent->info>otherItem)
			trailCurrent->left=newNode;
		else
			trailCurrent->right=newNode;
	}
}
#endif
