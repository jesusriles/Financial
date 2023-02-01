#include "Menu.h"

int Menu::printMenu()
{
	cout << "--- General activities ---\n";
	cout << "(1) Accounts" << endl;
	cout << "(2) Income" << endl;
	cout << "(3) Expense" << endl;

	cout << "\n--- Reports ---\n";
	cout << "(10) Expense report" << endl;
	cout << "(11) Income report" << endl;
	
	cout << "\n--- Quick activities ---\n";
	cout << "(98) Register an income" << endl;
	cout << "(99) Register an expense" << endl;

	cout << "Option> ";

	int option{};
	cin >> option;

	return option;
}