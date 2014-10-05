#include "Savings.h"
#include "Checking.h"

bool Savings::transfer_from_checking(float amount, Checking &checkingAccount){
	if (checkingAccount.withdraw(amount)){
		deposit(amount);
		return true;
	}
	return false;
}