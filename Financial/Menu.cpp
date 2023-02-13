#include "Menu.h"

/* prints the main menu */
int Menu::printMenu() {

	int option{ 0 };
	while (option != 99) {
		system("CLS");
		cout << "--- General activities ---\n";
		cout << "(1) Accounts" << endl;
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

		vector<Cuentas> cuentas = Cuentas::leerCuentas();
		if (optionCuenta == 1) {
		
			Cuentas::imprimirCuentas(cuentas);
		}

		else if (optionCuenta == 2) {
			Menu::createAccount();
		}
	}
}

int Menu::printMenuAccounts() {
	
	int option{ 0 };
	system("CLS");
	cout << "--- Actividades de cuenta ---\n";
	cout << "(1) Visualizar cuentas" << endl;
	cout << "(2) Agregar cuenta" << endl;
	cout << "#(3) Eliminar cuenta" << endl;
	cout << "#(4) Eliminar cuenta" << endl;

	cout << "(99) Salir" << endl;
	cout << "Option > ";
	cin >> option;
	
	return option;
}

void Menu::createAccount() {
	string nombre{};
	float valor{ 0.00f };

	int tmpTipoDeCuentaInt{ 0 };
	TIPODECUENTA tipoDeCuenta{ TIPODECUENTA::OTHER };

	cout << "Nombre de cuenta> ";
	std::cin.ignore();
	getline(std::cin, nombre);

	cout << "Valor inicial de cuenta> ";
	std::cin >> setprecision(2) >> valor;

	cout << "Tipo de cuenta:\n(1) Debito\n(2) Credito\n> ";
	std::cin >> tmpTipoDeCuentaInt;
	tipoDeCuenta = static_cast<TIPODECUENTA>(tmpTipoDeCuentaInt);

	try {
		int id = Cuentas::getNextFreeId();
		Cuentas cuenta = Cuentas(id, nombre, valor, tipoDeCuenta);
		Cuentas::guardarCuenta(cuenta);
	}
	catch (...) {
		cout << "[ERROR] La cuenta no se pudo crear correctamente." << endl;
	}
}