#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Cuentas
{
private:
	int mId;
	string mNombre{};
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
	Cuentas(int id, string nombre, float valorInicial);

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

	// Setters
	void setId(int tmpId) { mId = tmpId; }
	void setNombre(string tmpNombre) { mNombre = tmpNombre; };
	void setComentario(string tmpComentario) { mComentarios = tmpComentario; };
	void setFechaCreacion(string tmpFechaCreacion) { mFechaCreacion = tmpFechaCreacion; };
	void setValorInicial(float tmpValorInicial) { mValorInicial = tmpValorInicial; };
	void setTipoDeCuenta(int tmpTipoDeCuenta) { mTipoDeCuenta = tmpTipoDeCuenta; };
	void setTipoDeMoneda(int tmpTipoDeMoneda) { mTipoDeMoneda = tmpTipoDeMoneda; };
	void setEscondido(bool tmpEscondido) { mEscondido = tmpEscondido; };
	void setArchivado(bool tmpArchivado) { mArchivado = tmpArchivado; };

	// Funciones
	static void imprimirCuentas(vector<Cuentas> &c); // imprimir informacion relevante de una cuenta
};

