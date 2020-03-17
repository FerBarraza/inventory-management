#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

// enumeración para ayudar a identificar las entradas del usuario en la función getUserAction
enum inputs {
	quit,
	addItem,
	removeItem,
	showInv,
	showItemList
};

// Declaración de funciones
inputs getUserAction();
void addItemToInv(Inventory*);
void removeItemFromInv(Inventory*);

// punto de entrada
int main(int argc, char* argv[]) {

	// El inventario principal que almacenará todos los datos
	Inventory inv(10);

	// Variable para decidir si salir del programa o no
	bool quit = false;

	// Repita el programa siempre que el usuario no quiera salir
	do {
		int inp = getUserAction();	// Obtener la entrada del usuario para realizar una acción
		if (inp == 0) {
			quit = true;
			std::cout << "Hasta luego!" << std::endl;
		}
		else if (inp == 1) {
			// llama la función para agregar item
			addItemToInv(&inv);
		}
		else if (inp == 2){
			// llama la función para remover item
			removeItemFromInv(&inv);
		}
		else if (inp == 3) {
			// llama la función para mostrar inventario
			inv.showInv();
		}
		else if (inp == 4) {
			// llama la función para mostrar items
			inv.showItems();
		}
		else {
			// mensaje en caso de que algo este mal
			std::cout << "Error, intente nuevamente!" << std::endl;
		}
	} while (!quit);

	system("PAUSE");
	return 0;

}

// funcion para obtener entradas
inputs getUserAction() {

	std::string inp;

	// booleano para almacenar la entrada del usuario
	bool valid = false;

	// entrada para que la función retorne
	inputs fInput;

	// Pedir entrada encaso de que la anterior sea invalida
	do {
		// Imprimir opciones
		std::cout << "Qué le gustaría hacer?" << std::endl;
		std::cout << "[q]: Salir de la aplicación" << std::endl;
		std::cout << "[a]: Agregar item" << std::endl;
		std::cout << "[r]: Remover item" << std::endl;
		std::cout << "[i]: Mostrar contenidos del inventario" << std::endl;
		std::cout << "[s]: Mostrar todos los items" << std::endl;

		// Obtener entrada
		while (getline(std::cin, inp)) {
			// Asegura que la entrada no es afectada por el cin de otras funciones
			if (inp != "") {
				break;
			}
		}
		if (inp[0] == 'q' || inp[0] == 'Q')	{
			// retorna el resultado y valida la entrada
			fInput = quit;
			valid = true;
		}else if (inp[0] == 'a' || inp[0] == 'A') {
			// retorna el resultado y valida la entrada
			fInput = addItem;
			valid = true;
		}else if (inp[0] == 'r' || inp[0] == 'R') {
			// retorna el resultado y valida la entrada
			fInput = removeItem;
			valid = true;
		}else if (inp[0] == 'i' || inp[0] == 'I') {
			// retorna el resultado y valida la entrada
			fInput = showInv;
			valid = true;
		}else if (inp[0] == 's' || inp[0] == 'S') {
			// retorna el resultado y valida la entrada
			fInput = showItemList;
			valid = true;
		}else {
			// En caso de entrada invalida, se notifica
			std::cout << "Entrada invalida..." << std::endl;
		}

	} while (!valid);

	// retornar el resultado final al usuario
	return fInput;

}

// función para agregar un elemento a elección de los usuarios
void addItemToInv(Inventory* inv) {

	// mostrar lista de posibles items para agregar
	inv->showItems();

	// enteros para almacenar entradas de usuario
	int uID, uC;	// ID y Cuenta

	// obtener la entrada del usuario para la identificación y el recuento de elementos para agregar
	std::cout << "Cuantos items te gustaría agregar?" << std::endl;
	std::cout << "( ingrese ID )" << std::endl;
	std::cin >> uID;
	std::cout << "Cuantos te gustaría agregar?" << std::endl;
	std::cin >> uC;

	// agrega el artículo de acuerdo con la ID y cuente
	inv->addItem(uID, uC);

	return;
}

// function to remove an item of the users choice
void removeItemFromInv(Inventory* inv) {

	// muestra los elementos de la lista en el inventario actual
	inv->showInv();

	// enteros para almacenar entradas de usuario
	int uID, uC;	// ID y Cuenta

	// obtener la entrada del usuario para la identificación y el recuento de elementos para eliminar
	std::cout << "Qué item te gustaría remover?" << std::endl;
	std::cout << "( Ingrese ID )" << std::endl;
	std::cin >> uID;
	std::cout << "Cuantos te gustaría remover?" << std::endl;
	std::cin >> uC;

	// agrega el artículo de acuerdo con la ID y cuente
	inv->remove(uID, uC);

	return;
}
