#include "LinkList.h"
#include "iostream"
#include "Object.h"
#include "Node.h"
/*
* Contructor Linklist
*/
LinkList::LinkList() {
	inicio = NULL;
	fin = NULL;
}

/*
* Destructor Arraylist
*/
LinkList::~LinkList() {}

/*
* Funcion que inserta de un objecto en la lista
* @param {data} es tipo Object
* @param {posicion} posicion en la cual se insertara el elemento
*/
bool LinkList::inserta(Object* data, int posicion) {
	// Caso en el que se desea insertar fuera del rango
	if (posicion < 1 || posicion > size + 1)
		return false;
	Node* nodoInsertar = new Node(data);

	// Caso en el que se inserta en inicio con cero elementos
	if (size == 0 && posicion == 1) {
		inicio = nodoInsertar;
		fin = nodoInsertar;
		size++;
		return true;
	}

	// Caso en que se inserta en inicio con x elementos
	if (posicion == 1) {
		inicio->setAnterior(nodoInsertar);
		nodoInsertar->setSiguiente(inicio);
		inicio = nodoInsertar;
		size++;
		return true;
	}

	// Caso en que se inserta al final
	if (posicion == size + 1) {
		Node* nodoAnterior = fin;
		nodoInsertar->setAnterior(nodoAnterior);
		nodoAnterior->setSiguiente(nodoInsertar);
		fin = nodoInsertar;
		size++;
		return true;
	}

	Node* nodoUbicado = inicio;
	for (int i = 1; i < posicion; i++)
		nodoUbicado = nodoUbicado->getSiguiente();
	Node* nodoAnterior = nodoUbicado->getAnterior();
	nodoInsertar->setAnterior(nodoAnterior);
	nodoInsertar->setSiguiente(nodoUbicado);
	nodoUbicado->setAnterior(nodoInsertar);
	nodoAnterior->setSiguiente(nodoInsertar);
	size++;
	return true;
}

/*
* Funcion para agregar al final de lista
* @param {data} es tipo Object
*/
bool LinkList::append(Object* data) {
	return inserta(data, size + 1);
}

/*
* Funcion que localiza si un objecto esta en la lista
* @param {data} es tipo Object
*/
int LinkList::localiza(Object* data) {
	Node* nodo = inicio;
	for (int i = 1; i <= size; i++) {
		Object* dataNodo = nodo->getData();
		if (dataNodo->toString() == data->toString())
			return i;
		nodo = nodo->getSiguiente();
	}
	return -1;
}

/*
* Funcion que devuelve un Objecto de la lista en base a un posicion
* @param {posicion} es tipo entero
*/
Object* LinkList::recupera(int posicion) {
	if (posicion < 1 || posicion > size)
		return NULL;
	Node* nodo = inicio;
	for (int i = 1; i < posicion; i++) {
		nodo = nodo->getSiguiente();
	}
	return nodo->getData();
}

/*
* Funcion que suprime un objecto de la lista de una posicion en especifo
* @param {data} es tipo Object
* @return {Object} retorna un Objecto que alocado en el heap
*/
Object* LinkList::suprime(int posicion) {
	if (posicion < 1 || posicion > size)
		return NULL;
	Node* nodo = inicio;
	Object* retorno;
	for (int i = 1; i < posicion; i++) {
		if (nodo->getSiguiente() != NULL) {
			nodo = nodo->getSiguiente();
		}
	}

	retorno = nodo->getData();
	nodo->setData(NULL);

	if (posicion == 1 && size == 1) {
		inicio = NULL;
		fin = NULL;
		size = 0;
		delete nodo;
		return retorno;
	}

	if (posicion == 1 && size > 1) {
		Node* nuevoInicio = nodo->getSiguiente();
		nuevoInicio->setAnterior(NULL);
		inicio = nuevoInicio;
		nodo->setSiguiente(NULL);
		nodo->setAnterior(NULL);
		delete nodo;
		size--;
		return retorno;
	}

	if (posicion == size && size > 1) {
		Node* nuevoFinal = fin->getAnterior();
		nuevoFinal->setSiguiente(NULL);
		nodo->setAnterior(NULL);
		fin = nuevoFinal;
		delete nodo;
		size--;
		return retorno;
	}

	if (posicion > 1 && posicion < size) {
		Node* nodoAnterior = nodo->getAnterior();
		Node* nodoSiguiente = nodo->getSiguiente();
		nodo->setAnterior(NULL);
		nodo->setSiguiente(NULL);
		nodoAnterior->setSiguiente(nodoSiguiente);
		nodoSiguiente->setAnterior(nodoAnterior);
		delete nodo;
		size--;
		return retorno;
	}
	return NULL;
}

/*
* Funcion que borra todo los elementos de la lista
* @param {data} es tipo Object
*/
void LinkList::anula() {
	if (size > 0) {
		delete inicio;
		inicio = NULL;
		fin = NULL;
		size = 0;
	}

}

/*
* Funcion que devuelve el primer objecto en la lista
* @param {data} es tipo Object
* @return tipo Objecto
*/
Object* LinkList::primero() {
	if (size > 0)
		return inicio->getData();
	return NULL;
}

/*
* Funcion que devuelve el objecto anterior de la lista de un posicion
* @param {posicion} es tipo int
* @return tipo Objecto
*/
Object* LinkList::anterior(int posicion) {
	return recupera(posicion - 1);
}

/*
* Funcion que devuelve el objecto siguiente de la lista de un posicion
* @param {posicion} es tipo int
* @return tipo Objecto
*/
Object* LinkList::siguiente(int posicion) {
	return recupera(posicion + 1);
}

/*
* Funcion que indica si la lista esta vacia
*/
bool LinkList::vacia() {
	return size == 0;
}

/*
* Funcion que imprime todo los elementos si la lista no esta vacia
*/
void LinkList::imprime() {
	if (vacia())
		std::cout << "No hay elementos presentes en la lista" << std::endl;
	else {
		Node* temp = inicio;
		for (int i = 1; i <= size; i++) {
			std::cout << i << ". " << temp->getData()->toString() << std::endl;
			if (temp->getSiguiente() != NULL)
				temp = temp->getSiguiente();
		}
	}
}