#pragma once
#include "Object.h"

class Alumno : public Object {
	//Declaraci�n de atributos para la clase Allumno
	string Nombre;
	string Cuenta;
public:
	//Declaraci�n de constructor y destructor para la clase Alumno
	Alumno(string, string);
	~Alumno();

	//Declaraci�n de m�todos heredados de la clase Object
	virtual string toString();
	virtual bool equals(Object*);
};