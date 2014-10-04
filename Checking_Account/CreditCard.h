#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <stdexcept>

class CreditCard{

	float balance;
	static float rateInterest;
	float creditLimit;

public:
	CreditCard(float balanceReq, float rateInterestReq, float creditLimitReq = 5000);

	float get_balance() const { return balance; }

	bool deposit(float amount);
	bool charge(float amount);

	CreditCard& operator+(float input){
		deposit(input);
	}

	CreditCard& operator-(float input){
		charge(input);
	}
};

CreditCard::CreditCard(float balanceReq, float rateInterestReq, float creditLimitReq){
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

	//Raincheck credit limit before assigning
	if (creditLimit < 0) {
		throw std::invalid_argument("Credit limit cannot be negative.");
	}
	creditLimit = creditLimitReq;
}

bool CreditCard::deposit(float amount){
	//Must be positive
	if (amount > 0){
		balance += amount;
		return true;
	}
	return false;
}

bool CreditCard::charge(float amount){
	//Must be positive, and must have enough in account
	if (amount > 0 && balance - amount >= 0){
		balance -= amount;
		return true;
	}
	return false;
}

#endif