#include "FileMgmt.h"

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

	vector<string> vLine{};
	vector<Cuentas> cuentas{};

	for (int i{ 0 }; getline(file, lineTmp); ++i) { // iterar sobre cada linea

		int contadorDeComas{ 0 };
		string s{};

		// valores que se necesitan para hacer la clase
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