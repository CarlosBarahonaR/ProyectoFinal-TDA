#include "Alumno.h"

Alumno::Alumno()
{
  nombreAlumno = "";
  numeroCuenta = "";
}


/*
 * Constructor de la clase Alumno
 */
Alumno::Alumno(string nombreAlumno, string numeroCuenta) {
	this->nombreAlumno = nombreAlumno;
	this->numeroCuenta = numeroCuenta;
}

/*
 * Destructor de la clase Alumno
 */
Alumno::~Alumno() {

}

/*
 * Muestra los datos sobre el Alumno.
 * @param No recibe ning�n parametro.
 * @returns Retorna una cadena con los atributos nombreAlumno y numeroCuenta.
 */
string Alumno::toString() {
	string salida = nombreAlumno + " - " + numeroCuenta + "\n";
	return salida;
}

/*
 * Compara la Clase (this) con el objeto.
 * @param {Object* A} Es un objeto el cual ser� comparado a esta Clase (this).
 * @returns Retorna un booleano verificando si el par�metro es igual al Alumno.
 */
bool Alumno::equals(Object* A) {
	if (this == A) {
		return true;
	}
	return false;
}

string Alumno::getNombreAlumno()
{
  return nombreAlumno;
}

string Alumno::getNumeroCuenta()
{
  return numeroCuenta;
}