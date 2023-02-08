#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <vector>

#include "Cuentas.h" // here are the global files name defined in Cuentas.h

using namespace std;

class Ingresos
{
private:
	int mId{ 0 };
	int mIdCuentaAsociada;
	float mCantidad;

public:
	// getter
	int getId() { return mId; };
	int getIdCuentaAsociada() { return mIdCuentaAsociada; };
	float getCantidad() { return mCantidad; };

	// funciones
	Ingresos(int id, int idCuentaAsociada, float cantidad);
	void imprimirIngresos();
	static double obtenerIngresoTotalDeCuenta(vector<Ingresos>& i, int cuentaId);

	static vector<Ingresos> leerIngresos(); // obtener todos los ingresos
	bool guardarIngreso(Ingresos& i);
};