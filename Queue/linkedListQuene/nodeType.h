#ifndef NODE_TYPE
#define NODE_TYPE

template <class Type>
struct nodeType
{
	nodeType<Type> *link;
	Type info;
};



#endif
