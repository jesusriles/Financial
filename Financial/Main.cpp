#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"
#include "Menu.h"

using namespace std;

int main() {

	// Obtener la informacion guardada en los archivos (Cuentas, Ingresos y Gastos)
	vector<Cuentas> cuentas = Cuentas::leerCuentas();
	vector<Ingresos> ingresos = Ingresos::leerIngresos();

	// Menu options
	int option{ Menu::printMenu() };

	if (option == 1) { // Cuentas
		int optionCuenta{ Menu::printMenuAccounts() };

		if (optionCuenta == 1) { // visualizar cuenta
			Cuentas::imprimirCuentas(cuentas);
		}
		else if (optionCuenta == 2) { // agregar cuenta
			// pedir la informacion de la cuenta nueva que se va a crear
			string nombre{};
			float valor{ 0.00f };

			int tmpTipoDeCuentaInt{ 0 };
			TIPODECUENTA tipoDeCuenta{ TIPODECUENTA::OTHER };

			cout << "Nombre de cuenta> ";
			cin.ignore();
			getline(std::cin, nombre);

			cout << "Valor inicial de cuenta> ";
			cin >> setprecision(2) >> valor;
			
			cout << "Tipo de cuenta:\n(1) Debito\n(2) Credito\n> ";
			cin >> tmpTipoDeCuentaInt;
			tipoDeCuenta = static_cast<TIPODECUENTA>(tmpTipoDeCuentaInt);

			try {
				int id = Cuentas::getNextFreeId(cuentas);
				Cuentas cuenta = Cuentas(id, nombre, valor, tipoDeCuenta);
				Cuentas::guardarCuenta(cuenta);
			}
			catch (...) {
				cout << "[ERROR] La cuenta no se pudo crear correctamente." << endl;
			}
		}
	}
	return 0;
}