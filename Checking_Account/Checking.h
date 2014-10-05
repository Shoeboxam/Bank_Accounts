#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

#include <stdexcept>

class Checking : public Account {
	static float rateInterest;

public:
	Checking(float balanceReq, float rateInterestReq) : Account(balanceReq) {}

	bool deposit(float amount);
	bool withdraw(float amount);

	Checking& operator+(float input){
		deposit(input);
	}

	Checking& operator-(float input){
		withdraw(input);
	}

	bool transfer_from_savings(float amount, Savings savingsAccount);
};

Checking::Checking(float balanceReq, float rateInterestReq){
	//Raincheck interest rate before assigning
	if (rateInterestReq < 0 || rateInterestReq > 100){
		throw std::invalid_argument("Interest rate not between 0 and 100.");
	}
	rateInterest = rateInterestReq;
}

bool Checking::transfer_from_savings(float amount, Savings savingsAccount){
	if (savingsAccount.withdraw(amount)){
		deposit(amount);
	}
}

#endif