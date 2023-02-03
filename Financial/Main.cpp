#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"
#include "Menu.h"
#include "FileMgmt.h"

int main()
{
	// Leer todas las cuentas
	FileMgmt fileMgmt;
	vector<Cuentas> cuentas = fileMgmt.leerCuentas();

	// Crear cuenta
	//Cuentas cuentaUno{ 1, "Cartera", 200.50, 0, 0, "null" };
	//Cuentas cuentaDos{ 2, "HSBC Nomina", 0.0, 0, 0, "Tarjeta donde me depositan de Deloitte" };

	
	//file.guardarCuenta(cuentaUno);
	//file.guardarCuenta(cuentaDos);

	
	return 0;
}