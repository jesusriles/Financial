#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"
#include "Menu.h"
#include "FileMgmt.h"

using namespace std;

int main() {

	// Obtener la informacion guardada en los archivos (Cuentas, Ingresos y Gastos)
	FileMgmt fileMgmt;
	vector<Cuentas> cuentas = fileMgmt.leerCuentas();
	vector<Ingresos> ingresos = fileMgmt.leerIngresos();

	// Menu options
	int option{ Menu::printMenu() };

	if (option == 1) { // Cuentas
		int optionCuenta{ Menu::printMenuAccounts() };

		if (optionCuenta == 1) { // visualizar cuenta
			Cuentas::imprimirCuentas(cuentas);
		}
	}


	/* Imprimir la informacion de las cuentas
	cout << "Cuenta" << setw(26) << "Cantidad" << endl;
	cout << "-----------------------------------------" << endl;
	for (Cuentas cuenta : cuentas) {
		cuenta.imprimirCuentaRelevante();
	}
	*/

	// Agregar 5 ingresos
	//Ingresos uno(1, 1, 26000.30f);
	//Ingresos dos(2, 1, 64000.00f);

	//uno.imprimirIngresos();
	//dos.imprimirIngresos();
	
	//file.guardarCuenta(cuentaUno);
	//file.guardarCuenta(cuentaDos);

	//fileMgmt.guardarIngreso(uno);
	//fileMgmt.guardarIngreso(dos);

	return 0;
}