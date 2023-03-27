#include <iostream>
#include "ArrayQueue.h"
using namespace std;
/*
 * Constructor de la clase ArrayQueue
 */
ArrayQueue::ArrayQueue()
{
	this->front = -1;
	this->back = -1;
}

/*
 * Destructor de la clase ArrayQueue
 */
ArrayQueue::~ArrayQueue() {

}

/*
 * Muestra el tamaño del ArrayQueue.
 * @param No recibe ningún parametro.
 * @returns Retorna un entero, el cual contiene el tamaño del ArrayQueue.
 */
int ArrayQueue::Size()
{
	if (back == -1) {
		return 0;
	}

	if (back < front) {
		return MAX_SIZE - (front - back) + 1;
	}

	return back - front + 1;
}

/*
 * Ingresa el objeto al ArrayQueue.
 * @param {Object* elemento} Es el elemento que se recibe para ingresarlo al ArrayQueue.
 * @returns No retorna nada.
 */
void ArrayQueue::Encolar(Object* elemento)
{
	//No dejar que la cola crezca más que (tamaño máximo -1)
	if (Size() == MAX_SIZE) {
		cout << "Se ha llegado al tamanio maximo\n";
		return;
	}

	//El % se utiliza para que back pueda ir alrededor
	back = (back + 1) % MAX_SIZE;
	Cola[back] = elemento;

	if (front == -1) {
		front = 0;
	}

}

/*
 * Saca el elemento en la parte frontal del ArrayQueue.
 * @param No recibe ningún parametro.
 * @returns Retorna el elemento que se sacó.
 */
Object* ArrayQueue::Desencolar()
{
	if (EstaVacia()) {
		cout << "!La cola esta vacia\n";
		return nullptr;
	}

	Object* temp = Cola[front];

	cout << temp->toString();

	//Si el último elemento es desencolado
	//la cola retornará a su estado inicial
	if (front == back) {
		front = -1;
		back = -1;
		return temp;
	}

	//El % se utiliza para que front pueda ir alrededor
	front = (front + 1) % MAX_SIZE;

	return temp;
}

/*
 * Muestra el elemento en la parte frontal del ArrayQueue.
 * @param No recibe ningún parametro.
 * @returns Retorna el elemento de la parte frontal del ArrayQueue.
 */
Object* ArrayQueue::Frente()
{
	if (!EstaVacia()) {
		return Cola[front];
	}
}

/*
 * Muestra si el ArrayQueue está vacío.
 * @param No recibe ningún parametro.
 * @returns Retorna TRUE si el ArrayQueue esta vacío y FALSE si no lo está.
 */
bool ArrayQueue::EstaVacia()
{
	return (back == -1) ? true : false;
}

/*
 * Borra todos los elementos del ArrayQueue.
 * @param No recibe ningún parametro.
 * @returns No retorna nada.
 */
void ArrayQueue::Vaciar() {

	if (!EstaVacia()) {
		for (int i = back; i < front; i++) {
			delete Cola[i];
		}
		front = -1;
		back = -1;
	}
}

/*
 * Imprime todos los elementos del ArrayQueue.
 * @param No recibe ningún parametro.
 * @returns No retorna nada pero si imprime todos los valores que se encuentran en el ArrayQueue.
 */
void ArrayQueue::Imprimir()
{
	if (!EstaVacia()) {
		for (int i = front; i <= back; i++) {
			cout << "Objeto #" << i << ": " << endl;
			cout << Cola[i]->toString() << endl;
		}
	}
}