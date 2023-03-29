#ifndef NODE_H
#define NODE_H
#include "Object.h"
class Node {
public:
	Object* valor;
	Node* siguiente;
	Node* anterior;
	Node();
	Node(Object*);
	~Node();
	Object* getData() const;
	Node* getAnterior() const;
	Node* getSiguiente() const;
	Object* setData(Object*);
	void setAnterior(Node*);
	void setSiguiente(Node*);
};
#endif

