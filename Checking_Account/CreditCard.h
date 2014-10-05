#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Account.h"

class Checking; //Forward declaration to soothe compiler
class Savings;

class CreditCard : public Account {
	static float rateFinance;
	float creditLimit;

	//bool deposit(float amount, string title = ""); //Mask inherited deposit

public:
	CreditCard(float mcreditLimit = 5000) : Account(mcreditLimit){
		//Raincheck credit limit before assigning
		if (mcreditLimit < 0) {
			throw std::invalid_argument("Credit limit cannot be negative.");
		}
		creditLimit = mcreditLimit;
	}

	static bool set_finance_rate(float mrateFinance);
	static float get_finance_rate() { return rateFinance; }
	float get_debt() const { return creditLimit - balance; }

	float compound();

	bool transfer_from_checking(float amount, Checking &checkingAccount, string title = "Checking credit payment");
	bool transfer_from_savings(float amount, Savings &savingsAccount, string title = "Savings credit payment");

};

#endif