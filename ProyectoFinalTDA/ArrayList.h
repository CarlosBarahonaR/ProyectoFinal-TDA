#ifndef ARRAYLIST_H
#define  ARRAYLIST_H
#include "TDAList.h"
#include "Object.h"
// Clase ArrayList
class ArrayList : public TDAList
{
private:
  int capacidad;
  Object** array;

public:
  ArrayList();
  ~ArrayList();
  bool inserta(Object*, int);
  bool append(Object*);
  int localiza(Object*);
  Object* recupera(int);
  Object* suprime(int);
  void anula();
  Object* primero();
  Object* anterior(int);
  Object* siguiente(int);
  bool vacia();
  void imprime();
};

#endif