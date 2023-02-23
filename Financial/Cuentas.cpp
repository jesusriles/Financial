#include "Cuentas.h"

// Constructors
Cuentas::Cuentas(int id, string nombre, float valorInicial,
	TIPODECUENTA tipoDeCuenta, TIPODEMONEDA tipoDeMoneda, string comentarios) :
	mId{ id }, mNombre {nombre}, mValorInicial{ valorInicial },
	mTipoDeCuenta {tipoDeCuenta}, mTipoDeMoneda {tipoDeMoneda}, mComentarios {comentarios}
{	
	if (id < 1 || id > 99) {
		string error_message{ "[ERROR] Error: El id no debe ser mayor a " + MAX_AVAILABLE_IDS };
		cout << error_message << endl;
		throw(error_message);
	}

	if (nombre.length() > 30) {
		string error_message{ "[ERROR] El nombre debe tener maximo 30 caracteres" };
		cout << error_message << endl;
		throw(error_message);
	}

	if (nombre.find(",") != std::string::npos) {
		string error_message{ "[ERROR] El nombre no puedo incluir el caracter \",\"" };
		cout << error_message << endl;
		throw(error_message);
	}

	if (mComentarios.length() > 50) {
		string error_message{ "[ERROR] El comentario debe tener maximo 200 caracteres" };
		cout << error_message << endl;
		throw(error_message);
	}
;}

Cuentas::Cuentas(int id, string nombre, float valorInicial, TIPODECUENTA tipoDeCuenta) : 
	mId{ id }, mNombre{ nombre }, mValorInicial{ valorInicial }, mTipoDeCuenta{ tipoDeCuenta } {
	Cuentas::Cuentas(
		mId,
		mNombre,
		mValorInicial,
		mTipoDeCuenta,
		TIPODEMONEDA::MXN, // MXN will be the default
		"null"); // comentarios
}

void Cuentas::imprimirCuentas(const vector<Cuentas> &c)
{ 
	system("CLS");
	if (c.empty()) {
		cout << "No accounts created." << endl;
		return;
	}

	for (Cuentas cuenta : c) {
		if (cuenta.obtenerStatus() == STATUS::HIDDEN || 
			cuenta.obtenerStatus() == STATUS::DELETED ||
			cuenta.obtenerStatus() == STATUS::ARCHIVED) continue;
		int tabSize = 25 - cuenta.mNombre.size();

		std::cout.imbue(std::locale(""));
		std::cout << std::fixed << std::showpoint << std::setprecision(2);
		cout << cuenta.mNombre << setw(tabSize) << "$" << cuenta.mValorInicial << endl;
	}
	cout << endl;
	system("PAUSE"); // wait user input to continue
}

int Cuentas::getNextFreeId() {
	vector<Cuentas> c = Cuentas::leerCuentas();
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
		c.obtenerValorInicial() << std::showpoint << std::setprecision(2) << "," <<
		c.tipoDeCuentaToString() << "," <<	// TIPODECUENTA changed to text
		c.tipoDeMonedaToString() << "," <<	// TIPODEMONEDA changed to text
		c.statusToString() << ";" <<		// STATUS changed to text
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
		TIPODECUENTA tmpTipoDeCuenta{ TIPODECUENTA::OTHER };				// 5
		TIPODEMONEDA tmpTipoDeMoneda{ TIPODEMONEDA::OTHER };				// 6
		STATUS tmpStatus{ STATUS::OTHER };				// 7

		std::cout.precision(2);

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
				else if (contadorDeComas == 5) tmpTipoDeCuenta = stringToTipoDeCuenta(s);
				else if (contadorDeComas == 6) tmpTipoDeMoneda = stringToTipoDeMoneda(s);
				else if (contadorDeComas == 7) {
					tmpStatus = stringToStatus(s);

					// se crea la cuenta y se agrega al vector cuentas
					Cuentas tmpAccount{ tmpId, tmpNombre, tmpValorInicial, tmpTipoDeCuenta, tmpTipoDeMoneda, tmpComentarios };
					tmpAccount.setStatus(tmpStatus); // set the status
					cuentas.push_back(tmpAccount);
				}
				contadorDeComas++;
				s = "";
			}
		}
	}
	file.close();
	return cuentas;
}

/* TIPODECUENTA is stored in the file as text (this function is to convert "TIPODECUENTA" to text */
string Cuentas::tipoDeCuentaToString() const {
	switch (mTipoDeCuenta) {
	case TIPODECUENTA::DEBITO: 
		return "Debito";
	case TIPODECUENTA::CREDITO:
		return "Credito";
	}
	return "Other";
}

/* TIPODECUENTA is stored in the file as text (this function is to convert text to "TIPODECUENTA" */
TIPODECUENTA Cuentas::stringToTipoDeCuenta(const string &s) {
	if (s == "Debito") return TIPODECUENTA::DEBITO;
	else if (s == "Credito") return TIPODECUENTA::CREDITO;

	return TIPODECUENTA::OTHER;
}

/* TIPODEMONEDA is stored in the file as text (this function is to convert "TIPODEMONEDA" to text */
string Cuentas::tipoDeMonedaToString() const {
	switch (mTipoDeMoneda) {
	case TIPODEMONEDA::MXN:
		return "MXN";
	case TIPODEMONEDA::USD:
		return "USD";
	case TIPODEMONEDA::EUR:
		return "EUR";
	}
	return "Other";
}

/* TIPODEMONEDA is stored in the file as text (this function is to convert text to "TIPODEMONEDA" */
TIPODEMONEDA Cuentas::stringToTipoDeMoneda(const string &s) {
	if (s == "MXN") return TIPODEMONEDA::MXN;
	else if (s == "USD") return TIPODEMONEDA::USD;
	else if (s == "EUR") return TIPODEMONEDA::EUR;

	return TIPODEMONEDA::OTHER;
}

/* STATUS is stored in the file as text (this function is to convert "STATUS" to text */
string Cuentas::statusToString() const {
	switch (mStatus) {
	case STATUS::ACTIVE:
		return "Active";
	case STATUS::HIDDEN:
		return "Hidden";
	case STATUS::DELETED:
		return "Deleted";
	case STATUS::ARCHIVED:
		return "Archived";
	}
	return "Other";
}

/* STATUS is stored in the file as text (this function is to convert text to "STATUS" */
STATUS Cuentas::stringToStatus(const string& s) {
	if (s == "Active") return STATUS::ACTIVE;
	else if (s == "Hidden") return STATUS::HIDDEN;
	else if (s == "Deleted") return STATUS::DELETED;
	else if (s == "Archived") return STATUS::ARCHIVED;

	return STATUS::OTHER;
}

/*
	- update the status of the current object

	- update the status in the file
		[] create a backup of the original file to <filename>.old.#

		[x] create a new file with <filename> where all information is going to be store
		[x] Read line by line
			[x] if the line is not the one to be replaced, write it to a new file
			[x] if the line is the one to be replaced, replace the word and write it to the new file
*/

void Cuentas::deleteAccount() {

	if (this->obtenerStatus() == STATUS::DELETED) { return; }

	string oldStatusToString{ this->statusToString() };
	mStatus = STATUS::DELETED;
	string newStatusToString{ this->statusToString() };

	// update the status in the file
//	auto status = rename(ARCHIVO_CUENTAS.c_str(), "Hola.txt");
	fstream file(ARCHIVO_CUENTAS, std::ifstream::in);

	replaceWordInFileWithId(oldStatusToString, newStatusToString, file, ARCHIVO_CUENTAS, mId);
	file.close();
}

void Cuentas::replaceWordInFileWithId(
	const string& wordToReplace, const string& newWord, 
	fstream& file, string fileName, 
	const int& id) {
	
	ofstream newFile;
	string newFileName{ fileName + ".tmp" };

	newFile.open(newFileName, fstream::app);

	string lineTmp{};
	for (int i{ 0 }; getline(file, lineTmp); ++i) {
		string tmpId{ lineTmp[0] }; // TODO: this is a mistake, cause it only works with 1 digit accounts

		if (to_string(id) == tmpId) {
			size_t pos = lineTmp.find(wordToReplace);
			if (pos != std::string::npos) {
				lineTmp.replace(pos, wordToReplace.length(), newWord);
			}			
		}
		newFile << lineTmp << "\n";
	}
	newFile.close();
	file.close();
	
	remove("OLD_FILE_NAME.tmp.txt");
	rename(fileName.c_str(), "OLD_FILE_NAME.tmp.txt");
	rename(newFileName.c_str(), fileName.c_str() );
}