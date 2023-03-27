#include "ArrayStack.h"
#include <iostream>
using namespace std;

/**
 * Constructor de la clase ArrayStack
 */
ArrayStack::ArrayStack() {}

/**
 * Destructor de la clase ArrayStack
 */
ArrayStack::~ArrayStack() {}


/**
 * Ingresa el valor en el ArrayStack.
 * @param {int} valor Es el valor enviado que va a ser ingresado en el ArrayStack.
 * @returns No retorna nada, pero si imprime un mensaje si se logro insertar o no.
 */
void ArrayStack::empujar(int valor) {
	if (this->top < this->tamanio-1) {
		this->top++;
		this->arrayStack[this->top] = valor;
		cout << "El valor fue ingresado de manera exitosa." << endl;
		cout << endl;
	}
	else {
		cout << "El arreglo de pilas esta lleno." << endl;
		cout << endl;
	}
}

/**
 * Saca el valor en la parte superior del ArrayStack.
 * @param No recibe un parametro.
 * @returns No retorna nada, pero si imprime un mensaje si se logro sacar o no.
 */
void ArrayStack::sacar() {
	if (!vacio()) {
		this->arrayStack[this->top--];
		cout << "El valor fue sacado de manera exitosa." << endl;
		cout << endl;
	}
	else {
		cout << "El arreglo de pilas esta vacio." << endl;
		cout << endl;
	}
}

/**
 * Muestra el valor que esta en la parte superior del ArrayStack.
 * @param No recibe un parametro.
 * @returns No retorna nada, pero si imprime el valor que se encuentra en el tope del ArrayStack.
 */
void ArrayStack::verTope() {
	if (!vacio()) {
		cout << "El valor en el tope es: " << this->arrayStack[this->top] << endl;
		cout << endl;
	}
	else {
		cout << "El arreglo de pilas esta vacio." << endl;
		cout << endl;
	}
}

/**
 * Muestra si el ArrayStack esta vacío.
 * @param No recibe un parametro.
 * @returns Retorna un verdadero si el arreglo esta vacío y un falso si no lo esta.
 */
bool ArrayStack::vacio() {
	if (this->top <= -1) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * Imprime todos los elementos del ArrayStack.
 * @param No recibe un parametro.
 * @returns No retorna nada pero si imprime todos los valores que se encuentran en el ArrayStack.
 */
void ArrayStack::imprimir() {
	if (!vacio()) {
		for (int i = -1; i < top; i++) {
			cout << i+2 << ") " << this->arrayStack[i+1] << endl;
		}
		cout << endl;
	}
	else {
		cout << "El arreglo de pilas esta vacio." << endl;
		cout << endl;
	}
}

/**
 * Borra todos los elementos del ArrayStack.
 * @param No recibe un parametro.
 * @returns No retorna nada pero si un mensaje si se borraron todos los valores que se encuentran en el ArrayStack.
 */
void ArrayStack::borrarElementos() {
	if (!vacio()) {
		for (int i = 0; i < top; i++) {
			this->arrayStack[this->top--];
		}
		cout << "Los elementos del arreglo de pilas fueron eliminados" << endl;
	}
	else {
		cout << "El arreglo de pilas esta vacio." << endl;
	}
}