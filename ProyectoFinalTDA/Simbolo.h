#pragma once
#include "Object.h"
class Simbolo : public Object {
	//Declaraci�n de atributos para la clase Simbolo
	char simbolo;
public:
	//Declaraci�n de constructor y destructor para la clase Alumno
	Simbolo(char);
	Simbolo();
	~Simbolo();

	//Declaraci�n de m�todos heredados de la clase Object
	virtual string toString();
	virtual bool equals(Object*);
};

