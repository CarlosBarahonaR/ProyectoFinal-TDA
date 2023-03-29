#pragma once
#include "Object.h"
#include "Node.h"
class LinkedQueue {
	Node* front;
	Node* back;
public:
	LinkedQueue();
	~LinkedQueue();
	void Encolar(Object* elemento);
	Node* Desencolar();
	Node* Frente();
	void Imprimir();
	void Vaciar();
	bool EstaVacia();
};

