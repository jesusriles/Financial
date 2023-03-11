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
	int mId{ 0 };
	string mShortDescription{};
	int mAccountId{ 0 };
	float mAmount{ 0 };
	vector<string> tags{};
	string mComments{};
	//	string mDate{};

public:
	// getters
	int getId() const { return mId; };
	string getShortDescription() const { return mShortDescription; };
	int getAccountId() const { return mAccountId; };
	double getAmount() const { return mAmount; };
	vector<string> getTags() const { return tags; };
	string getComments() const { return mComments; };

	// constructor
	Ingresos(int tmpId, string shortDescription, int tmpAccountId, float tmpAmount);

	// funciones
	static void imprimirIngresos(const vector<Ingresos>& i);
	static double obtenerIngresoTotalDeCuenta(vector<Ingresos>& i, int cuentaId);

	static vector<Ingresos> leerIngresos(); // obtener todos los ingresos
	static bool guardarIngreso(Ingresos& i);
};