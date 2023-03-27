#ifndef LINKLIST_H
#define  LINKLIST_H
#include "TDAList.h"
#include "Node.h"

class LinkList : public TDAList
{
private:
  Node* inicio;
  Node* fin;

public:
  LinkList();
  ~LinkList();
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