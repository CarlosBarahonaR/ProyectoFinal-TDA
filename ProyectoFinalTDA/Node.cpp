#include "Node.h"
#include <iostream>
#include "Object.h"

using namespace std;

Node::Node() {
	anterior = NULL;
	valor = NULL;
	siguiente = NULL;
}

Node::Node(Object* valor) {
	this->valor = valor;
	this->siguiente = NULL;
	this->anterior = NULL;
}

Node::~Node() {
	if (siguiente != NULL)
		delete siguiente;
	if (valor != NULL)
		delete valor;
}

Object* Node::getData() const {
	return valor;
}

Node* Node::getSiguiente() const {
	return siguiente;
}

Node* Node::getAnterior() const {
	return anterior;
}

Object* Node::setData(Object* data) {
	return this->valor = data;
}

void Node::setAnterior(Node* anterior) {
	this->anterior = anterior;
}

void Node::setSiguiente(Node* siguiente) {
	this->siguiente = siguiente;
}