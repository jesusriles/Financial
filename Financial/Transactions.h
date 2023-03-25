#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <vector>

#include "Accounts.h"

using namespace std;

enum class TRANSACTION_TYPE {
	INCOME = 1,
	EXPENSE = 2,
	TRANSFER = 3,
	OTHER = 99
};

class Transactions
{
	int mId{ 0 };
	string mShortDescription{};
	int mAccountId{ 0 };
	float mAmount{ 0 };
	vector<string> tags{};
	string mComments{};
	TRANSACTION_TYPE mTransactionType{ TRANSACTION_TYPE::OTHER };

public:
	// constructor
	Transactions(int tmpId, string shortDescription, int tmpAccountId, float tmpAmount, 
					TRANSACTION_TYPE tmpTransactionType);

	// getters
	int getId() const { return mId; };
	string getShortDescription() const { return mShortDescription; };
	int getAccountId() const { return mAccountId; };
	double getAmount() const { return mAmount; };
	vector<string> getTags() const { return tags; };
	string getComments() const { return mComments; };
	TRANSACTION_TYPE getTransactionType() const { return mTransactionType; };

	// funciones
	static void printTransactions(const vector<Transactions>& i);
	static double getTotalIncomesOfAccount(vector<Transactions>& i, int cuentaId);

	static vector<Transactions> readIncomes();
	static bool saveIncomes(Transactions& i);

	string transactionTypeToString() const;
	static TRANSACTION_TYPE stringToTransactionType(const string& s);

	static int getNextFreeId();
};