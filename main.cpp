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
#include "ProyectoFinalTDA/LinkedQueue.h"

//Menus principales
int menu();
// int menuListas();
int menuPilas();
int menuColas();

//Menu secundario de listas
void menuList(TDAList*, TDAList*);

//Menu secundario de pilas
int menuOpcionesPilas();

//Menu secundario de colas
int menuOpcionesColas();

// Declaracion de funciones para uso previo a la implementacion
void menuOperacionesList(TDAList*, int);
int leerSeleccionNumerica(int);

// Declaracion de funciones que contiene las operaciones de las listas
void agregarElementoLista(TDAList*);
void imprimirElementosLista(TDAList*);
void buscarElementoLista(TDAList*);
void borrarElementoLista(TDAList*);
void listaVacia(TDAList*);
void buscarElementoPosicionLista(TDAList*);
void siguienteElementoLista(TDAList*);
void anteriorElementoLista(TDAList*);
void borrarTodosElementosLista(TDAList*);
bool verificarDigito(char);

int main() {
	//Variables donde se guardan las opciones
	int opc, opcListas, opcPilas, opcColas, opcListasOperaciones, opcPilasOperaciones, opcColasOperaciones;
	//Variables donde se guardan los datos para los objetos
	string nombreAlumno, numeroCuenta;
	string Nombre, Cuenta;
	//Variables con objetos inicializados
	ArrayStack arregloStack;
	LinkedStack linkedStack;
	ArrayQueue arregloQueue;
	LinkedQueue linkedQueue;
	Simbolo* simboloStackPtr = nullptr;
	Simbolo* simboloArrayPtr = nullptr;

	//Variables para el manejo de listas
	TDAList* listArray = new ArrayList();
  TDAList* listLink = new LinkList();

	do {
		opc = menu();
		switch (opc) {
			case 1:
				cin.ignore();
				menuList(listArray,listLink);
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
										getline(cin, nombreAlumno);

										cout << "Ingrese el numero de cuenta del alumno: ";
										cin >> numeroCuenta;

										arregloQueue.Encolar(new Alumno(nombreAlumno, numeroCuenta));
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
									cout << "Ingrese el nombre del alumno: ";
									cin.ignore();
									getline(cin, Nombre);

									cout << "Ingrese el numero de cuenta del alumno: ";
									cin >> Cuenta;

									linkedQueue.Encolar(new Alumno(Nombre, Cuenta));
									break;
								case 2:
									if (!linkedQueue.EstaVacia()) {
										cout << "Alumno Desencolado: " << endl;
										linkedQueue.Desencolar();
									}
									else {
										cout << "!La cola esta vacia" << endl;
									}


									break;
								case 3:
									if (!linkedQueue.EstaVacia()) {
										linkedQueue.Frente();
									}
									else {
										cout << "!La cola esta vacia" << endl;
									}

									break;
								case 4:
									if (linkedQueue.EstaVacia()) {
										cout << "Esta vacia" << endl;
									}
									else {
										cout << "No esta vacia" << endl;
									}
									break;
								case 5:
									if (linkedQueue.EstaVacia()) {
										cout << "!La cola esta vacia" << endl;
									}
									else {
										linkedQueue.Imprimir();
									}
									break;
								case 6:
									if (linkedQueue.EstaVacia()) {
										cout << "!La cola ya esta vacia" << endl;
									}
									else {
										linkedQueue.Vaciar();
										cout << "La cola se ha vaciado exitosamente!\n";
									}
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

	//Borrar las variables que estan alocadas en el heap
	
	delete listArray;
	delete listLink;

}

/**
 * Menu principal.
 * @param No recibe parametros.
 * @returns Retorna el n�mero de la opci�n seleccionada.
 */
int menu() {
	cout << endl;
    cout << "===================== MENU =======================" << std::endl;
	cout << "1. Trabajar con Listas" << endl;
	cout << "2. Trabajar con Pilas" << endl;
	cout << "3. Trabajar con Colas" << endl;
	cout << "4. Salir" << endl;
    cout << "Ingrese la opcion que desea ejecutar: ";
    int opc = 0;
	cin >> opc;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Ingrese una opcion valida: ";
		cin >> opc;
	} 
	return opc;
}

// /**
//  * Menu de opciones de tipo de listas.
//  * @param No recibe parametros.
//  * @returns Retorna el n�mero de la opci�n seleccionada.
//  */
// int menuListas() {
// 	int opc;
// 	cout << endl;
// 	cout << "Menu Tipo de Lista" << endl;
// 	cout << "1. Trabajar con ArrayList" << endl;
// 	cout << "2. Trabajar con LinkedList" << endl;
// 	cout << "3. Regresar al Menu Principal" << endl;
// 	cin >> opc;
// 	cout << endl;

// 	return opc;
// }

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
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Ingrese una opcion valida: ";
		cin >> opc;
	}
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
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Ingrese una opcion valida: ";
		cin >> opc;
	}
	cout << endl;

	return opc;
}



// /**
//  * Menu de operaciones de implementaci�n de listas.
//  * @param No recibe parametros.
//  * @returns Retorna el n�mero de la opci�n seleccionada.
//  */
// int menuOpcionesListas() {
// 	int opc;
// 	cout << endl;
// 	cout << "Operaciones de Listas" << endl;
// 	cout << "1. Insertar Elemento" << endl;
// 	cout << "2. Imprimir Elementos" << endl;
// 	cout << "3. Buscar Elemento" << endl;
// 	cout << "4. Borrar Elemento" << endl;
// 	cout << "5. Ver si esta vacia" << endl;
// 	cout << "6. Obtener Elemento por Posicion" << endl;
// 	cout << "7. Obtener Siguiente" << endl;
// 	cout << "8. Obtener Anterior" << endl;
// 	cout << "9. Borrar todos los Elementos (Anula)" << endl;
// 	cout << "10. Regresar al Menu Anterior" << endl;
// 	cin >> opc;
// 	cout << endl;

// 	return opc;
// }

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
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Ingrese una opcion valida: ";
		cin >> opc;
	}
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
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Ingrese una opcion valida: ";
		cin >> opc;
	}
	cout << endl;

	return opc;
}

// APARTADO DE LISTA DE AQUI PARA ABAJO



/*
* Funcion que muestra el menu de listas y no retorna nada
*/
void menuList(TDAList* listArray, TDAList* listLink)
{
  bool ciclo = true;
  do
  {
    cout << "== LISTAS ========================================" << std::endl;
    cout << "1. Trabajar con ArrayList" << std::endl;
    cout << "2. Trabajar con Linked List" << std::endl;
    cout << "3. Regresar al Menu Principal" << std::endl;
    cout << "Ingrese la opcion que desea ejecutar: ";
    int seleccion = leerSeleccionNumerica(3);
    switch (seleccion)
    {
    case 1:
      menuOperacionesList(listArray, 0); 
      break;
    case 2:
      menuOperacionesList(listLink, 1);
      break;
    case 3:
      ciclo = false;
      break;
    default:
      cout << "Favor ingrese una opcion valida" << std::endl;
      break;
    }
  } while (ciclo);
}


/*
* Funcion que muestra el menu para ArrayLIst y LinkList
*/
void menuOperacionesList(TDAList* lista, int tipo)
{
  bool ciclo = true;
  do
  {
    if (tipo == 0)
      cout << "== ARRAYLIST =====================================" << std::endl;
    else
      cout << "== LINKLIST ======================================" << std::endl;
    cout << "1. Insertar Elemento" << std::endl;
    cout << "2. Imprimir Elementos" << std::endl;
    cout << "3. Buscar Elemento" << std::endl;
    cout << "4. Borrar Elemento" << std::endl;
    cout << "5. Ver si esta vacia" << std::endl;
    cout << "6. Obtener Elemento por Posicion" << std::endl;
    cout << "7. Obtener Siguiente" << std::endl;
    cout << "8. Obtener Anterior" << std::endl;
    cout << "9. Borrar todos los Elementos (Anula)" << std::endl;
    cout << "10. Regresar al Menu Anterior" << std::endl;
    cout << "Ingrese la opcion que desea ejecutar: ";
    int seleccion = leerSeleccionNumerica(10);
    Object* elemento;
    switch (seleccion)
    {
    case 1:
      agregarElementoLista(lista);
      break;
    case 2:
      cout << "== IMPRIMIENDO LISTA =============================" << std::endl;
      imprimirElementosLista(lista);
      break;
    case 3:
      cout << "== BUSCAR POR NUMERO DE CUENTA EN LISTA ==========" << std::endl;
      buscarElementoLista(lista);
      break;
    case 4:
      cout << "== ELIMINAR POR POSICION EN LISTA ================" << std::endl;
      borrarElementoLista(lista);
      break;
    case 5:
      cout << "== COMPROBANDO SI ESTA VACIA LA LISTA ============" << std::endl;
      listaVacia(lista);
      break;
    case 6:
      cout << "== RECUPERAR POR POSICION EN LISTA ===============" << std::endl;
      buscarElementoPosicionLista(lista);
      break;
    case 7:
      cout << "== SIGUIENTE POSICION EN LISTA ===================" << std::endl;
      siguienteElementoLista(lista);
      break;
    case 8:
      cout << "== ANTERIOR POSICION EN LISTA ====================" << std::endl;
      anteriorElementoLista(lista);
      break;
    case 9:
      cout << "== VACIAR LA LISTA ===============================" << std::endl;
      borrarTodosElementosLista(lista);
      break;
    case 10:
      cout << "==================================================" << std::endl;
      cout << "Regresando al Menu Principal" << std::endl;
      ciclo = false;
      break;
    default:
      cout << "Favor ingrese una opcion valida" << std::endl;
      break;
    }
  } while (ciclo);
}

/*
* Funcion que compruba que el caracter sea un digito
* @param {caracter}
* @return bool indicando si el caracter es un digito o no
*/
bool verificarDigito(char caracter){
  int cero = 48;
  int nueve = 57;
  return (int)caracter >= cero && (int)caracter <= nueve;
}

/*
* Funciona que permite solicitar al usuario un valor y comprueba que sea un digito
* @param {tieneMasdeNueveOpciones} si es verdadero verificar los dos caracteres si el usuario ingreso
* @return devuelve un entero (int)
*/
int leerSeleccionNumerica(int cantidadOpciones){
  bool tieneMasdeNueveOpciones = cantidadOpciones > 9;
  int seleccion = -1;
  string linea = "";
  getline(cin,linea);
  if (linea.length() > 1 && tieneMasdeNueveOpciones)
  {
    bool validarElemento1 = verificarDigito(linea[0]);
    bool validarElemento2 = verificarDigito(linea[1]);
    if (validarElemento1 && validarElemento2)
      seleccion = atoi(&linea[0]);
  }
  else
  {
    if (verificarDigito(linea[0]))
      seleccion = atoi(&linea[0]);
  }
  return seleccion;
}

/*
* Funcion que agregar elementos  para ArrayLIst y LinkList
*/
void agregarElementoLista(TDAList* lista)
{
  bool ciclo = true;
  do
  {
    cout << "== AGREGAR A LISTA ===============================" << std::endl;
    int opcion = -1;
    cout << "Ingrese el nombre del Alumno: ";
    string nombreAlumno = "";
    getline(cin, nombreAlumno);
    cout << "Ingrese el numero de cuenta: ";
    string numeroCuenta = "";
    getline(cin,numeroCuenta);
    Object* nuevoAlumno = new Alumno(nombreAlumno,numeroCuenta);
    
    bool agregadoExitosamente = lista->append(nuevoAlumno);
    if (agregadoExitosamente){
      cout << "--------------------------------------------------" << std::endl;
      cout << nombreAlumno << " fue agregado exitosamente" << std::endl;
    }
    else
      cout << "El Alumno no se puedo agregar a la lista" << std::endl;
    do
    {
      opcion = -1;
      cout << "--------------------------------------------------" << std::endl;
      cout << "Desea agregar otro Alumno (1.Si 2.No) -> ";
      opcion = leerSeleccionNumerica(2);
      cout << "--------------------------------------------------" << std::endl;
      if (opcion == -1)
        cout << "Favor selecione un opcion valida" << std::endl;
      if (opcion == 2){
        cout << "Regresando al menu anterior" << std::endl;
        cout << "--------------------------------------------------" << std::endl;
        ciclo = false;
      }
    } while (!(opcion == 2 || opcion == 1));
  } while (ciclo);
}


/*
* Funcion que imprime los elementos para ArrayLIst y LinkList
*/
void imprimirElementosLista(TDAList* lista)
{
  lista->imprime();
}

/*
* Funcion que busca por numero para ArrayLIst y LinkList
*/
void buscarElementoLista(TDAList* lista)
{
  cout << "Ingrese el numero de Cuenta del Alumno a buscar: ";
  string numeroCuenta = "";
  getline(cin,numeroCuenta);
  if (lista->vacia()){
    lista->imprime();
    return;
  }
  int size = lista->getSize();
  Alumno* alumno = nullptr;
  bool encontrado = false;
  int indice = -1;
  for (size_t i = 1; i <= size; i++)
  {
	alumno = dynamic_cast<Alumno*>(lista->recupera(i));
    if (alumno != NULL)
    {
      if (numeroCuenta == alumno->getNumeroCuenta())
      {
        encontrado = true;
        indice = i;
        break;
      }
    }
  }
  if (!encontrado)
  {
    cout << "No se ha encontrado un alumno con el numero de cuenta: " << std::endl;
    return;
  }
  // si se ha encontrado se imprime el alumno
  cout << "Se ha encontrado el registro para la cuenta: " << numeroCuenta << std::endl;
  cout <<  indice << ". -- >  " << alumno->toString() << std::endl;
}

/*
* Funcion que recibe el ingreso de un usuario y comprueba que sea un entero positivo
* @return remite un Entero positivo
*/
int solicitarEnteroPosivo(){
  string numeroString = "";
  int posicion = -1;
  bool esNumero = true;
  do{
    getline(cin,numeroString);
    for (size_t i = 0; i < numeroString.length(); i++)
    {
      if (!verificarDigito(numeroString[0]))
      {
        esNumero = false;
        break;
      }
    }
    if (esNumero)
    {
      posicion = stoi(numeroString);
    }
    else
    {
      cout << "Ingrese un numero entero positivo: ";
    }
  } while (!esNumero);
  return posicion;
}

/*
* Funcion que permite borrar un elemento para un ArrayLIst y LinkList
*/
void borrarElementoLista(TDAList* lista)
{
  cout << "Favor ingrese el numero del elemento a eliminar: ";
  int posicion = solicitarEnteroPosivo();
  Object* resultado = (lista->suprime(posicion));
  if (resultado != NULL)
  {
    delete resultado;
    cout << "Elemento borrado exitosamente" << std::endl;
    return;
  }
  cout << "No se ha podido eliminar el elemento" << std::endl;
}

/*
* Funcion identifica si el ArrayLIst o el LinkList estan vacios
*/
void listaVacia(TDAList* lista)
{
  if (lista->vacia())
    cout << "La lista esta vacia" << std::endl;
  else
    cout << "La lista no esta vacia y tiene: " << lista->getSize() << " elementos" << std::endl;
}

/*
* Funcion que permite buscar en una lista una posicion
* @param {retorno} string que se recibe como referencia para poder retornarla
* @return retonar 0 cuando se encuentra el elemento y -1 cuando no
*/
int buscardorElementosLista(TDAList* lista, int posicion,string &retorno){
  Object* elemento = lista->recupera(posicion);
  if (elemento != NULL)
  {
    Alumno* a = dynamic_cast<Alumno*>(elemento);
    retorno = a->toString();
    return 0;
  }
  retorno ="";
  return -1;
}

/*
* Funcion que busca elemento en ArrayLIst y LinkList
*/
void buscarElementoPosicionLista(TDAList* lista)
{
  cout << "Favor ingrese el numero del elemento a buscar: ";
  int posicion = solicitarEnteroPosivo();
  string retorno = "";
  int resultado = buscardorElementosLista(lista, posicion, retorno);
  if (resultado == 0)
    cout << "Elemento encontrado: " << retorno << std::endl;
  else
    cout << "Posicion no valida" << std::endl;
}

/*
* Funcion que busca el elemento siguiente para ArrayLIst y LinkList
*/
void siguienteElementoLista(TDAList*lista)
{
  cout << "Favor ingrese la posicion: ";
  int posicion = solicitarEnteroPosivo();
  string retorno = "";
  int resultado = buscardorElementosLista(lista,posicion + 1,retorno);
  if (resultado == 0)
    cout << "Elemento siguiente es: " << retorno << std::endl;
  else
    cout << "El espacio siguiente esta vacio" << std::endl;
}

/*
* Funcion que busca elemento anterior para ArrayLIst y LinkList
*/
void anteriorElementoLista(TDAList* lista)
{
  cout << "Favor ingrese la posicion: ";
  int posicion = solicitarEnteroPosivo();
  string retorno = "";
  int resultado = buscardorElementosLista(lista,posicion - 1,retorno);
  if (resultado == 0)
    cout << "Elemento anterior es: " << retorno << std::endl;
  else
    cout << "El espacio anterior esta vacio" << std::endl;
}

/*
* Funcion borra todos los elementos ArrayLIst y LinkList
*/
void borrarTodosElementosLista(TDAList* lista)
{
  lista->anula();
  if (lista->vacia())
    cout << "La lista ha sido borrada exitosamente" << std::endl;
  else
    cout << "No se ha podido borrar la lista" << std::endl;
}