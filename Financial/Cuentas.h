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
	string mFechaCreacion{ "null" };
	float mValorInicial{ 0.0f};
	int mTipoDeCuenta{ 1 };
	int mTipoDeMoneda{ 1 };
	bool mEscondido{ false };
	bool mArchivado{ false };
	
public:
	// constructor
	Cuentas(int id, string nombre, float valorInicial,
		int tipoDeCuenta, int tipoDeMoneda, string comentarios);

	// Getters
	int obtenerId() { return mId; };
	string obtenerNombre() { return mNombre; };
	string obtenerComentario() { return mComentarios; };
	string obtenerFechaCreacion() { return mFechaCreacion; };
	float obtenerValorInicial() { return mValorInicial; };
	int obtenerTipoDeCuenta() { return mTipoDeCuenta; };
	int obtenerTipoDeMoneda() { return mTipoDeMoneda; };
	bool obtenerEscondido() { return mEscondido; };
	bool obtenerArchivado() { return mArchivado; };

	void imprimirCuenta(); // imprimir toda la informacion de una cuenta
	void imprimirCuentaRelevante(); // imprimir informacion relevante de una cuenta
};

