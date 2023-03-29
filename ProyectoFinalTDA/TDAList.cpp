#include "TDAList.h"

// Constructor TDAList
TDAList::TDAList()
{
	size = 0;
}

// Destructor TDAList
TDAList::~TDAList()
{
}

/*
* Funcion que permite obtener el tamanio de la lista
* @return Devuelve un entero con el tamanio
*/
int TDAList::getSize() {
	return size;
}
