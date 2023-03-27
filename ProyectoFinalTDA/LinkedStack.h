#pragma once
#include "Node.h"
class LinkedStack
{
	Node* top;
public:
	LinkedStack();
	~LinkedStack();
	//Declaración de metodos de pilas
	void empujar(int);
	void sacar();
	void verTope();
	bool vacio();
	void imprimir();
	void borrarElementos();
};

