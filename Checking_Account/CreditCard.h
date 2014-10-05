#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Account.h"
#include "Checking.h"

#include <stdexcept>

class CreditCard : public Account {
	static float rateFinance;
	float creditLimit;

public:
	CreditCard(float creditLimitReq = 5000) : Account(creditLimitReq){}

	static bool set_finance_rate(float rateFinanceReq);

	CreditCard& operator+(float input){
		deposit(input);
	}

	CreditCard& operator-(float input){
		withdraw(input);
	}

	bool transfer_from_checking(float amount, Checking creditCardAccount);
};



CreditCard::CreditCard(float creditLimitReq){
	//Raincheck credit limit before assigning
	if (creditLimit < 0) {
		throw std::invalid_argument("Credit limit cannot be negative.");
	}
	creditLimit = creditLimitReq;
}

bool CreditCard::set_finance_rate(float rateFinanceReq){
	//Raincheck finance rate before assigning
	if (rateFinanceReq < 0 || rateFinanceReq > 100){
		return false;
		//throw std::invalid_argument("Finance rate not between 0 and 100.");
	}
	rateFinance = rateFinanceReq;
	return true;
}

bool CreditCard::transfer_from_checking(float amount, Checking creditCardAccount){
	if (creditCardAccount.withdraw(amount)){
		deposit(amount);
	}
}

#endif