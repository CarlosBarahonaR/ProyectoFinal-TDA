#pragma once
using namespace std;
class ArrayStack
{
	int arrayStack[100];
	int tamanio = 100;
	int top = -1;
public:
	//Declaraci�n de constructor y destructor
	ArrayStack();
	~ArrayStack();
	//Declaraci�n de metodos de pilas
	void empujar(int);
	void sacar();
	void verTope();
	bool vacio();
	void imprimir();
	void borrarElementos();
};
