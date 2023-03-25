#include "Transactions.h"

Transactions::Transactions(int tmpId, string tmpShortDescription, int tmpAccountId, float tmpAmount, 
								TRANSACTION_TYPE tmpTransactionType)
{
	mId = tmpId;
	mShortDescription = tmpShortDescription;
	mAccountId = tmpAccountId;
	mAmount = tmpAmount;
	mTransactionType = tmpTransactionType;
}

void Transactions::printTransactions(const vector<Transactions> &i) {
	system("CLS");
	// Modificar un numero para que muestre comas (e.j. 1,000,999.321)
	std::cout.imbue(std::locale(""));
	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	for (Transactions ingreso : i) {
		int tabSize = 40 - ingreso.mShortDescription.size();

		cout << ingreso.mId << "\t" << ingreso.mAccountId << "\t" <<
			ingreso.mShortDescription << setw(tabSize) << ingreso.mAmount << endl;
	}
	system("PAUSE"); // wait user input to continue
}

double Transactions::getTotalIncomesOfAccount(vector<Transactions> &i, int cuentaId) {

	float total{ 0 };

	for (Transactions ingreso : i) {
		if(ingreso.getTransactionType() == TRANSACTION_TYPE::INCOME && ingreso.getAccountId() == cuentaId)
		total += ingreso.mAmount;
	}
	return total;
}

bool Transactions::saveIncomes(Transactions& i) {

	ofstream file;
	file.open(FILE_TRANSACTIONS, fstream::app);

	file <<
		i.getId() << "," <<
		i.getShortDescription() << "," <<
		i.getAccountId() << "," <<
		i.getAmount() << "," <<
		i.transactionTypeToString() << ";" <<
		endl;

	file.close();
	return true;
}

vector<Transactions> Transactions::readIncomes() {

	string lineTmp{};
	ifstream file(FILE_TRANSACTIONS, std::ifstream::in);

	vector<Transactions> ingresos{};

	for (int i{ 0 }; getline(file, lineTmp); ++i) { // iterar sobre cada linea

		int contadorDeComas{ 0 };
		string s{};

		// valores que se necesitan para hacer la clase de tipo Ingresos
		int tmpId{ 0 };
		string tmpShortDescription{};
		int tmpIdCuentaAsociada{ 0 };
		float tmpCantidad{ 0 };
		TRANSACTION_TYPE tmpTransactionType{ TRANSACTION_TYPE::OTHER };

		for (int x{ 0 }; x < lineTmp.size(); ++x) { // iterar sobre cada letra en cada linea

			if (lineTmp[x] != ',' && lineTmp[x] != ';') { // separar cada elemento por coma
				s += lineTmp[x];
			}

			else {
				// asignar los valores
				if (contadorDeComas == 0) tmpId = stoi(s);
				else if (contadorDeComas == 1) tmpShortDescription = s;
				else if (contadorDeComas == 2)  tmpIdCuentaAsociada = stoi(s);
				else if (contadorDeComas == 3) tmpCantidad = stof(s);
				else if (contadorDeComas == 4) {
					
					tmpTransactionType = stringToTransactionType(s);
					// se crea la cuenta y se agrega al vector cuentas
					ingresos.push_back(Transactions(tmpId, tmpShortDescription, tmpIdCuentaAsociada, tmpCantidad, tmpTransactionType));
				}
				contadorDeComas++;
				s = "";
			}
		}
	}
	return ingresos;
}

/* TRANSACTION_TYPE is stored in the file as text (this function is to convert "TRANSACTION_TYPE" to text */
string Transactions::transactionTypeToString() const {
	switch (mTransactionType) {
	case TRANSACTION_TYPE::INCOME:
		return "Income";
	case TRANSACTION_TYPE::EXPENSE:
		return "Expense";
	case TRANSACTION_TYPE::TRANSFER:
		return "Transfer";
	}
	return "Other";
}

/* TRANSACTION_TYPE is stored in the file as text (this function is to convert text to "TRANSACTION_TYPE" */
TRANSACTION_TYPE Transactions::stringToTransactionType(const string& s) {
	if (s == "Income") return TRANSACTION_TYPE::INCOME;
	else if (s == "Expense") return TRANSACTION_TYPE::EXPENSE;
	else if (s == "Transfer") return TRANSACTION_TYPE::TRANSFER;

	return TRANSACTION_TYPE::OTHER;
}

int Transactions::getNextFreeId() {
	vector<Transactions> t = Transactions::readIncomes();
	if (t.empty())
		return 1;

	int nextId = (t[t.size() - 1].getId()) + 1;

	// make sure the id doesn't exist in the already created accounts
	bool duplicatedId{ true };

	while (duplicatedId) {
		for (Transactions transaction : t) {
			if (transaction.getId() == nextId) { // id already exist, assign another
				++nextId;
				break;
			}
		}
		duplicatedId = false;
	}
	return nextId;
}