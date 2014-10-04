#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
	float balance;
		
public:
	Account(float balanceReq = 0);

	float get_balance() const { return balance; }
	 
	bool deposit(float amount);
	bool withdraw(float amount);

	Account& operator+(float input){
		deposit(input);
	}

	Account& operator-(float input){
		withdraw(input);
	}

};

Account::Account(float balanceReq){
	//Raincheck balance before assigning
	if (balanceReq < 0){
		throw std::invalid_argument("Balance cannot be negative");
	}
	balance = balanceReq;
	
}

bool Account::deposit(float amount){
	//Must be positive
	if (amount > 0){
		balance += amount;
		return true;
	}
	return false;
}

bool Account::withdraw(float amount){
	//Must be positive, and must have enough in account
	if (amount > 0 && balance - amount >= 0){
		balance -= amount;
		return true;
	}
	return false;
}

#endif