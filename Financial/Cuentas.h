#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream> 

using std::string;
using namespace std;

// global variables
const string ARCHIVO_CUENTAS{ "Cuentas.txt" };
const string ARCHIVO_INGRESOS{ "Ingresos.txt" };
const string ARCHIVO_GASTOS{ "Gastos.txt" };

const int MAX_AVAILABLE_IDS{ 99 };

enum class TIPODECUENTA {
	DEBITO = 1,
	CREDITO = 2,
	OTHER = 99
};

class Cuentas 
{
private:
	int mId{ 0 };
	string mNombre{ "null" };
	string mComentarios{ "null" };
	string mFechaCreacion{ "null" };
	float mValorInicial{ 0.0f};
	TIPODECUENTA mTipoDeCuenta{ TIPODECUENTA::OTHER };
	int mTipoDeMoneda{ 0 };
	bool mEscondido{ false };
	bool mArchivado{ false };

public:
	// constructor
	Cuentas(int id, string nombre, float valorInicial, TIPODECUENTA tipoDeCuenta, int tipoDeMoneda, string comentarios);
	Cuentas(int id, string nombre, float valorInicial, TIPODECUENTA tipoDeCuenta);

	// getters
	int obtenerId() const { return mId; };
	string obtenerNombre() const { return mNombre; };
	string obtenerComentario() const { return mComentarios; };
	string obtenerFechaCreacion() const { return mFechaCreacion; };
	float obtenerValorInicial() const { return mValorInicial; };
	TIPODECUENTA obtenerTipoDeCuenta() const { return mTipoDeCuenta; };
	int obtenerTipoDeMoneda() const { return mTipoDeMoneda; };
	bool obtenerEscondido() const { return mEscondido; };
	bool obtenerArchivado() const { return mArchivado; };

	// setters
	void setId(int tmpId) { mId = tmpId; }
	void setNombre(string tmpNombre) { mNombre = tmpNombre; };
	void setComentario(string tmpComentario) { mComentarios = tmpComentario; };
	void setFechaCreacion(string tmpFechaCreacion) { mFechaCreacion = tmpFechaCreacion; };
	void setValorInicial(float tmpValorInicial) { mValorInicial = tmpValorInicial; };
	void setTipoDeCuenta(TIPODECUENTA tmpTipoDeCuenta) { mTipoDeCuenta = tmpTipoDeCuenta; };
	void setTipoDeMoneda(int tmpTipoDeMoneda) { mTipoDeMoneda = tmpTipoDeMoneda; };
	void setEscondido(bool tmpEscondido) { mEscondido = tmpEscondido; };
	void setArchivado(bool tmpArchivado) { mArchivado = tmpArchivado; };

	// functions
	static void imprimirCuentas(vector<Cuentas>& c);
	static bool guardarCuenta(Cuentas& c);
	static vector<Cuentas> leerCuentas();
	static int getNextFreeId(const vector<Cuentas> &c); // get the next free Id to be assigned

	string tipoDeCuentaToString() const;
	static TIPODECUENTA StringToTipoDeCuenta(string s);
};