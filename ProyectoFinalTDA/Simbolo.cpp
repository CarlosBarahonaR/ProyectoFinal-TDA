#include "Simbolo.h"


/*
 * Constructor de la clase Simbolo
 */
Simbolo::Simbolo(char simbolo) {
	this->simbolo = simbolo;
}

Simbolo::Simbolo() {
}


/*
 * Destructor de la clase Simbolo
 */
Simbolo::~Simbolo() {

}

/*
 * Muestra los datos sobre el Simbolo.
 * @param No recibe ningún parametro.
 * @returns Retorna una cadena con el atributo simbolo.
 */
string Simbolo::toString() {
	string salida = "Simbolo: ";
	salida.push_back(this->simbolo);

	return salida;
}

/*
 * Compara la Clase (this) con el objeto.
 * @param {Object* A} Es un objeto el cual será comparado a esta Clase (this).
 * @returns Retorna un booleano verificando si el parámetro es igual al Simbolo.
 */
bool Simbolo::equals(Object* A) {
	if (this == A) {
		return true;
	}
	return false;
}
