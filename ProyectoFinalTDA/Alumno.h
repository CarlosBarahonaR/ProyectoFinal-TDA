#pragma once
#include "Object.h"

class Alumno : public Object {
	//Declaración de atributos para la clase Allumno
	string Nombre;
	string Cuenta;
public:
	//Declaración de constructor y destructor para la clase Alumno
	Alumno(string, string);
	~Alumno();

	//Declaración de métodos heredados de la clase Object
	virtual string toString();
	virtual bool equals(Object*);
};