#include "Inventory.h"

// constructor
Inventory::Inventory(int size) {

	// llama a la funcion para inicializar item ID y names
	initIDs();

	// setea por defecto tamaño a 10
	if (size == 0) {
		iSize = 10;
	}

	// setea tamaño del inventario
	iSize = size;

}

// funcion para agregar item (ID, Count)
void Inventory::addItem(int inpID, int inpCount) {

	if ( _inv.size() >= iSize ) {
		std::cout << "ERROR, INVENTARIO LLENO..." << std::endl;
		return;
	}

	for (int i = 0; i < _inv.size(); i++) {
		if(inpID == _inv[i]._item.ID){
			_inv[i]._count += inpCount;
			return;
		}
	}

	item temp;


	for (int i = 0; i < itemList.size(); i++) {
		if (inpID==itemList[i].ID) {
			temp = itemList[i];
		}
	}

	if (temp.ID == NULL) {
		temp = itemList[0];
	}

	invType a = { temp, inpCount };
	_inv.push_back(a);

	return;

}

// funcion para mostrar el contenido de los inventarios
void Inventory::showInv() {

	std::cout << "+--------------------+" << std::endl;

	for (int i = 0; i < _inv.size(); i++) {
		std::cout << "ID: " << _inv[i]._item.ID << " - " <<  _inv[i]._item.name << " : " << _inv[i]._count << std::endl;
	}

	std::cout << "+--------------------+" << std::endl;

	return;

}

// funcion para remover los items de los inventarios
void Inventory::remove(int ID, int Count) {

	for (int i = 0; i < _inv.size(); i++) {
		if (_inv.at(i)._item.ID == ID) {
			if (_inv.at(i)._count <= Count) {
				_inv.erase(_inv.begin()+i);
			}
			else {
				_inv.at(i)._count -= Count;
			}
			return;
		}
	}

	std::cout << "ITEM FALLO EN REMOVERSE" << std::endl;
	return;

}

// funcion para mostrar todos los items
void Inventory::showItems() {

	std::cout << "+--------------------+" << std::endl;

	for (int i = 0; i < itemList.size(); i++) {
		std::cout << "ID: " << itemList[i].ID << " - " << itemList[i].name << std::endl;
	}

	std::cout << "+--------------------+" << std::endl;

	return;
}

// inicializa el ID de los items
void Inventory::initIDs() {

	itemList.push_back({ 0, "NADA", 0 });
	itemList.push_back({ 1, "MADERA" , 1 });
	itemList.push_back({ 2, "PIEDRA" , 1 });
	itemList.push_back({ 3, "GRAVA" , 1 });
	itemList.push_back({ 4, "HIERRO", 3 });
	itemList.push_back({ 5, "ORO", 4 });
	itemList.push_back({ 6, "PLATA", 5 });
	itemList.push_back({ 7, "COBRE", 4 });
	itemList.push_back({ 8, "LADRILLO", 3});

	return;
}
