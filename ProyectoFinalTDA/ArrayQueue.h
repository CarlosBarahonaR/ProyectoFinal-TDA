#pragma once
#include "Object.h"
const int MAX_SIZE = 100;

class ArrayQueue {
	//Declaración de atributos para la clase ArrayQueue
	Object* Cola[MAX_SIZE];
	int front;
	int back;
public:
	//Declaración de constructor y destructor para la clase ArrayQueue
	ArrayQueue();
	~ArrayQueue();

	//Declaración de métodos para la clase ArrayQueue
	int Size();
	void Encolar(Object* element);
	Object* Desencolar();
	Object* Frente();
	bool EstaVacia();
	void Vaciar();
	void Imprimir();
};