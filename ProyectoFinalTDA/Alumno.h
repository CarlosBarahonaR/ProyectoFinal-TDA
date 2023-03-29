#pragma once
#include "Object.h"

// Clase Alumno
class Alumno : public Object {
	//Declaraci�n de atributos para la clase Alumno
	string nombreAlumno;
	string numeroCuenta;
public:
	//Declaraci�n de constructor y destructor para la clase Alumno
	Alumno();
	Alumno(string, string);
	~Alumno();

	// Declacion de getters
  string getNombreAlumno();
  string getNumeroCuenta();
	
	//Declaraci�n de m�todos heredados de la clase Object
	string toString();
	bool equals(Object*);
};