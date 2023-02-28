#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <vector>

#include "Cuentas.h" // here are the global files name defined in Cuentas.h
#include "Movements.h"

using namespace std;

class Ingresos : public Movements
{
public:
	// constructor
	Ingresos(int tmpId, string shortDescription, int tmpAccountId, float tmpAmount);

	// funciones
	static void imprimirIngresos(const vector<Ingresos>& i);
	static double obtenerIngresoTotalDeCuenta(vector<Ingresos>& i, int cuentaId);

	static vector<Ingresos> leerIngresos(); // obtener todos los ingresos
	static bool guardarIngreso(Ingresos& i);
};