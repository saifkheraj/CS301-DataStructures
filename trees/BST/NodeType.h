#ifndef NODE_TYPE
#define NODE_TYPE


template <class Type>
struct NodeType
{
	Type info;	
	NodeType<Type> *left;
	NodeType<Type> *right;
};


#endif
