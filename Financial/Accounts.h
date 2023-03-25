#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream> 
#include <limits>

using std::string;
using namespace std;

// global variables
const string FILE_ACCOUNTS{ "Cuentas.txt" };
const string FILE_TRANSACTIONS{ "Ingresos.txt" };

const int MAX_AVAILABLE_IDS{ 99 };

enum class ACCOUNT_TYPE {
	DEBITO = 1,
	CREDITO = 2,
	OTHER = 99
};

enum class CURRENCY {
	MXN = 1,
	USD = 2,
	EUR = 3,
	OTHER = 99
};

enum class STATUS {
	ACTIVE = 1,		
	HIDDEN = 2,		// account is active but not visible
	DELETED = 3,	// account was marked as deleted (should be able to recover this account)
	ARCHIVED = 4,	// account archived (all related to this account should be moved to another file)
	OTHER = 99		// should not be used
};

class Accounts 
{
private:
	int mId{ 0 };
	string mName{ "null" };
	float mInitialValue{ 0.0f };
	ACCOUNT_TYPE mAccountType{ ACCOUNT_TYPE::DEBITO };
	CURRENCY mCurrency{ CURRENCY::MXN };
	STATUS mStatus{ STATUS::ACTIVE };

	string mDateCreated{ "null" };
	string mComments{ "null" };

	static void replaceWordInFileWithId(const string& wordToReplace, const string& newWord, 
		fstream& file, const string fileName, const int &id);
	static string getIdFromLine(const string& line);

public:
	// constructor
	Accounts() = delete;
	Accounts(int id, string nombre, float valorInicial, ACCOUNT_TYPE tipoDeCuenta, CURRENCY tipoDeMoneda, string comentarios);
	Accounts(int id, string nombre, float valorInicial, ACCOUNT_TYPE tipoDeCuenta);

	// getters
	int getId() const { return mId; };
	string getName() const { return mName; };
	string getComments() const { return mComments; };
	string getDateCreated() const { return mDateCreated; };
	float getInitialValue() const { return mInitialValue; };
	ACCOUNT_TYPE getAccountType() const { return mAccountType; };
	CURRENCY getCurrency() const { return mCurrency; };
	STATUS getStatus() const { return mStatus; };

	// setters
	void setId(int tmpId) { mId = tmpId; }
	void setName(string tmpNombre) { mName = tmpNombre; };
	void setComments(string tmpComentario) { mComments = tmpComentario; };
	void setCreationDate(string tmpFechaCreacion) { mDateCreated = tmpFechaCreacion; };
	void setInitialValue(float tmpValorInicial) { mInitialValue = tmpValorInicial; };
	void setAccountType(ACCOUNT_TYPE tmpTipoDeCuenta) { mAccountType = tmpTipoDeCuenta; };
	void setCurrency(CURRENCY tmpTipoDeMoneda) { mCurrency = tmpTipoDeMoneda; };
	void setStatus(STATUS tmpStatus) { mStatus = tmpStatus; };

	// functions
	static void printAccounts(const vector<Accounts> &c);
	static bool saveAccount(Accounts &c);
	static vector<Accounts> readAccounts();
	static int getNextFreeId(); // get the next free Id to be assigned

	string accountTypeToString() const;
	static ACCOUNT_TYPE stringToAccountType(const string &s);

	string currencyToString() const;
	static CURRENCY stringToCurrency(const string &s);

	string statusToString() const;
	static STATUS stringToStatus(const string& s);

	void deleteAccount();
	void restoreAccount();
	void renameAccount(const string newAccountName);

	static int printByAccountType(const vector<Accounts>& c);
};