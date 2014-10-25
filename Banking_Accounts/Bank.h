#ifndef BANK_H
#define BANK_H

#include <string>
using std::string;

#include "CreditCard.h"
#include "Savings.h"
#include "Checking.h"

class Bank {
	//Did some reading online... pimpl. 
	class Implementation;
	Implementation *concealed;

public:
	Bank() { concealed = new Implementation; }
	~Bank();

	bool withdraw(int account_number, float amount, string title);
	bool deposit(int account_number, float amount, string title);
};

#endif