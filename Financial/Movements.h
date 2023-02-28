#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Movements
{
protected:
	int mId{ 0 };
	string mShortDescription{};
	int mAccountId{ 0 };
	float mAmount{ 0 };
	vector<string> tags{};
	string mComments{};
//	string mDate{};

	int getId() const { return mId; };
	string getShortDescription() const { return mShortDescription; };
	int getAccountId() const { return mAccountId; };
	double getAmount() const { return mAmount; };
	vector<string> getTags() const{ return tags; };
	string getComments() const { return mComments; };
};