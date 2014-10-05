#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Checking; //Forward declaration

class Savings : public Account {
public:
	Savings(float balanceReq) : Account(balanceReq){}

	bool transfer_from_checking(float amount, Checking &checkingAccount);
};

#endif