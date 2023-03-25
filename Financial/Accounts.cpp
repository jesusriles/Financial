#include "Accounts.h"

// Constructors
Accounts::Accounts(int id, string nombre, float valorInicial,
	ACCOUNT_TYPE tipoDeCuenta, CURRENCY tipoDeMoneda, string comentarios) :
	mId{ id }, mName {nombre}, mInitialValue{ valorInicial },
	mAccountType {tipoDeCuenta}, mCurrency {tipoDeMoneda}, mComments {comentarios}
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

	if (mComments.length() > 50) {
		string error_message{ "[ERROR] El comentario debe tener maximo 200 caracteres" };
		cout << error_message << endl;
		throw(error_message);
	}
;}

Accounts::Accounts(int id, string nombre, float valorInicial, ACCOUNT_TYPE tipoDeCuenta) :
	mId{ id }, mName{ nombre }, mInitialValue{ valorInicial }, mAccountType{ tipoDeCuenta } {
	Accounts::Accounts(
		mId,
		mName,
		mInitialValue,
		mAccountType,
		CURRENCY::MXN, // MXN will be the default
		"null"); // comentarios
}

void Accounts::printAccounts(const vector<Accounts> &c)
{ 
	system("CLS");
	if (c.empty()) {
		cout << "No accounts created." << endl;
		return;
	}

	// header
	cout << "Id\t" << "Name" << setw(26) << "Amount" << endl;
	cout << "--------------------------------------------------" << endl;

	for (Accounts cuenta : c) {
		if (cuenta.getStatus() == STATUS::HIDDEN || 
			cuenta.getStatus() == STATUS::DELETED ||
			cuenta.getStatus() == STATUS::ARCHIVED) continue;
		int tabSize = 25 - cuenta.mName.size();

		std::cout.imbue(std::locale(""));
		std::cout << std::fixed << std::showpoint << std::setprecision(2);
		cout << cuenta.mId << "\t" << cuenta.mName << setw(tabSize) << "$" << cuenta.mInitialValue << endl;
	}
	cout << endl;
	system("PAUSE"); // wait user input to continue
}

int Accounts::getNextFreeId() {
	vector<Accounts> c = Accounts::readAccounts();
	if (c.empty())
		return 1;

	int nextId = (c[c.size() - 1].getId()) + 1;

	// make sure the id doesn't exist in the already created accounts
	bool duplicatedId{ true };

	while (duplicatedId) {
		for (Accounts cuenta : c) {
			if (cuenta.getId() == nextId) { // id already exist, assign another
				++nextId;
				break;
			}
		}
		duplicatedId = false;
	}
	return nextId;
}

bool Accounts::saveAccount(Accounts& c) {

	ofstream file;
	file.open(FILE_ACCOUNTS, fstream::app);

	file <<
		c.getId() << "," <<
		c.getName() << "," <<
		c.getComments() << "," <<
		c.getDateCreated() << "," <<
		c.getInitialValue() << std::showpoint << std::setprecision(2) << "," <<
		c.accountTypeToString() << "," <<	// TIPODECUENTA changed to text
		c.currencyToString() << "," <<	// TIPODEMONEDA changed to text
		c.statusToString() << ";" <<		// STATUS changed to text
		endl;
	file.close();
	return true;
}

vector<Accounts> Accounts::readAccounts() {

	string lineTmp{};
	ifstream file(FILE_ACCOUNTS, std::ifstream::in);

	vector<string> vLine{}; // TODO: creo que no se usa, revisar
	vector<Accounts> cuentas{};

	for (int i{ 0 }; getline(file, lineTmp); ++i) { // iterar sobre cada linea

		int contadorDeComas{ 0 };
		string s{};

		// valores que se necesitan para hacer la clase de tipo Cuentas
		int tmpId{ 0 };							// 0
		string tmpNombre{};						// 1
		string tmpComentarios{ "null" };		// 2
		string tmpFechaCreacion{ "null" };		// 3
		float tmpValorInicial{ 0.0f };			// 4
		ACCOUNT_TYPE tmpTipoDeCuenta{ ACCOUNT_TYPE::OTHER };				// 5
		CURRENCY tmpTipoDeMoneda{ CURRENCY::OTHER };				// 6
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
				else if (contadorDeComas == 5) tmpTipoDeCuenta = stringToAccountType(s);
				else if (contadorDeComas == 6) tmpTipoDeMoneda = stringToCurrency(s);
				else if (contadorDeComas == 7) {
					tmpStatus = stringToStatus(s);

					// se crea la cuenta y se agrega al vector cuentas
					Accounts tmpAccount{ tmpId, tmpNombre, tmpValorInicial, tmpTipoDeCuenta, tmpTipoDeMoneda, tmpComentarios };
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
string Accounts::accountTypeToString() const {
	switch (mAccountType) {
	case ACCOUNT_TYPE::DEBITO: 
		return "Debito";
	case ACCOUNT_TYPE::CREDITO:
		return "Credito";
	}
	return "Other";
}

/* TIPODECUENTA is stored in the file as text (this function is to convert text to "TIPODECUENTA" */
ACCOUNT_TYPE Accounts::stringToAccountType(const string &s) {
	if (s == "Debito") return ACCOUNT_TYPE::DEBITO;
	else if (s == "Credito") return ACCOUNT_TYPE::CREDITO;

	return ACCOUNT_TYPE::OTHER;
}

/* TIPODEMONEDA is stored in the file as text (this function is to convert "TIPODEMONEDA" to text */
string Accounts::currencyToString() const {
	switch (mCurrency) {
	case CURRENCY::MXN:
		return "MXN";
	case CURRENCY::USD:
		return "USD";
	case CURRENCY::EUR:
		return "EUR";
	}
	return "Other";
}

/* TIPODEMONEDA is stored in the file as text (this function is to convert text to "TIPODEMONEDA" */
CURRENCY Accounts::stringToCurrency(const string &s) {
	if (s == "MXN") return CURRENCY::MXN;
	else if (s == "USD") return CURRENCY::USD;
	else if (s == "EUR") return CURRENCY::EUR;

	return CURRENCY::OTHER;
}

/* STATUS is stored in the file as text (this function is to convert "STATUS" to text */
string Accounts::statusToString() const {
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
STATUS Accounts::stringToStatus(const string& s) {
	if (s == "Active") return STATUS::ACTIVE;
	else if (s == "Hidden") return STATUS::HIDDEN;
	else if (s == "Deleted") return STATUS::DELETED;
	else if (s == "Archived") return STATUS::ARCHIVED;

	return STATUS::OTHER;
}

void Accounts::deleteAccount() {

	if (this->getStatus() == STATUS::DELETED) { return; }

	string oldStatusToString{ this->statusToString() };
	mStatus = STATUS::DELETED;
	string newStatusToString{ this->statusToString() };

	fstream file(FILE_ACCOUNTS, std::ifstream::in);

	replaceWordInFileWithId(oldStatusToString, newStatusToString, file, FILE_ACCOUNTS, mId);
	file.close();
}

void Accounts::restoreAccount() {

	if (this->getStatus() == STATUS::ACTIVE) { return; }

	string oldStatusToString{ this->statusToString() };
	mStatus = STATUS::ACTIVE;
	string newStatusToString{ this->statusToString() };

	fstream file(FILE_ACCOUNTS, std::ifstream::in);

	replaceWordInFileWithId(oldStatusToString, newStatusToString, file, FILE_ACCOUNTS, mId);
	file.close();
}

void Accounts::replaceWordInFileWithId(const string& wordToReplace, const string& newWord,
	fstream& file, string fileName, const int& id) {
	
	ofstream newFile;
	string newFileName{ fileName + ".tmp" };

	newFile.open(newFileName, fstream::app);

	string lineTmp{};
	for (int i{ 0 }; getline(file, lineTmp); ++i) {
		string tmpId{ getIdFromLine(lineTmp) };

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

string Accounts::getIdFromLine(const string& line) {
	string id{};
	for (char c : line) {
		if (c == ',') break;
		id += c;
	}
	return id;
}

void Accounts::renameAccount(const string newAccountName) {
	fstream file(FILE_ACCOUNTS, std::ifstream::in);
	string currentAccountName{ getName() };		

	replaceWordInFileWithId(currentAccountName, newAccountName, file, FILE_ACCOUNTS, mId);
	file.close();
}

int Accounts::printByAccountType(const vector<Accounts>& c) {
	system("CLS");
	vector<Accounts> debit{};
	vector<Accounts> credit{};
	vector<Accounts> other{};

	// separate accounts by account type
	for (Accounts a : c) {
		if (a.getStatus() != STATUS::ACTIVE) continue;

		if (a.getAccountType() == ACCOUNT_TYPE::DEBITO) {
			debit.push_back(a);
			continue;
		}
				
		else if (a.getAccountType() == ACCOUNT_TYPE::CREDITO) {
			credit.push_back(a);
			continue;
		}
		other.push_back(a);
	}

	// print accounts by account type
	cout << "** Debit **" << endl;
	for (Accounts deb : debit) {
		cout << "(" + to_string(deb.getId()) + ") " << deb.getName() << endl;
	}

	cout << "\n** Credit **" << endl;
	for (Accounts cred : credit) {
		cout << "(" + to_string(cred.getId()) + ") " << cred.getName() << endl;
	}

	cout << "\n** Others **" << endl;
	for (Accounts oth : other) {
		cout << "(" + to_string(oth.getId()) + ") " << oth.getName() << endl << endl;
	}

	int accountId{  };
	cout << "Select account > ";
	cin >> accountId;
	return accountId;
}