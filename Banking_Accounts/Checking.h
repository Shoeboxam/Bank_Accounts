//Checking.h - child header
#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"


class Checking : public Account {

public:
	//Default constructor passes optional balance to parent constructor
	Checking(float mbalance = 0) : Account(mbalance){}

	virtual string get_type() { return "Checking"; }

	void operator+(float input){
		deposit(input);
	}

	void operator-(float input){
		withdraw(input);
	}
};

#endif