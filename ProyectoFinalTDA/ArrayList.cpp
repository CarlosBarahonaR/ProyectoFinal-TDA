#include "ArrayList.h"
#include <iostream>

using std::cout;
using std::endl;

ArrayList::ArrayList()
{
  this->capacidad = 10000;
  array = new Object*[capacidad];
  size = 0;
  for (int i = 0; i < capacidad; i++)
    array[i] = NULL;
}

ArrayList::~ArrayList()
{
  delete array;
}

bool ArrayList::inserta(Object * data, int posicion)
{
  int index = posicion - 1;
  if (index < 0 || index > size + 1)
  {
    return false;
  }
  if (posicion == size)
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

bool ArrayList::append(Object * data)
{
  inserta(data, size + 1);
  return false;
}

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

Object* ArrayList::recupera(int posicion)
{
  if (posicion < 1 || posicion > size )
  {
    return NULL;
  }
  return array[posicion - 1];
}

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

void ArrayList::anula()
{
  for (int i = 0; i < size; i++)
  {
    delete array[i];
    array[i] = NULL;
  }
  size = 0;
}

Object* ArrayList::primero()
{
  if (size == 0)
  {
    return NULL;
  }
  return array[0];
}

Object* ArrayList::anterior(int posicion)
{
  if (size == 0 || posicion < 2 || posicion > size)
  {
    return NULL;
  }
  return array[posicion - 2];
}

Object* ArrayList::siguiente(int posicion)
{
  if (size == 0 || posicion < 1 || posicion > size)
  {
    return NULL;
  }
  return array[posicion];
}

bool ArrayList::vacia()
{
  return size == 0;
}

void ArrayList::imprime()
{
  if (size == 0)
  {
    std::cout << "No hay elementos presentes en la lista" << std::endl;
    return;
  }
  for (int i = 0; i < size; i++)
  {
    cout << (array[i]->toString()) << std::endl;
  }
}