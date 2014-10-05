#include <iostream>
#include <iomanip>
#include <sstream>

#include "Account.h"

using std::cout;
using std::endl;

using std::ostream;

int Account::instances = 0;

Account::Account(float mbalance, string title){
	accountNumber = ++instances;

	//Raincheck balance before assigning
	if (mbalance < 0){
		throw std::invalid_argument("Balance cannot be negative");
	}
	balance = mbalance;

	history.push_back(pair<float, string>(mbalance, title));

	cout << "Opened Account #" << get_account_number() << endl;
}

Account::~Account(){
	cout << "Closed Account #" << get_account_number() << endl;
}

string Account::get_history_string(){
	std::stringstream buffer;

	buffer << std::fixed << std::setprecision(2) << std::showpoint;

	//Append each pair to the history string on a new line
	for (int i = 0; i < history.size(); i++){

		//At index i, get <0>/first element of pair, then round, then convert to string and append to buffer
		float transactValue = std::get<0>(history[i]);

		buffer << "\t" << std::setw(7) << transactValue << " | ";

		//At index i, get <1>/second element of pair
		buffer << std::get<1>(history[i]) << endl;
	}

	return buffer.str();
}


string Account::get_last_transaction_string(){
	std::stringstream buffer;
	buffer << std::fixed << std::setprecision(2) << std::showpoint;

	//At index i, get <0>/first element of pair, then round, then convert to string and append to buffer
	float transactValue = std::get<0>(history.back());
	buffer << std::setw(7) << transactValue << " | " << std::get<1>(history.back());

	return buffer.str();
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
	if (amount > 0 && balance >= amount){
		balance -= amount;

		history.push_back(pair<float, string>(-amount, title));
		return true;
	}
	return false;
}