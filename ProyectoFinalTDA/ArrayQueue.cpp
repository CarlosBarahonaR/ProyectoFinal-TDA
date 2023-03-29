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
 * Muestra el tama�o del ArrayQueue.
 * @param No recibe ning�n parametro.
 * @returns Retorna un entero, el cual contiene el tama�o del ArrayQueue.
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
	//No dejar que la cola crezca m�s que (tama�o m�ximo -1)
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
 * @param No recibe ning�n parametro.
 * @returns Retorna el elemento que se sac�.
 */
Object* ArrayQueue::Desencolar()
{
	if (EstaVacia()) {
		cout << "!La cola esta vacia\n";
		return nullptr;
	}

	Object* temp = Cola[front];

	cout << temp->toString();

	//Si el �ltimo elemento es desencolado
	//la cola retornar� a su estado inicial
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
 * @param No recibe ning�n parametro.
 * @returns Retorna el elemento de la parte frontal del ArrayQueue.
 */
Object* ArrayQueue::Frente()
{
	if (!EstaVacia()) {
		return Cola[front];
	}
	return NULL;
}

/*
 * Muestra si el ArrayQueue est� vac�o.
 * @param No recibe ning�n parametro.
 * @returns Retorna TRUE si el ArrayQueue esta vac�o y FALSE si no lo est�.
 */
bool ArrayQueue::EstaVacia()
{
	return (back == -1) ? true : false;
}

/*
 * Borra todos los elementos del ArrayQueue.
 * @param No recibe ning�n parametro.
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
 * @param No recibe ning�n parametro.
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