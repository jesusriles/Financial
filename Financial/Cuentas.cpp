#include "Cuentas.h"

// Constructors
Cuentas::Cuentas(int id, string nombre, float valorInicial,
	int tipoDeCuenta, int tipoDeMoneda, string comentarios) :
	mId {id}, mNombre {nombre}, mValorInicial {valorInicial},
	mTipoDeCuenta {tipoDeCuenta}, mTipoDeMoneda {tipoDeMoneda}, mComentarios {comentarios}
{
	// id: no puede ser un numero mayor a 100
	if (id < 1 || id > 99)
	{
		throw("El id debe ser un numero entre 1 y 99");
	}

	// nombre: maximo 30 caracteres
	if (nombre.length() > 30)
	{
		throw("El nombre debe tener maximo 30 caracteres");
	}

	// nombre: maximo 200 caracteres
	if (mComentarios.length() > 200)
	{
		throw("El comentario debe tener maximo 200 caracteres");
	}
;}

Cuentas::Cuentas(int id, string nombre, float valorInicial) :
	mId{ id }, mNombre{ nombre }, mValorInicial{ valorInicial }
{
	Cuentas::Cuentas(
		id,
		nombre,
		valorInicial,
		1, // tipo de cuenta
		1, // tipo de moneda
		"null"); // comentarios
}

void Cuentas::imprimirCuentas(vector<Cuentas> &c)
{ 
	system("CLS");
	for (Cuentas cuenta : c) {
		int tabSize = 25 - cuenta.mNombre.size();

		std::cout.imbue(std::locale(""));
		std::cout << std::fixed << std::showpoint << std::setprecision(3);
		cout << cuenta.mNombre << setw(tabSize) << "$" << cuenta.mValorInicial << endl;
	}
}