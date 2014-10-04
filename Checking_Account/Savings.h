#ifndef SAVINGS_H
#define SAVINGS_H

#include <stdexcept>

class Savings{

	float balance;

public:
	Savings(float balanceReq = 0);

	float get_balance() const { return balance; }

	bool deposit(float amount);
	bool withdraw(float amount);

	Savings& operator+(float input){
		deposit(input);
	}

	Savings& operator-(float input){
		withdraw(input);
	}
};

Savings::Savings(float balanceReq){
	//Raincheck balance before assigning
	if (balanceReq < 0){
		throw std::invalid_argument("Balance cannot be negative");
	}
	balance = balanceReq;

}

bool Savings::deposit(float amount){
	//Must be positive
	if (amount > 0){
		balance += amount;
		return true;
	}
	return false;
}

bool Savings::withdraw(float amount){
	//Must be positive, and must have enough in account
	if (amount > 0 && balance - amount >= 0){
		balance -= amount;
		return true;
	}
	return false;
}

#endif