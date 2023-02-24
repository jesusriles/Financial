#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"
#include "Menu.h"

using std::cin;

int main() {

	// Obtener la informacion guardada en los archivos (Cuentas, Ingresos y Gastos)
	//vector<Cuentas> cuentas = Cuentas::leerCuentas();
	//vector<Ingresos> ingresos = Ingresos::leerIngresos();

	// Menu options
	int option { 0 };
	option = Menu::printMenu();
	return 0;
}