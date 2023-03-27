#include "LinkList.h"
#include "iostream"

LinkList::LinkList(){
  inicio = NULL;
  fin = NULL;
}
LinkList::~LinkList(){}

bool LinkList::inserta(Object* data, int posicion){
  // Caso en el que se desea insertar fuera del rango
  if (posicion < 1 || posicion > size + 1)
    return false;
  Node* nodoInsertar = new Node(data);

  // Caso en el que se inserta en inicio con cero elementos
  if (size == 0 && posicion == 1){
    inicio = nodoInsertar;
    fin = nodoInsertar;
    size++;
    return true;
  }
  
  // Caso en que se inserta en inicio con x elementos
  if (posicion == 1)
  {
    inicio->setAnterior(nodoInsertar);
    nodoInsertar->setSiguiente(inicio);
    inicio = nodoInsertar;
    size++;
    return true;
  }

  // Caso en que se inserta al final
  if (posicion == size + 1)
  {
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

bool LinkList::append(Object* data){
  return inserta(data, size+1);
}

int LinkList::localiza(Object* data){
  Node* nodo = inicio;
  for (int i = 1; i <= size; i++)
  {
    Object* dataNodo = nodo->getData();
    if (dataNodo->toString() == data->toString())
      return i;
    nodo = nodo->getSiguiente();
  }
  return -1;
}

Object* LinkList::recupera(int posicion){
  if (posicion < 1 || posicion > size)
    return NULL;
  Node* nodo = inicio;
  for (int i = 1; i < posicion; i++)
  {
    nodo = nodo->getSiguiente();
  }
  return nodo->getData();
}

Object* LinkList::suprime(int posicion){
  if (posicion < 1 || posicion > size)
    return NULL;
  Node* nodo = inicio;
  Object* retorno;
  for (int i = 1; i < posicion; i++)
  {
    if (nodo->getSiguiente() != NULL)
    {
      nodo = nodo->getSiguiente();
    }
  }
  
  retorno = nodo->getData();
  nodo->setData(NULL);

  if (posicion == 1 && size == 1){
    inicio = NULL;
    fin = NULL;
    size = 0;
    delete nodo;
    return retorno;
  }

  if (posicion == 1 && size > 1)
  {
    Node* nuevoInicio = nodo->getSiguiente();
    nuevoInicio->setAnterior(NULL);
    inicio = nuevoInicio;
    nodo->setSiguiente(NULL);
    nodo->setAnterior(NULL);
    delete nodo;
    size--;
    return retorno;
  }

  if (posicion == size && size > 1)
  {
    Node* nuevoFinal = fin->getAnterior();
    nuevoFinal->setSiguiente(NULL);
    nodo->setAnterior(NULL);
    fin = nuevoFinal;
    delete nodo;
    size--;
    return retorno;
  }
  
  if (posicion > 1 && posicion < size)
  {
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

void LinkList::anula(){
  if (size > 0){
    delete inicio;
    inicio = NULL;
    fin = NULL;
    size = 0;
  }

}
Object* LinkList::primero(){
  if (size > 0)
    return inicio->getData();
  return NULL;
}

Object* LinkList::anterior(int posicion){
  return recupera(posicion - 1);
}
Object* LinkList::siguiente(int posicion){
  return recupera(posicion + 1);
}
bool LinkList::vacia(){
  return size == 0;
}
void LinkList::imprime(){
  if (vacia())
  std::cout << "No hay elementos presentes en la lista" << std::endl;
  else{
    Node* temp = inicio;
    for (int i = 1; i < size; i++)
    {
      std::cout << temp->getData()->toString() << std::endl;
      if (temp->getSiguiente() != NULL)
        temp = temp->getSiguiente(); 
    }
  }
}