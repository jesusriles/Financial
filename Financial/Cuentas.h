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

enum class TIPODEMONEDA {
	MXN = 1,
	USD = 2,
	EUR = 3,
	OTHER = 99
};

enum class STATUS {
	ACTIVE = 1,		
	HIDDEN = 2,		// account is active but not visible
	DELETED = 3,	// account was marked as deleted (should be able to recover this account)
	ARCHIVED = 4,	// account archived (all related to this account should be moved to another file)
	OTHER = 99		// should not be used
};

class Cuentas 
{
private:
	int mId{ 0 };
	string mNombre{ "null" };
	float mValorInicial{ 0.0f };
	TIPODECUENTA mTipoDeCuenta{ TIPODECUENTA::DEBITO };
	TIPODEMONEDA mTipoDeMoneda{ TIPODEMONEDA::MXN };
	STATUS mStatus{ STATUS::ACTIVE };

	string mFechaCreacion{ "null" };
	string mComentarios{ "null" };

public:
	// constructor
	Cuentas(int id, string nombre, float valorInicial, TIPODECUENTA tipoDeCuenta, TIPODEMONEDA tipoDeMoneda, string comentarios);
	Cuentas(int id, string nombre, float valorInicial, TIPODECUENTA tipoDeCuenta);

	// getters
	int obtenerId() const { return mId; };
	string obtenerNombre() const { return mNombre; };
	string obtenerComentario() const { return mComentarios; };
	string obtenerFechaCreacion() const { return mFechaCreacion; };
	float obtenerValorInicial() const { return mValorInicial; };
	TIPODECUENTA obtenerTipoDeCuenta() const { return mTipoDeCuenta; };
	TIPODEMONEDA obtenerTipoDeMoneda() const { return mTipoDeMoneda; };
	STATUS obtenerStatus() const { return mStatus; };

	// setters
	void setId(int tmpId) { mId = tmpId; }
	void setNombre(string tmpNombre) { mNombre = tmpNombre; };
	void setComentario(string tmpComentario) { mComentarios = tmpComentario; };
	void setFechaCreacion(string tmpFechaCreacion) { mFechaCreacion = tmpFechaCreacion; };
	void setValorInicial(float tmpValorInicial) { mValorInicial = tmpValorInicial; };
	void setTipoDeCuenta(TIPODECUENTA tmpTipoDeCuenta) { mTipoDeCuenta = tmpTipoDeCuenta; };
	void setTipoDeMoneda(TIPODEMONEDA tmpTipoDeMoneda) { mTipoDeMoneda = tmpTipoDeMoneda; };
	void setStatus(STATUS tmpStatus) { mStatus = tmpStatus; };

	// functions
	static void imprimirCuentas(const vector<Cuentas> &c);
	static bool guardarCuenta(Cuentas &c);
	static vector<Cuentas> leerCuentas();
	static int getNextFreeId(const vector<Cuentas> &c); // get the next free Id to be assigned

	string tipoDeCuentaToString() const;
	static TIPODECUENTA stringToTipoDeCuenta(const string &s);

	string tipoDeMonedaToString() const;
	static TIPODEMONEDA stringToTipoDeMoneda(const string &s);

	string statusToString() const;
	static STATUS stringToStatus(const string& s);
};