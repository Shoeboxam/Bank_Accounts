#ifndef BANK_H
#define BANK_H

#include <string>
using std::string;

#include "CreditCard.h"
#include "Savings.h"
#include "Checking.h"

class Bank {
	//Did some reading online... pimpl. 
	//Allocation is calculated from the header file, so methods cannot be concealed. 
	//Instead, use a pointer to more methods!
	struct Implementation;
	Implementation *concealed;
public:
	Bank();
	~Bank();

	bool withdraw(int account_number, float amount, string title);
	bool deposit(int account_number, float amount, string title);
};

#endif