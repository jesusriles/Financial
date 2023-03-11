#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <vector>

#include "Accounts.h"

using namespace std;

class Transactions
{
	int mId{ 0 };
	string mShortDescription{};
	int mAccountId{ 0 };
	float mAmount{ 0 };
	vector<string> tags{};
	string mComments{};

public:
	// constructor
	Transactions(int tmpId, string shortDescription, int tmpAccountId, float tmpAmount);

	// getters
	int getId() const { return mId; };
	string getShortDescription() const { return mShortDescription; };
	int getAccountId() const { return mAccountId; };
	double getAmount() const { return mAmount; };
	vector<string> getTags() const { return tags; };
	string getComments() const { return mComments; };

	// funciones
	static void printTransactions(const vector<Transactions>& i);
	static double getTotalIncomesOfAccount(vector<Transactions>& i, int cuentaId);

	static vector<Transactions> readIncomes();
	static bool saveIncomes(Transactions& i);
};