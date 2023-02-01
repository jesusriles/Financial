#include "Cuentas.h"

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

	cout << "[+] Cuenta \"" << mNombre << "\" creada correctamente." << endl;
;}

void Cuentas::imprimirCuenta()
{
	cout << "Id: " << setw(13) << " " << mId << endl;
	cout << "Nombre: " << setw(9) << " " << mNombre << endl;
	cout << "Valor: " << setw(11) << "$" << mValorInicial << endl;
	cout << "Tipo de cuenta: " << setw(1) << " " << mTipoDeCuenta << endl;
	cout << "Tipo de moneda: " << setw(1) << " " << mTipoDeMoneda << endl;
	cout << "Escondido: " << setw(6) << " " << mTipoDeMoneda << endl;
	cout << "Archivado: " << setw(6) << " " << mArchivado << endl;
	cout << "Comentarios: " << setw(4) << " " << mComentarios << endl;

	cout << endl;
}

void Cuentas::imprimirCuentaRelevante()
{
	cout << "Nombre: " << setw(9) << " " << mNombre << endl;
	cout << "Valor: " << setw(11) << "$" << mValorInicial << endl;
	if (mEscondido != 0) cout << "Escondido: " << setw(6) << " " << mTipoDeMoneda << endl;
	if (mArchivado != 0) cout << "Archivado: " << setw(6) << " " << mArchivado << endl;
	if (mComentarios != "null") cout << "Comentarios: " << setw(4) << " " << mComentarios << endl;

	cout << endl;
}