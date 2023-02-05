#include "FileMgmt.h"

/*
Funciones de Cuentas
*/
bool FileMgmt::guardarCuenta(Cuentas &c) {

	ofstream file;
	file.open(ARCHIVO_CUENTAS, fstream::app);
	
	file <<
		c.obtenerId() << "," <<
		c.obtenerNombre() << "," <<
		c.obtenerComentario() << "," <<
		c.obtenerFechaCreacion() << "," <<
		c.obtenerValorInicial() << "," <<
		c.obtenerTipoDeCuenta() << "," <<
		c.obtenerTipoDeMoneda() << "," <<
		c.obtenerEscondido() << "," <<
		c.obtenerArchivado() << ";" <<
		endl;
	
	file.close();
	return true;
}

vector<Cuentas> FileMgmt::leerCuentas() {

	string lineTmp{};
	ifstream file(ARCHIVO_CUENTAS, std::ifstream::in);

	vector<string> vLine{}; // TODO: creo que no se usa, revisar
	vector<Cuentas> cuentas{};

	for (int i{ 0 }; getline(file, lineTmp); ++i) { // iterar sobre cada linea

		int contadorDeComas{ 0 };
		string s{};

		// valores que se necesitan para hacer la clase de tipo Cuentas
		int tmpId{ 0 };							// 0
		string tmpNombre{};						// 1
		string tmpComentarios{ "null" };		// 2
		string tmpFechaCreacion{ "null" };		// 3
		float tmpValorInicial{ 0.0f };			// 4
		int tmpTipoDeCuenta{ 1 };				// 5
		int tmpTipoDeMoneda{ 1 };				// 6
		bool tmpEscondido{ false };				// 7
		bool tmpArchivado{ false };				// 8

		for (int x{ 0 }; x < lineTmp.size(); ++x) { // iterar sobre cada letra en cada linea

			if (lineTmp[x] != ',' && lineTmp[x] != ';') { // separar cada elemento por coma
				s += lineTmp[x];
			}

			else {
				// asignar los valores
				if (contadorDeComas == 0) tmpId = stoi(s);
				else if (contadorDeComas == 1) tmpNombre = s;
				else if (contadorDeComas == 2) tmpComentarios = s;
				else if (contadorDeComas == 3) tmpFechaCreacion = s;
				else if (contadorDeComas == 4) tmpValorInicial = stof(s);
				else if (contadorDeComas == 5) tmpTipoDeCuenta = stoi(s);
				else if (contadorDeComas == 6) tmpTipoDeMoneda = stoi(s);
				else if (contadorDeComas == 7) tmpEscondido = (s == "false") ? false : true;
				else if (contadorDeComas == 8) {
					tmpArchivado = (s == "false") ? false : true;

					// se crea la cuenta y se agrega al vector cuentas
					cuentas.push_back(Cuentas(tmpId, tmpNombre, tmpValorInicial,
						tmpTipoDeCuenta, tmpTipoDeMoneda, tmpComentarios));
				}

				contadorDeComas++;
				s = "";
			}			
		}
	}
	
	file.close();
	return cuentas;
}


/* 
Funciones de Ingresos 
*/

bool FileMgmt::guardarIngreso(Ingresos& i) {

	ofstream file;
	file.open(ARCHIVO_INGRESOS, fstream::app);

	file <<
		i.getId() << "," <<
		i.getIdCuentaAsociada() << "," <<
		i.getCantidad() << ";" <<
		endl;

	file.close();
	return true;
}

vector<Ingresos> FileMgmt::leerIngresos() {

	string lineTmp{};
	ifstream file(ARCHIVO_INGRESOS, std::ifstream::in);

	vector<Ingresos> ingresos{};

	for (int i{ 0 }; getline(file, lineTmp); ++i) { // iterar sobre cada linea

		int contadorDeComas{ 0 };
		string s{};

		// valores que se necesitan para hacer la clase de tipo Ingresos
		int tmpId{ 0 };					// 0
		int tmpIdCuentaAsociada{ 0 };		// 1
		float tmpCantidad{ 0 };			// 2

		for (int x{ 0 }; x < lineTmp.size(); ++x) { // iterar sobre cada letra en cada linea

			if (lineTmp[x] != ',' && lineTmp[x] != ';') { // separar cada elemento por coma
				s += lineTmp[x];
			}

			else {
				// asignar los valores
				if (contadorDeComas == 0) tmpId = stoi(s);
				else if (contadorDeComas == 1)  tmpIdCuentaAsociada = stoi(s);
				else if (contadorDeComas == 2) {
					tmpCantidad = stof(s);

					// se crea la cuenta y se agrega al vector cuentas
					ingresos.push_back(Ingresos(tmpId, tmpIdCuentaAsociada, tmpCantidad));
				}

				contadorDeComas++;
				s = "";
			}
		}
	}
	return ingresos;
}