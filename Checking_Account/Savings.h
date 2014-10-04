#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
public:
	Savings(float balanceReq) :Account(balanceReq) {}

	bool transfer_from_savings(float amount, Savings savingsAccount);
};

bool Savings::transfer_from_savings(float amount, Savings savingsAccount){
	if (savingsAccount.withdraw(amount)){
		deposit(amount);
	}
}

#endif