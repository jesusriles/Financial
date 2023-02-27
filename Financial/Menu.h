#pragma once
#include <iostream>
#include "Cuentas.h"
#include "Ingresos.h"

using namespace std;

class Menu
{
public:

	// Menu options
	static int printMenu(); // print the available options in menu
	static void optionsMenu(const int &option);

	// Accounts
	static int printMenuAccounts();
	static void createAccount();
	static void deleteAccount(vector<Cuentas> &c);
	static void restoreAccount(vector<Cuentas>& c);
	static void renameAccount(vector<Cuentas>& c);

	// Income
	static int printMenuIncome();
	static void createIncome();
};