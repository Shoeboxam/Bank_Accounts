#include "Checking.h"
#include "Savings.h"

bool Checking::transfer_from_savings(float amount, Savings &savingsAccount){
	if (savingsAccount.withdraw(amount)){
		deposit(amount);
		return true;
	}
	return false;
}