#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

using std::string;

using std::vector;
using std::pair;


class Account {
	static int instances;

protected:
	int accountNumber;
	float balance;

	vector<pair<float, string>> history;
	

public:
	Account(float mbalance = 0, string title = "Initial Balance");
	~Account();

	float get_balance() const { return balance; }
	vector<pair<float, string>> get_history() const { return history; }
	string get_history_string();
	string get_last_transaction_string();
	int get_account_number() const { return accountNumber; }
	
	bool deposit(float amount, string title = "");
	bool withdraw(float amount, string title = "");

};

#endif