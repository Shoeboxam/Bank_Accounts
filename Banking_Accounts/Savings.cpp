//Savings.cpp - child source
#include "Savings.h"

float Savings::rateInterest = 0.06;

Savings::Savings(float mbalance, float mrateInterest) : Account(mbalance){
	//Raincheck interest rate before assigning
	if (mrateInterest < 0 || mrateInterest > 100){
		throw std::invalid_argument("Interest rate not between 0 and 100.");
	}
	rateInterest = mrateInterest;
}

bool Savings::set_interest_rate(float mrateInterest){
	//Raincheck interest rate before assigning
	if (mrateInterest < 0 || mrateInterest > 100){
		return false;
		//throw std::invalid_argument("Interest rate not between 0 and 100.");
	}
	rateInterest = mrateInterest;
	return true;
}

float Savings::compound(){
	//What a joke... $0.01
	float interest = balance * (rateInterest / 100 / 12);
	deposit(interest, "Monthly interest");
	return interest;
}