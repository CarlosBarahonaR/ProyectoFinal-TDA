#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int valor) {
	this->valor = valor;
	this->siguiente = NULL;
}

Node::~Node() {}