#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Cuentas
{
private:
	int mId;
	string mNombre;
	string mComentarios{ "null" };
	string fechaCreacion{ "null" };
	float mValorInicial{ 0.0f};
	int mTipoDeCuenta{ 1 };
	int mTipoDeMoneda{ 1 };
	bool mEscondido{ false };
	bool mArchivado{ false };
	

public:
	Cuentas(int id, string nombre, float valorInicial,
		int tipoDeCuenta, int tipoDeMoneda, string comentarios);	

	void imprimirCuenta(); // imprimir toda la informacion de una cuenta
	void imprimirCuentaRelevante(); // imprimir informacion relevante de una cuenta
};

