#include "Alumno.h"

/*
 * Constructor de la clase Alumno
 */
Alumno::Alumno(string Nombre, string Cuenta) {
	this->Nombre = Nombre;
	this->Cuenta = Cuenta;
}

/*
 * Destructor de la clase Alumno
 */
Alumno::~Alumno() {

}

/*
 * Muestra los datos sobre el Alumno.
 * @param No recibe ningún parametro.
 * @returns Retorna una cadena con los atributos Nombre y Cuenta.
 */
string Alumno::toString() {
	string salida = "Alumno: " + Nombre + " - " + Cuenta + "\n";

	return salida;
}

/*
 * Compara la Clase (this) con el objeto.
 * @param {Object* A} Es un objeto el cual será comparado a esta Clase (this).
 * @returns Retorna un booleano verificando si el parámetro es igual al Alumno.
 */
bool Alumno::equals(Object* A) {
	if (this == A) {
		return true;
	}
	return false;
}