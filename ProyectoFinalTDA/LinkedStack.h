#pragma once
#include "Node.h"
#include "Object.h"
class LinkedStack
{
	Node* top;
	Node* inicio;
public:
	LinkedStack();
	~LinkedStack();
	//Declaración de metodos de pilas
	void empujar(Object*);
	void sacar();
	void verTope();
	bool vacio();
	void imprimir();
	void borrarElementos();
};

