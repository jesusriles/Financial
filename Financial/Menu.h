#pragma once
#include <iostream>
#include "Cuentas.h"

using namespace std;

class Menu
{
public:

	// Menu options
	static int printMenu(); // print the available options in menu
	static int printMenuAccounts(); // print the available options in menu

	static void optionsMenu(int &option);
};

