#include "Savings.h"
#include "Checking.h"

float Savings::rateInterest = 0.06;

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
	float interest = balance * (rateInterest / 100);
	deposit(interest, "Monthly interest");
	return interest;
}

bool Savings::transfer_from_checking(float amount, Checking &checkingAccount, string title){
	if (checkingAccount.withdraw(amount, title)){
		deposit(amount, title);
		return true;
	}
	return false;
}