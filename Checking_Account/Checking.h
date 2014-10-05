#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

#include <stdexcept>

class Savings; //Forward Declaration

class Checking : public Account {
	static float rateInterest;

public:
	Checking(float balanceReq, float rateInterestReq) : Account(balanceReq){
		//Raincheck interest rate before assigning
		if (rateInterestReq < 0 || rateInterestReq > 100){
			throw std::invalid_argument("Interest rate not between 0 and 100.");
		}
		rateInterest = rateInterestReq;
	}

	bool transfer_from_savings(float amount, Savings &savingsAccount);
};

#endif