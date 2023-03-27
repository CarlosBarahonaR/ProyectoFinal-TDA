#pragma once
#include "Object.h"
class Simbolo : public Object {
	//Declaración de atributos para la clase Simbolo
	char simbolo;
public:
	//Declaración de constructor y destructor para la clase Alumno
	Simbolo(char);
	Simbolo();
	~Simbolo();

	//Declaración de métodos heredados de la clase Object
	virtual string toString();
	virtual bool equals(Object*);
};

