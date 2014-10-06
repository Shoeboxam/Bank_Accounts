//CreditCard.h - child header
#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Account.h"

class CreditCard : public Account {
	
	static float rateFinance;
	float creditLimit;

	//Mask deposit via overriding inheritance with private... disabled
	//bool deposit(float amount, string title = "");

public:
	//Default constructor, passes 5000 to parent constructor unless argument given
	CreditCard(float mcreditLimit = 5000) : Account(mcreditLimit){
		//Raincheck credit limit before assigning
		//Except instead of return failures in constructors/destructors... stdexcept already imported in parent
		if (mcreditLimit < 0) {
			throw std::invalid_argument("Credit limit cannot be negative.");
		}
		creditLimit = mcreditLimit;
	}

	/* Setters and Getters */
	static bool set_finance_rate(float mrateFinance);
	static float get_finance_rate() { return rateFinance; }
	float get_debt() const { return creditLimit - balance; }

	//Applies monthly financing costs
	float compound();

	//Overwrite transfer_from to add credit limit check
	template <typename genAccount> 
	bool transfer_from(genAccount &genericAccount, float amount, string title = "Credit Transfer"){

		//Clamp payment to prevent overpaying
		amount = amount > get_debt() ? get_debt() : amount;

		return genericAccount.withdraw(amount, title) ? (deposit(amount, title), true) : false;
	}

	void operator+(float input){
		deposit(input);
	}

	void operator-(float input){
		withdraw(input);
	}

};

#endif