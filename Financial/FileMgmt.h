#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

#include "Cuentas.h"

using std::string;

class FileMgmt
{
private:
	const string ARCHIVO_CUENTAS{ "Cuentas.txt" };
	vector<Cuentas> cuentas;

public:
	// Cuentas
	bool guardarCuenta(Cuentas& c);
	vector<Cuentas> leerCuentas();
};