//Checking.h - child header
#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

//Every single feature of checking was generalized out to account.
//Kept class for sake of extensibility and readablity

//Inherit from Account; only checking specific methods in Checking
class Checking : public Account {

public:
	//Default constructor passes optional balance to parent constructor
	Checking(float mbalance = 0) : Account(mbalance){}

	void operator+(float input){
		deposit(input);
	}

	void operator-(float input){
		withdraw(input);
	}
};

#endif