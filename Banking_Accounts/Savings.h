//Savings.h - child header
#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
	static float rateInterest;

public:
	Savings(float mbalance = 0, float mrateInterest = rateInterest);

	virtual string get_type() { return "Savings"; }

	float compound();

	static bool set_interest_rate(float mrateInterest);
	static float get_interest_rate() { return rateInterest; }

	void operator+(float input){
		deposit(input);
	}

	void operator-(float input){
		withdraw(input);
	}
};

#endif