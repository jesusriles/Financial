#pragma once
#include <iostream>
#include <string>
#include <fstream> 

#include "Cuentas.h"

using std::string;

class FileMgmt
{
private:
	const string ARCHIVO_CUENTAS{ "Cuentas.txt" };

public:
	// Cuentas
	bool guardarCuenta(Cuentas& c);
	bool leerCuenta(int id);





	bool imprimirTodasLasCuentas();
};