#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Account.h"
#include "Checking.h"

#include <stdexcept>

class CreditCard :public Account{

	CreditCard(float balanceReq, float rateInterestReq, float creditLimitReq = 5000) :Account(balanceReq) {}
	static float rateInterest;
	float creditLimit;

	bool transfer_from_checking(float amount, Checking creditCardAccount);
};

CreditCard::CreditCard(float balanceReq, float rateInterestReq, float creditLimitReq){
	//Raincheck interest rate before assigning
	if (rateInterestReq < 0 || rateInterestReq > 100){	
		throw std::invalid_argument("Interest rate not between 0 and 100.");
	}
	rateInterest = rateInterestReq;

	//Raincheck credit limit before assigning
	if (creditLimit < 0) {
		throw std::invalid_argument("Credit limit cannot be negative.");
	}
	creditLimit = creditLimitReq;
}

bool CreditCard::transfer_from_checking(float amount, Checking creditCardAccount){
	if (creditCardAccount.withdraw(amount)){
		deposit(amount);
	}
}

#endif