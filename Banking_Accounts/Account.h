//Account.h - parent header
//Michael Shoemate

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

using std::string;

using std::vector;
using std::pair;


class Account{
	//Used to keep track of account number
	static int instances;
	int accountNumber;

	string _account_owner;

protected:
	//Should be directly modifiable in child classes
	float balance;
	//pair is transaction, float is money, string is descriptor
	vector<pair<float, string>> history;
	

public:
	//Default values allow it to be read as default constructor while still taking optional parameters
	Account(float mbalance = 0, string title = "Initial Balance");
	Account(const Account &input);
	~Account();

	/* Setters and Getters */
	float get_balance() const { return balance; }
	vector<pair<float, string>> get_history() const { return history; }
	string get_history_string();
	string get_last_transaction_string();
	int get_account_number() const { return accountNumber; }

	string get_owner() { return _account_owner; }
	void set_owner(string mOwner) { _account_owner = mOwner; }

	virtual string get_type() { return "Generic"; }
	
	//Optional title can be passed for each deposit/withdrawal
	bool deposit(float amount, string title = "");
	bool withdraw(float amount, string title = "");

	//Handle all four types of accounts in one transfer function
	template <typename genAccount> 
	bool transfer_from(genAccount &genericAccount, float amount, string title = "Transfer"){
		return genericAccount.withdraw(amount, title) ? (deposit(amount, title), true) : false;
	}

	bool operator+(float input){
		return deposit(input);
	}

	bool operator-(float input){
		return withdraw(input);
	}

};

#endif