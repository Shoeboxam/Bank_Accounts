#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"
#include "Savings.h"

#include <stdexcept>

class Checking :public Account{

	Checking(float balanceReq, float rateInterestReq) :Account(balanceReq) {}
	static float rateInterest;

	bool transfer_from_checking(float amount, Savings checkingAccount);
};

Checking::Checking(float balanceReq, float rateInterestReq){
	//Raincheck interest rate before assigning
	if (rateInterestReq < 0 || rateInterestReq > 100){
		throw std::invalid_argument("Interest rate not between 0 and 100.");
	}
	rateInterest = rateInterestReq;
}

bool Checking::transfer_from_checking(float amount, Savings checkingAccount){
	if (checkingAccount.withdraw(amount)){
		deposit(amount);
	}
}

#endif