#include "LinkedStack.h"
#include "Object.h"
#include <iostream>
using namespace std;

/**
 * Constructor que inicializa el valor del tope en el LinkedStack.
 */
LinkedStack::LinkedStack() {
	this->top = NULL;
	this->inicio = NULL;
}

/**
 * Destructor de la clase LinkedStack
 */
LinkedStack::~LinkedStack() {}

/**
 * Ingresa el valor en el LinkedStack.
 * @param {int} valor Es el valor enviado que va a ser ingresado en el LinkedStack.
 * @returns No retorna nada, pero si imprime un mensaje si se logro insertar o no.
 */
void LinkedStack::empujar(Object* valor) {
	Node* nodo = new Node(valor);
	//Se hace un if para ver si es el primer nodo ingresado en el LinkedStack
	if (!vacio()) {
		this->top->siguiente = nodo;

		nodo->siguiente = NULL;
		nodo->anterior = this->top;
		this->top = nodo;


		cout << "El valor fue ingresado de manera exitosa." << endl;
		cout << endl;
	}
	else {
		nodo->siguiente = NULL;
		nodo->anterior = NULL;

		this->inicio = nodo;
		this->top = nodo;

		cout << "El valor fue ingresado de manera exitosa." << endl;
		cout << endl;
	}

}

/**
 * Saca el valor en la parte superior del LinkedStack.
 * @param No recibe un parametro.
 * @returns No retorna nada, pero si imprime un mensaje si se logro sacar o no.
 */
void LinkedStack::sacar() {
	Node* nodo = this->top;
	if (!vacio()) {
		this->top->anterior->siguiente = NULL;
		this->top = nodo->anterior;
		delete nodo;
		cout << "El valor fue sacado de manera exitosa." << endl;
		cout << endl;
	} else if (this->top != this->inicio) {
		this->inicio = NULL;
		this->top = NULL;
		delete nodo;
		cout << "El valor fue sacado de manera exitosa." << endl;
		cout << endl;
	} else {
		cout << "El stack esta vacio." << endl;
		cout << endl;
	}
}

/**
 * Muestra el valor que esta en la parte superior del LinkedStack.
 * @param No recibe un parametro.
 * @returns No retorna nada, pero si imprime el valor que se encuentra en el tope del LinkedStack.
 */
void LinkedStack::verTope() {
	if (!vacio()) {
		cout << "El valor en el tope es: " << this->top->valor->toString() << endl;
		cout << endl;
	}
	else {
		cout << "El stack esta vacio." << endl;
		cout << endl;
	}
}

/**
 * Muestra si el LinkedStack esta vacío al revisar si el nodo del inicio es nulo.
 * @param No recibe un parametro.
 * @returns Retorna un verdadero si el arreglo esta vacío y un falso si no lo esta.
 */
bool LinkedStack::vacio() {
	if (this->inicio == NULL) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * Imprime todos los elementos del LinkedStack.
 * @param No recibe un parametro.
 * @returns No retorna nada pero si imprime todos los valores que se encuentran en el LinkedStack.
 */
void LinkedStack::imprimir() {
	if (!vacio()) {
		Node* nodo;
		
		nodo = this->inicio;

		do {
			int i = 1;
			cout << i << ") " << nodo->valor->toString() << endl;

			nodo = nodo->siguiente;
			i++;
		} while (nodo!=NULL);

		cout << endl;
	}
	else {
		cout << "El stack esta vacio." << endl;
		cout << endl;
	}
}

/**
 * Borra todos los elementos del LinkedStack.
 * @param No recibe un parametro.
 * @returns No retorna nada pero si un mensaje si se borraron todos los valores que se encuentran en el LinkedStack.
 */
void LinkedStack::borrarElementos() {
	if (!vacio()) {
		Node* nodo;

		nodo = this->inicio;

		do {
			this->inicio = nodo->siguiente;
			delete nodo;
			nodo = this->inicio;



		} while (nodo != NULL);

		this->inicio = NULL;

		cout << endl;
		cout << "Los elementos del stack fueron eliminados" << endl;
	}
	else {
		cout << "El stack esta vacio." << endl;
	}
}