#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdexcept>
#include <string>
#include <list>
#include <utility>

using std::string;

using std::list;
using std::pair;


class Account {
	static int account_total;
	int account_number;
	float balance;

	list<pair<float, string>> history;
	

public:
	Account(float balanceReq = 0, string title = "Initial Balance");

	float get_balance() const { return balance; }
	
	bool deposit(float amount, string title = "");
	bool withdraw(float amount, string title = "");

	Account& operator+(float input){
		deposit(input);
	}

	Account& operator-(float input){
		withdraw(input);
	}

};

Account::Account(float balanceReq, string title){

	account_total = 1;
	account_number = account_total++;

	//Raincheck balance before assigning
	if (balanceReq < 0){
		throw std::invalid_argument("Balance cannot be negative");
	}
	balance = balanceReq;
	
	history.push_back(pair<float, string>(balanceReq, title));
}

bool Account::deposit(float amount, string title){
	//Must be positive
	if (amount > 0){
		balance += amount;

		//Record transaction in history
		history.push_back(pair<float, string>(+amount, title));
		return true;
	}
	return false;
}

bool Account::withdraw(float amount, string title){
	//Must be positive, and must have enough in account
	if (amount > 0 && balance - amount >= 0){
		balance -= amount;

		history.push_back(pair<float, string>(-amount, title));
		return true;
	}
	return false;
}

#endif