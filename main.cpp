#include <iostream>
#include <fstream>
#include "ProyectoFinalTDA/ArrayStack.h"
#include "ProyectoFinalTDA/LinkedStack.h"
#include "ProyectoFinalTDA/ArrayQueue.h"
#include "ProyectoFinalTDA/Alumno.h"
#include "ProyectoFinalTDA/Object.h"
#include "ProyectoFinalTDA/TDAList.h"
#include "ProyectoFinalTDA/ArrayList.h"
#include "ProyectoFinalTDA/LinkList.h"
#include "ProyectoFinalTDA/Simbolo.h"

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
	//Variables donde se guardan los datos para los objetos
	string Nombre, Cuenta;
	//Variables con objetos inicializados
	ArrayStack arregloStack;
	LinkedStack linkedStack;
	ArrayQueue arregloQueue;
	Simbolo* simboloStackPtr = nullptr;
	Simbolo* simboloArrayPtr = nullptr;

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
										char valorSimbolo;
										cout << "Ingrese el valor de simbolo que quiere ingresar al stack" << endl;
										cin >> valorSimbolo;
										simboloArrayPtr = new Simbolo(valorSimbolo);
										arregloStack.empujar(simboloArrayPtr);
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
										char valorSimbolo;
										cout << "Ingrese el valor de simbolo que quiere ingresar al stack" << endl;
										cin >> valorSimbolo;
										simboloStackPtr = new Simbolo(valorSimbolo);
										linkedStack.empujar(simboloStackPtr);
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
										cout << "Ingrese el nombre del alumno: ";
										cin.ignore();
										getline(cin, Nombre);

										cout << "Ingrese el numero de cuenta del alumno: ";
										cin >> Cuenta;

										arregloQueue.Encolar(new Alumno(Nombre, Cuenta));
										break;
									case 2:
										if (!arregloQueue.EstaVacia()) {
											cout << "Alumno Desencolado: " << endl;
										}
										arregloQueue.Desencolar();
										break;
									case 3:
										if (arregloQueue.EstaVacia()) {
											cout << "!La cola esta vacia" << endl;
										}
										else {
											cout << "El elemento en frente de la Cola es: " << endl;
											cout << arregloQueue.Frente()->toString();
										}
										break;
									case 4:
										if (arregloQueue.EstaVacia()) {
											cout << "Esta Vacia" << endl;
										}
										else {
											cout << "No Esta Vacia" << endl;
										}
										break;
									case 5:
										if (arregloQueue.EstaVacia()) {
											cout << "!La cola esta vacia" << endl;
										}
										else {
											arregloQueue.Imprimir();
										}
										break;
									case 6:
										if (arregloQueue.EstaVacia()) {
											cout << "!La cola ya esta vacia" << endl;
										}
										else {
											arregloQueue.Vaciar();
											cout << "La cola se ha vaciado exitosamente!\n";
										}
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
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menu() {
	int opc;
	cout << endl;
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
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menuListas() {
	int opc;
	cout << endl;
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
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menuPilas() {
	int opc;
	cout << endl;
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
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menuColas() {
	int opc;
	cout << endl;
	cout << "Menu Tipo de Cola" << endl;
	cout << "1. Trabajar con ArrayQueue" << endl;
	cout << "2. Trabajar con LinkedQueue" << endl;
	cout << "3. Regresar al Menu Principal" << endl;
	cin >> opc;
	cout << endl;

	return opc;
}



/**
 * Menu de operaciones de implementaci�n de listas.
 * @param No recibe parametros.
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menuOpcionesListas() {
	int opc;
	cout << endl;
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
 * Menu de operaciones de implementaci�n de pilas.
 * @param No recibe parametros.
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menuOpcionesPilas() {
	int opc;
	cout << endl;
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
 * Menu de operaciones de implementaci�n de colas.
 * @param No recibe parametros.
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menuOpcionesColas() {
	int opc;
	cout << endl;
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