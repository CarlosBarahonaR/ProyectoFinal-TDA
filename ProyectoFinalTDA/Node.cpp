#include "Node.h"
#include <iostream>
#include "Object.h"

using namespace std;

Node::Node(Object* valor) {
	this->valor = valor;
	this->siguiente = NULL;
	this->anterior = NULL;
}

Node::~Node() {}