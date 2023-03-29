#include "LinkedQueue.h"
#include <iostream>
using namespace std;

// constructor

LinkedQueue::LinkedQueue()
{
	this->front = NULL;
	this->back = NULL;
}

// destructor

LinkedQueue :: ~LinkedQueue() {

	if (front)
		delete front;
}

// vacia todos los elementos de la cola

void LinkedQueue :: Vaciar() {
	front = NULL;
	back = NULL;
}

// al ser una cola se imprime el primer valor agregado primero y el ultimo valor agregado por ultimo

void LinkedQueue::Imprimir() {
	Node* temp = front;
	if (!EstaVacia()) {
		while (temp != NULL) {
			cout << temp->valor->toString();
			temp = temp->siguiente;
		}
	}
}

Node* LinkedQueue::Frente() {
	Node* Nodo = NULL;
	if (!EstaVacia()) {
		cout<<front->valor->toString();
	}
	return Nodo;
}

// si esta vacia la cola retornara verdadero, de lo contrario retornara falso

bool LinkedQueue::EstaVacia() {
	if (front == nullptr && back == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

// pone el ultimo elemento que se encola en el back, el ultimo elemento puesto se agrega en el back

void LinkedQueue::Encolar(Object* elemento) {
	if (!EstaVacia()) {
		Node* temp = new Node(elemento);
		back->siguiente = temp;
		back = temp;
	}
	else {
		front = new Node(elemento);
		back = front;
	}
}

// desencola el ultimo puesto en el back
	Node* LinkedQueue::Desencolar() {
		if (!EstaVacia()) {
			// Almacena el front anterior
			// y mueve front un nodo adelante
			Node* temp = front;
			front = front->siguiente;

			// Si front se vuelve NULL
			// back también se cambia a NULL
			if (front == NULL) {
				back = NULL;
			}

			cout << temp->valor->toString();

			return temp;

			delete (temp);
		}
		return nullptr;
	}
