#include "ArrayList.h"
#include <iostream>
#include "Object.h"
using std::cout;
using std::endl;
/*
* Contructor Arraylist
*/
ArrayList::ArrayList()
{
  this->capacidad = 10000;
  array = new Object*[capacidad];
  size = 0;
  for (int i = 0; i < capacidad; i++)
    array[i] = NULL;
}

/*
* Destructor Arraylist
*/
ArrayList::~ArrayList()
{
  delete array;
}

/*
* Funcion que inserta de un objecto en la lista
* @param {data} es tipo Object
*/
bool ArrayList::inserta(Object * data, int posicion)
{
  int index = posicion - 1;
  if (index < 0 || index > size + 1)
  {
    return false;
  }
  if (index == size)
  {
    array[index] = data;
    size++;
    return true;
  }
  if (index <= size)
  {
    for (int i = size; i >= index; i--)
    {
      array[i + 1] = array[i];
    }
    array[index] = data;
  }
  size++;
  return true;
}

/*
* Funcion para agregar al final de lista
* @param {data} es tipo Object
*/
bool ArrayList::append(Object * data)
{
  return inserta(data, size + 1);
}

/*
* Funcion que localiza si un objecto esta en la lista
* @param {data} es tipo Object
*/
int ArrayList::localiza(Object * data)
{
  for (int i = 0; i < size ; i++)
  {
    if (array[i]->equals(data))
    {
      return i + 1;
    }
  }
  return -1;
}

/*
* Funcion que devuelve un Objecto de la lista en base a un posicion
* @param {posicion} es tipo entero
*/
Object* ArrayList::recupera(int posicion)
{
  if (posicion < 1 || posicion > size )
  {
    return NULL;
  }
  return array[posicion - 1];
}

/*
* Funcion que suprime un objecto de la lista de una posicion en especifo
* @param {data} es tipo Object
* @return {Object} retorna un Objecto que alocado en el heap
*/
Object* ArrayList::suprime(int posicion)
{
  if (posicion < 1 || posicion > size)
  {
    return NULL;
  }
  Object* temp = array[posicion - 1];
  for (int i = posicion - 1; i < size - 1; i++)
  {
    array[i] = array[i + 1];
  }
  array[size - 1] = NULL;
  size--;
  return temp;
}

/*
* Funcion que borra todo los elementos de la lista
* @param {data} es tipo Object
*/
void ArrayList::anula()
{
  for (int i = 0; i < size; i++)
  {
    delete array[i];
    array[i] = NULL;
  }
  size = 0;
}

/*
* Funcion que devuelve el primer objecto en la lista
* @param {data} es tipo Object
* @return tipo Objecto 
*/
Object* ArrayList::primero()
{
  if (size == 0)
  {
    return NULL;
  }
  return array[0];
}

/*
* Funcion que devuelve el objecto anterior de la lista de un posicion
* @param {posicion} es tipo int
* @return tipo Objecto 
*/
Object* ArrayList::anterior(int posicion)
{
  if (size == 0 || posicion < 2 || posicion > size)
  {
    return NULL;
  }
  return array[posicion - 2];
}

/*
* Funcion que devuelve el objecto siguiente de la lista de un posicion
* @param {posicion} es tipo int
* @return tipo Objecto 
*/
Object* ArrayList::siguiente(int posicion)
{
  if (size == 0 || posicion < 1 || posicion > size)
  {
    return NULL;
  }
  return array[posicion];
}

/*
* Funcion que indica si la lista esta vacia
*/
bool ArrayList::vacia()
{
  return size == 0;
}

/*
* Funcion que imprime todo los elementos si la lista no esta vacia
*/
void ArrayList::imprime()
{
  if (size == 0)
  {
    std::cout << "No hay elementos presentes en la lista" << std::endl;
    return;
  }
  for (int i = 0; i < size; i++)
  {
    cout << (i+1) << ". " << (array[i]->toString()) << std::endl;
  }
}