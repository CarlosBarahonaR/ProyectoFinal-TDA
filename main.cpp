#include "ProyectoFinalTDA/ArrayStack.h"
#include "ProyectoFinalTDA/LinkedStack.h"
#include <iostream>
#include <fstream>

using namespace std;

//Menus principales
int menu();
int menuListas();
int menuPilas();
int menuColas();

//Menu secundario de listas
int menuOpcionesListas();

//Menu secundario de pilas
int menuOpcionesPilas();

//Menu secundario de colas
int menuOpcionesColas();

int main() {
	//Variables donde se guardan las opciones
	int opc, opcListas, opcPilas, opcColas, opcListasOperaciones, opcPilasOperaciones, opcColasOperaciones;
	//Variables con objetos inicializados
	ArrayStack arregloStack;
	LinkedStack linkedStack;

	do {
		opc = menu();
		switch (opc) {
		case 1:
			do {
				opcListas = menuListas();
				switch (opcListas) {
				case 1:
					do {
						opcListasOperaciones = menuOpcionesListas();
						switch (opcListasOperaciones) {
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;						
						case 4:
							break;						
						case 5:
							break;						
						case 6:
							break;						
						case 7:
							break;						
						case 8:
							break;						
						case 9:
							break;
						default:
							break;
						}
					} while (opcListasOperaciones != 10);
					break;
				case 2:
					do {
						opcListasOperaciones = menuOpcionesListas();
						switch (opcListasOperaciones) {
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						case 6:
							break;
						case 7:
							break;
						case 8:
							break;
						case 9:
							break;
						default:
							break;
						}
					} while (opcListasOperaciones != 10);
					break;
					break;
				default:
					break;
				}
			} while (opcListas != 3);
			break;
		case 2:
			do {
				opcPilas = menuPilas();
				switch (opcPilas) {
				case 1:
					do {
						opcPilasOperaciones = menuOpcionesPilas();
						switch (opcPilasOperaciones) {
						case 1:
							int valor;
							cout << "Ingrese el valor que quiere ingresar al arreglo de pilas" << endl;
							cin >> valor;
							arregloStack.empujar(valor);
							break;
						case 2:
							arregloStack.sacar();
							break;
						case 3:
							arregloStack.verTope();
							break;
						case 4:
							if (arregloStack.vacio()) {
								cout << "El arreglo de pilas esta vacio." << endl;
								cout << endl;
							}
							else {
								cout << "El arreglo de pilas no esta vacio." << endl;
								cout << endl;
							}
							break;
						case 5:
							arregloStack.imprimir();
							break;
						case 6:
							arregloStack.borrarElementos();
							break;
						default:
							break;
						}
					} while (opcPilasOperaciones != 7);
					break;
				case 2:
					do {
						opcPilasOperaciones = menuOpcionesPilas();
						switch (opcPilasOperaciones) {
						case 1:
							int valor;
							cout << "Ingrese el valor que quiere ingresar al stack" << endl;
							cin >> valor;
							linkedStack.empujar(valor);
							break;
						case 2:
							linkedStack.sacar();
							break;
						case 3:
							linkedStack.verTope();
							break;
						case 4:
							if (linkedStack.vacio()) {
								cout << "El stack esta vacio." << endl;
								cout << endl;
							}
							else {
								cout << "El stack no esta vacio." << endl;
								cout << endl;
							}
							break;
						case 5:
							linkedStack.imprimir();
							break;
						case 6:
							linkedStack.borrarElementos();
							break;
						default:
							break;
						}
					} while (opcPilasOperaciones != 7);
					break;
					break;
				default:
					break;
				}
			} while (opcPilas != 3);
			break;
		case 3:
			do {
				opcColas = menuColas();
				switch (opcColas) {
				case 1:
					do {
						opcColasOperaciones = menuOpcionesColas();
						switch (opcColasOperaciones) {
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						case 6:
							break;
						default:
							break;
						}
					} while (opcColasOperaciones != 7);
					break;
				case 2:
					do {
						opcColasOperaciones = menuOpcionesColas();
						switch (opcColasOperaciones) {
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						case 6:
							break;
						default:
							break;
						}
					} while (opcColasOperaciones != 7);
					break;
					break;
				default:
					break;
				}
			} while (opcColas != 3);
			break;
		default:
			break;
		}
	} while (opc != 4);
}

/**
 * Menu principal.
 * @param No recibe parametros.
 * @returns Retorna el número de la opción seleccionada.
 */
int menu() {
	int opc;
	cout << "Menu Principal" << endl;
	cout << "1. Trabajar con Listas" << endl;
	cout << "2. Trabajar con Pilas" << endl;
	cout << "3. Trabajar con Colas" << endl;
	cout << "4. Salir" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}

/**
 * Menu de opciones de tipo de listas.
 * @param No recibe parametros.
 * @returns Retorna el número de la opción seleccionada.
 */
int menuListas() {
	int opc;
	cout << "Menu Tipo de Lista" << endl;
	cout << "1. Trabajar con ArrayList" << endl;
	cout << "2. Trabajar con LinkedList" << endl;
	cout << "3. Regresar al Menu Principal" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}

/**
 * Menu de opciones de tipo de pilas.
 * @param No recibe parametros.
 * @returns Retorna el número de la opción seleccionada.
 */
int menuPilas() {
	int opc;
	cout << "Menu Tipo de Pila" << endl;
	cout << "1. Trabajar con ArrayStack" << endl;
	cout << "2. Trabajar con LinkedStack" << endl;
	cout << "3. Regresar al Menu Principal" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}

/**
 * Menu de opciones de tipo de colas.
 * @param No recibe parametros.
 * @returns Retorna el número de la opción seleccionada.
 */
int menuColas() {
	int opc;
	cout << "Menu Tipo de Cola" << endl;
	cout << "1. Trabajar con ArrayQueue" << endl;
	cout << "2. Trabajar con LinkedQueue" << endl;
	cout << "3. Regresar al Menu Principal" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}



/**
 * Menu de operaciones de implementación de listas.
 * @param No recibe parametros.
 * @returns Retorna el número de la opción seleccionada.
 */
int menuOpcionesListas() {
	int opc;
	cout << "Operaciones de Listas" << endl;
	cout << "1. Insertar Elemento" << endl;
	cout << "2. Imprimir Elementos" << endl;
	cout << "3. Buscar Elemento" << endl;
	cout << "4. Borrar Elemento" << endl;
	cout << "5. Ver si esta vacia" << endl;
	cout << "6. Obtener Elemento por Posicion" << endl;
	cout << "7. Obtener Siguiente" << endl;
	cout << "8. Obtener Anterior" << endl;
	cout << "9. Borrar todos los Elementos (Anula)" << endl;
	cout << "10. Regresar al Menu Anterior" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}

/**
 * Menu de operaciones de implementación de pilas.
 * @param No recibe parametros.
 * @returns Retorna el número de la opción seleccionada.
 */
int menuOpcionesPilas() {
	int opc;
	cout << "Operaciones de Pilas" << endl;
	cout << "1. Empujar (push) " << endl;
	cout << "2. Sacar (pop)" << endl;
	cout << "3. Ver Tope (top)" << endl;
	cout << "4. Verificar si esta vacia" << endl;
	cout << "5. Imprimir elementos" << endl;
	cout << "6. Borrar todos los elementos" << endl;
	cout << "7. Regresar al Menu Anterior" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}

/**
 * Menu de operaciones de implementación de colas.
 * @param No recibe parametros.
 * @returns Retorna el número de la opción seleccionada.
 */
int menuOpcionesColas() {
	int opc;
	cout << "Operaciones de Colas" << endl;
	cout << "1. Encolar (queue) " << endl;
	cout << "2. Desencolar (dequeue)" << endl;
	cout << "3. Ver Frente (peek)" << endl;
	cout << "4. Verificar si esta vacia" << endl;
	cout << "5. Imprimir elementos" << endl;
	cout << "6. Borrar los elementos" << endl;
	cout << "7. Regresar al Menu Anterior" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}