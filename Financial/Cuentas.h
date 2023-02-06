#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream> 

using std::string;

// global variables
const string ARCHIVO_CUENTAS{ "Cuentas.txt" };
const string ARCHIVO_INGRESOS{ "Ingresos.txt" };
const string ARCHIVO_GASTOS{ "Gastos.txt" };

using namespace std;

class Cuentas
{
private:
	int mId{ 0 };
	string mNombre{ "null" };
	string mComentarios{ "null" };
	string mFechaCreacion{ "null" };
	float mValorInicial{ 0.0f};
	int mTipoDeCuenta{ 0 };
	int mTipoDeMoneda{ 0 };
	bool mEscondido{ false };
	bool mArchivado{ false };

public:
	// constructor
	Cuentas(int id, string nombre, float valorInicial, int tipoDeCuenta, int tipoDeMoneda, string comentarios);
	Cuentas(int id, string nombre, float valorInicial);

	// Getters
	int obtenerId() const { return mId; };
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

	// Functions
	static void imprimirCuentas(vector<Cuentas>& c);
	static bool guardarCuenta(Cuentas& c);
	static vector<Cuentas> leerCuentas();
	static int getNextFreeId(const vector<Cuentas> &c); // get the next free Id to be assigned

};

