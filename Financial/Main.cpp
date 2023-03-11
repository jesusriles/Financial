#include <iostream>
#include "Accounts.h"
#include "Transactions.h"
#include "Menu.h"

int main() {

	// Obtener la informacion guardada en los archivos (Cuentas, Ingresos y Gastos)
	//vector<Cuentas> cuentas = Cuentas::leerCuentas();
	//vector<Ingresos> ingresos = Ingresos::leerIngresos();

	// Menu options
	int option { 0 };
	option = Menu::printMenu();
	return 0;
}