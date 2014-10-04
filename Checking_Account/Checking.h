#ifndef CHECKING_H
#define CHECKING_H

#include <stdexcept>

class Checking{
	float balance;
	static float rateInterest;

public:
	Checking(float balanceReq, float rateInterestReq);

	float get_balance() const { return balance; }

	bool deposit(float amount);
	bool withdraw(float amount);

	Checking& operator+(float input){
		deposit(input);
	}

	Checking& operator-(float input){
		withdraw(input);
	}
};

Checking::Checking(float balanceReq, float rateInterestReq){
	//Raincheck balance before assigning
	if (balanceReq < 0){
		throw std::invalid_argument("Balance cannot be negative");
	}
	balance = balanceReq;

	//Raincheck interest rate before assigning
	if (rateInterestReq < 0 || rateInterestReq > 100){
		throw std::invalid_argument("Interest rate not between 0 and 100.");
	}
	rateInterest = rateInterestReq;
}

bool Checking::deposit(float amount){
	//Must be positive
	if (amount > 0){
		balance += amount;
		return true;
	}
	return false;
}

bool Checking::withdraw(float amount){
	//Must be positive, and must have enough in account
	if (amount > 0 && balance - amount >= 0){
		balance -= amount;
		return true;
	}
	return false;
}

#endif