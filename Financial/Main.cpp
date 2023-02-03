#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"
#include "Menu.h"
#include "FileMgmt.h"

int main()
{
	// Menu (todavia es un draft)
	// Menu menu{};
	// menu.printMenu();

	// Crear cuenta
	Cuentas cuentaUno{ 1, "Cartera", 200.50, 0, 0, "null" };
	Cuentas cuentaDos{ 2, "HSBC Nomina", 0.0, 0, 0, "Tarjeta donde me depositan de Deloitte" };

	cuentaUno.imprimirCuenta();
	cuentaDos.imprimirCuenta();

	// Crear ingresos
	Ingresos ingresoUno{ 1, 1, 50 };
	Ingresos ingresoDos{ 2, 1, 450 };
	Ingresos ingresoTres{ 3, 2, 32956.86f };

	
	ingresoUno.imprimirIngresos();
	ingresoDos.imprimirIngresos();
	ingresoTres.imprimirIngresos();

	FileMgmt file;
	file.guardarCuenta(cuentaUno);
	file.guardarCuenta(cuentaDos);

	vector<string> v = file.leerTodasLasCuentas();
	for (string line : v) {
		cout << line << endl;
	}

	return 0;
}