#pragma once
using namespace std;
class ArrayStack
{
	int arrayStack[100];
	int tamanio = 100;
	int top = -1;
public:
	//Declaración de constructor y destructor
	ArrayStack();
	~ArrayStack();
	//Declaración de metodos de pilas
	void empujar(int);
	void sacar();
	void verTope();
	bool vacio();
	void imprimir();
	void borrarElementos();
};

