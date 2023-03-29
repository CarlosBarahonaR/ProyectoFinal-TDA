#ifndef TDALIST_H
#define TDALIST_H
#include "Object.h"

// Clase Abstracta TDA
class TDAList {
protected:
	int size;
public:
	TDAList();
	virtual ~TDAList();
	virtual bool inserta(Object*, int) = 0;
	virtual bool append(Object*) = 0;
	virtual int localiza(Object*) = 0;
	virtual Object* recupera(int) = 0;
	virtual Object* suprime(int) = 0;
	virtual void anula() = 0;
	virtual Object* primero() = 0;
	virtual Object* anterior(int) = 0;
	virtual Object* siguiente(int) = 0;
	virtual bool vacia() = 0;
	virtual void imprime() = 0;
	int getSize();
};

#endif

