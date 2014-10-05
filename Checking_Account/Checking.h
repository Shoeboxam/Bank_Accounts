#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Savings; //Forward Declaration

class Checking : public Account {

public:
	Checking(float mbalance = 0) : Account(mbalance){}

	bool transfer_from_savings(float amount, Savings &savingsAccount);

	void operator+(float input){
		deposit(input);
	}

	void operator-(float input){
		withdraw(input);
	}
};

#endif