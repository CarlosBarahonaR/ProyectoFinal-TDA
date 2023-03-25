#include <iostream>
#include <fstream>
using namespace std;

int menu();
int menuListas();
int menuPilas();
int menuColas();


int main() {
	int opc, opcListas, opcPilas, opcColas;
	do {
		opc = menu();
		switch (opc) {
		case 1:
			do {
				opcListas = menuListas();
				switch (opcListas) {
				case 1:
					break;
				case 2:
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
					break;
				case 2:
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
					break;
				case 2:
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