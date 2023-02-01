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
	Ingresos(int id, int idCuentaAsociada, float cantidad);
	void imprimirIngresos();
};