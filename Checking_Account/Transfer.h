#ifndef TRANSFER_H
#define TRANSFER_H

#include "Savings.h"
#include "CreditCard.h"
#include "Checking.h"

class Transfer {
public:
};

bool CreditCard::transfer_from_checking(float amount, Checking creditCardAccount){
	if (creditCardAccount.withdraw(amount)){
		deposit(amount);
	}
}

bool Checking::transfer_from_checking(float amount, Savings checkingAccount){
	if (checkingAccount.withdraw(amount)){
		deposit(amount);
	}
}

bool Savings::transfer_from_savings(float amount, Savings savingsAccount){
	if (savingsAccount.withdraw(amount)){
		deposit(amount);
	}
}

#endif