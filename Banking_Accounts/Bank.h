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
	Bank(int numTestAccounts = 0);

	//Returns Account ID
	int open_savings(float initial_balance);
	int open_checking(float initial_balance);
	int open_credit(float initial_balance);

	bool close(int account_id);

	bool withdraw(int account_number, float amount, string title);
	bool deposit(int account_number, float amount, string title);

	bool transfer(int account_number_from, int account_number_to, float mAmount, string title);

	float get_balance(int account_number);
	string get_type(int account_number);
	string get_history(int account_number);
};

#endif