#pragma once

#include <iostream>
#include <string>
#include <vector>

// struct para almacenar items
struct item {
	int ID;
	std::string name;
	int cost;
};

// structure para almacenar items en vector
struct invType {
	item _item;
	int _count;
};

// declaracion de clase
class Inventory {

public:
	Inventory(int);					// constructor con tamaño del inventario
	void addItem(int, int);			// funcion para agregar item (ID, Count)
	void showInv();					// funcion para mostrar el contenido de los inventarios
	void remove(int, int);			// funcion para remover los items de los inventarios
	void showItems();				// funcion para mostrar todos los items

private:
	std::vector<invType> _inv;		// vector de inventario
	std::vector<item> itemList;		// lista de items
	int iSize;						// tamaño de inventario

	void initIDs();					// inicializa el ID de los items
};

