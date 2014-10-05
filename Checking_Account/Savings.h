#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

#include <stdexcept>

class Savings : public Account {
public:
	Savings(float balanceReq) : Account(balanceReq) {}

	bool transfer_from_checking(float amount, Checking checkingAccount);
};

bool Savings::transfer_from_checking(float amount, Checking checkingAccount){
	if (checkingAccount.withdraw(amount)){
		deposit(amount);
	}
}

#endif