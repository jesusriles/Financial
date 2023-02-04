#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

#include "Cuentas.h"
#include "Ingresos.h"

using std::string;

// global variables
const string ARCHIVO_CUENTAS{ "Cuentas.txt" };
const string ARCHIVO_INGRESOS{ "Ingresos.txt" };
const string ARCHIVO_GASTOS{ "Gastos.txt" };

class FileMgmt
{
private:
	
	vector<Cuentas> cuentas;

public:
	// Cuentas
	static bool guardarCuenta(Cuentas& c);
	vector<Cuentas> leerCuentas();

	// Ingresos
	bool guardarIngreso(Ingresos& i);
	vector<Ingresos> leerIngresos();
};