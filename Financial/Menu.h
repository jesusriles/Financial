#pragma once
#include <iostream>
#include "Accounts.h"
#include "Transactions.h"

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
	static void deleteAccount(vector<Accounts> &c);
	static void restoreAccount(vector<Accounts>& c);
	static void renameAccount(vector<Accounts>& c);

	// Income
	static int printMenuIncome();
	static void createIncome();
};