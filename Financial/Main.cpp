#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"
#include "Menu.h"
#include "FileMgmt.h"

using namespace std;

int main()
{
	// Leer todas las cuentas
	FileMgmt fileMgmt;
	vector<Cuentas> cuentas = fileMgmt.leerCuentas();

	// Agregar 5 ingresos
	//Ingresos uno(1, 1, 26000.30f);
	//Ingresos dos(2, 1, 64000.00f);

	//uno.imprimirIngresos();
	//dos.imprimirIngresos();
	
	//file.guardarCuenta(cuentaUno);
	//file.guardarCuenta(cuentaDos);

	//fileMgmt.guardarIngreso(uno);
	//fileMgmt.guardarIngreso(dos);

	vector<Ingresos> ingresos = fileMgmt.leerIngresos();
	for (Ingresos ingreso : ingresos) {
		ingreso.imprimirIngresos();
	}
	
	return 0;
}