#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Account.h"

class Checking;

class CreditCard : public Account {
	static float rateFinance;
	float creditLimit;

public:
	CreditCard(float creditLimitReq = 5000) : Account(creditLimitReq){
		//Raincheck credit limit before assigning
		if (creditLimit < 0) {
			throw std::invalid_argument("Credit limit cannot be negative.");
		}
		creditLimit = creditLimitReq;
	}

	static bool set_finance_rate(float rateFinanceReq);

	void operator+(float input){
		deposit(input);
	}

	void operator-(float input){
		withdraw(input);
	}

	bool transfer_from_checking(float amount, Checking &creditCardAccount);
};

#endif