#include "Menu.h"

int Menu::printMenu()
{
	cout << "--- Actividades generales ---\n";
	cout << "(1) Cuentas" << endl;
	cout << "(2) Ingresos" << endl;
	cout << "(3) Gastos" << endl;

	cout << "\n--- Reportes ---\n";
	cout << "(10) Reporte de gastos" << endl;
	cout << "(11) Reporte de ingresos" << endl;
	
	cout << "\n--- Actividades rapidas ---\n";
	cout << "(98) Registrar ingresos" << endl;
	cout << "(99) Registrar gastos" << endl;

	cout << "Option> ";

	int option{};
	cin >> option;

	return option;
}