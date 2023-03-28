#pragma once
#include "Object.h"
class Node
{
public:
	Object* valor;
	Node* siguiente;
	Node* anterior;
	Node(Object*);
	~Node();
};

