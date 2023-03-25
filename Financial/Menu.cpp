#include "Menu.h"

/* prints the main menu */
int Menu::printMenu() {

	int option{ 0 };
	while (option != 99) {
		system("CLS");
		cout << "--- General activities ---\n";
		cout << "(1) Accounts" << endl;
		cout << "(2) Income" << endl;
		cout << "(99) Exit" << endl;

		cout << "Option > ";
		cin >> option;

		if (option != 99) optionsMenu(option);
	}
	return option;
}

void Menu::optionsMenu(const int &option) {
	system("CLS");

	// Accounts
	if (option == 1) {	
		int optionCuenta = printMenuAccounts();
		vector<Accounts> cuentas = Accounts::readAccounts();

		if (optionCuenta == 1) Accounts::printAccounts(cuentas);
		else if (optionCuenta == 2)	Menu::createAccount();
		else if (optionCuenta == 3) Menu::deleteAccount(cuentas);
		else if (optionCuenta == 4) Menu::restoreAccount(cuentas);
		else if (optionCuenta == 5) Menu::renameAccount(cuentas);
	}

	// Incomes
	if (option == 2) {
		int optionIncome = printMenuIncome();
		vector<Transactions> ing = Transactions::readIncomes();

		if (optionIncome == 1) Transactions::printTransactions(ing);		
		if (optionIncome == 2) Menu::createIncome();
	}
}

/*
		ACCOUNTS	
*/

int Menu::printMenuAccounts() {
	
	int option{ 0 };
	system("CLS");
	cout << "--- Actividades de cuenta ---\n";
	cout << "(1) Visualizar cuentas" << endl;
	cout << "(2) Agregar cuenta" << endl;
	cout << "(3) Eliminar cuenta" << endl;
	cout << "(4) Recuperar cuenta" << endl;
	cout << "(5) Renombrar cuenta" << endl;

	cout << "(99) Salir" << endl;
	cout << "Option > ";
	cin >> option;
	
	return option;
}

void Menu::createAccount() {
	string nombre{};
	float valor{ 0.00f };

	int tmpTipoDeCuentaInt{ 0 };
	ACCOUNT_TYPE tipoDeCuenta{ ACCOUNT_TYPE::OTHER };

	cout << "Nombre de cuenta> ";
	std::cin.ignore();
	getline(std::cin, nombre);

	cout << "Valor inicial de cuenta> ";
	std::cin >> setprecision(2) >> valor;

	cout << "Tipo de cuenta:\n(1) Debito\n(2) Credito\n> ";
	std::cin >> tmpTipoDeCuentaInt;
	tipoDeCuenta = static_cast<ACCOUNT_TYPE>(tmpTipoDeCuentaInt);

	try {
		int id = Accounts::getNextFreeId();
		Accounts cuenta = Accounts(id, nombre, valor, tipoDeCuenta);
		Accounts::saveAccount(cuenta);
	}
	catch (...) {
		cout << "[ERROR] La cuenta no se pudo crear correctamente." << endl;
	}
}

void Menu::deleteAccount(vector<Accounts> &c) {
	system("CLS");
	int idToDelete{ 0 };

	cout << "Select the account you want to delete: " << endl;
	for (Accounts&cuenta : c) {
		if (cuenta.getStatus() == STATUS::DELETED) continue;
		cout << cuenta.getId() << "\t" << cuenta.getName() << endl; //TODO: No hay una funcion que ya imprime esto? deberia ser una funcion en cuentas en vez de ponerlo aqui
	}
	cout << endl << "> ";
	cin >> idToDelete;

	for (Accounts cuenta : c) {
		if (cuenta.getId() == idToDelete) {
			cuenta.deleteAccount();
			break;
		}
	}
}

void Menu::restoreAccount(vector<Accounts> &c) {
	system("CLS");
	int idToRestore{ 0 };

	cout << "Select the account you want to restore: " << endl;
	for (Accounts&cuenta : c) {
		if (cuenta.getStatus() == STATUS::ACTIVE) continue;
		cout << cuenta.getId() << "\t" << cuenta.getName() << endl; //TODO: No hay una funcion que ya imprime esto? deberia ser una funcion en cuentas en vez de ponerlo aqui
	}
	cout << endl << "> ";
	cin >> idToRestore;

	for (Accounts&cuenta : c) {
		if (cuenta.getId() == idToRestore) {
			cuenta.restoreAccount();
			break;
		}
	}
}

void Menu::renameAccount(vector<Accounts>& c) {
	system("CLS");
	int idToRename{ 0 };

	cout << "Select the account you want to rename: " << endl;
	for (Accounts& cuenta : c)
		cout << cuenta.getId() << "\t" << cuenta.getName() << endl; //TODO: No hay una funcion que ya imprime esto? deberia ser una funcion en cuentas en vez de ponerlo aqui
	cout << endl << "> ";
	cin >> idToRename;

	string newAccountName{};
	cout << "Type the new account name: " << endl;
	cout << endl << "> ";

	std::cin.ignore();
	getline(std::cin, newAccountName);

	for (Accounts& cuenta : c) {
		if (cuenta.getId() == idToRename) {
			cuenta.renameAccount(newAccountName);
			break;
		}
	}
}


/*
		INCOME
*/

int Menu::printMenuIncome() {
	int option{ 0 };
	system("CLS");
	cout << "--- Income activities ---\n";
	cout << "(1) Visualize incomes" << endl;
	cout << "(2) Add income" << endl;

	cout << "(99) Salir" << endl;
	cout << "Option > ";
	cin >> option;

	return option;
}

void Menu::createIncome() {
	
	int id = Transactions::getNextFreeId();
	string shortDescription;
	int accountId{};
	double amount{};

	cout << "\nEnter a short description > ";
	std::cin.ignore();
	getline(std::cin, shortDescription);

	accountId = Accounts::printByAccountType(Accounts::readAccounts());

	cout << "\nEnter the amount > ";
	cin >> amount;
	
	Transactions ing = Transactions(id, shortDescription, accountId, amount, TRANSACTION_TYPE::INCOME);
	Transactions::saveIncomes(ing);
}