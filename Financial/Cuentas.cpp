#include "Cuentas.h"

// Constructors
Cuentas::Cuentas(int id, string nombre, float valorInicial,
	int tipoDeCuenta, int tipoDeMoneda, string comentarios) :
	mId{ id }, mNombre {nombre}, mValorInicial{ valorInicial },
	mTipoDeCuenta {tipoDeCuenta}, mTipoDeMoneda {tipoDeMoneda}, mComentarios {comentarios}
{	
	if (id < 1 || id > 99)
	{
		string error_message{ "[ERROR] Error: El id no debe ser mayor a " + MAX_AVAILABLE_IDS };
		cout << error_message << endl;
		throw(error_message);
	}

	if (nombre.length() > 30)
	{
		string error_message{ "[ERROR] El nombre debe tener maximo 30 caracteres" };
		cout << error_message << endl;
		throw(error_message);
	}

	if (nombre.find(",") != std::string::npos) {
		string error_message{ "[ERROR] El nombre no puedo incluir el caracter \",\"" };
		cout << error_message << endl;
		throw(error_message);
	}

	if (mComentarios.length() > 50)
	{
		string error_message{ "[ERROR] El comentario debe tener maximo 200 caracteres" };
		cout << error_message << endl;
		throw(error_message);
	}
;}

Cuentas::Cuentas(int id, string nombre, float valorInicial) 
	:mId{ id }, mNombre { nombre }, mValorInicial{ valorInicial }
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
	if (c.empty()) {
		cout << "No accounts created." << endl;
		return;
	}

	for (Cuentas cuenta : c) {
		int tabSize = 25 - cuenta.mNombre.size();

		std::cout.imbue(std::locale(""));
		std::cout << std::fixed << std::showpoint << std::setprecision(3);
		cout << cuenta.mNombre << setw(tabSize) << "$" << cuenta.mValorInicial << endl;
	}
}

int Cuentas::getNextFreeId(const vector<Cuentas> &c) {

	if (c.empty())
		return 1;

	int nextId = (c[c.size() - 1].obtenerId()) + 1;

	// make sure the id doesn't exist in the already created accounts
	bool duplicatedId{ true };

	while (duplicatedId) {
		for (Cuentas cuenta : c) {
			if (cuenta.obtenerId() == nextId) { // id already exist, assign another
				++nextId;
				break;
			}
		}
		duplicatedId = false;
	}
	return nextId;
}

bool Cuentas::guardarCuenta(Cuentas& c) {

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

vector<Cuentas> Cuentas::leerCuentas() {

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