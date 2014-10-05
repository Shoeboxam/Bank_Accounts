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
	list<pair<float, string>> get_history() const { return history; }
	
	bool deposit(float amount, string title = "");
	bool withdraw(float amount, string title = "");

};

#endif