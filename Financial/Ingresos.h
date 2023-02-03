#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>

using namespace std;

class Ingresos
{
private:
	int mId;
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
};