#include "Bank.h"
#include <vector>

#include "CreditCard.h"
#include "Savings.h"
#include "Checking.h"

using std::vector;

class Bank::Implementation{
public:

	vector<Account*> account_storage;

	bool deposit(int account_number, float mAmount, string mTitle = "");
	bool withdraw(int account_number, float mAmount, string mTitle = "");
	bool transfer(int account_number_from, int account_number_to, float mAmount, string title);

	int open_checking(float initial_balance);
	int open_savings(float initial_balance);
	int open_credit(float credit_limit);

	float get_balance(int account_number);
	string get_history(int account_number);

	bool close(int account_number);
};

bool Bank::Implementation::transfer(int account_number_from, int account_number_to, float mAmount, string title){
	if (account_storage[account_number_from - 1]->withdraw(mAmount, title) && account_storage[account_number_to - 1]->deposit(mAmount, title)){
		return true;
	}
	return false;
}

int Bank::Implementation::open_checking(float initial_balance) {
	account_storage.push_back(new Checking(initial_balance));
	return account_storage.back()->get_account_number();
}

int Bank::Implementation::open_savings(float initial_balance) {
	account_storage.push_back(new Savings(initial_balance)); 
	return account_storage.back()->get_account_number(); 
}

int Bank::Implementation::open_credit(float initial_balance) { 
	account_storage.push_back(new CreditCard(initial_balance)); 
	return account_storage.back()->get_account_number(); 
}

bool Bank::Implementation::deposit(int account_number, float mAmount, string mTitle) {
	 return account_storage[account_number - 1]->deposit(mAmount, mTitle); 
}

bool Bank::Implementation::withdraw(int account_number, float mAmount, string mTitle) {
	return account_storage[account_number - 1]->withdraw(mAmount, mTitle);
}

bool Bank::Implementation::close(int account_number) {
	if (account_number < account_storage.size() && account_number >= 0){
		account_storage[account_number - 1]->~Account();
		return true;
	}
	return false;
}

float Bank::Implementation::get_balance(int account_number){
	return account_storage[account_number - 1]->get_balance();
}

string Bank::Implementation::get_history(int account_number){
	return account_storage[account_number - 1]->get_history_string();
}


Bank::Bank(int numTestAccounts){
	concealed = new Bank::Implementation();

	for (int i = 0; i < numTestAccounts; i++){
		//New accounts default open to $500 for demonstration
		open_savings(500);
	}
}

//Pimpl boilerplate...

float Bank::get_balance(int account_number){
	return concealed->get_balance(account_number);
}

bool Bank::deposit(int account_number, float amount, string title = ""){
	return concealed->deposit(account_number, amount, title);
}

bool Bank::withdraw(int account_number, float amount, string title = ""){
	return concealed->withdraw(account_number, amount, title);
}

bool Bank::transfer(int account_number_from, int account_number_to, float mAmount, string title){
	return concealed->transfer(account_number_from, account_number_to, mAmount, title);
}

int Bank::open_checking(float initial_balance){
	return concealed->open_checking(initial_balance);
}

int Bank::open_savings(float initial_balance){
	return concealed->open_savings(initial_balance);
}

int Bank::open_credit(float credit_limit){
	return concealed->open_credit(credit_limit);
}

bool Bank::close(int account_number){
	return concealed->close(account_number);
}

string Bank::get_history(int account_number){
	return concealed->get_history(account_number);
}