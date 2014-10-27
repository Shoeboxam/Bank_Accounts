#include "Bank.h"
#include <vector>
using std::vector;

class Bank::Implementation{
public:
	Implementation(){}
	~Implementation(){}

	vector<Account> acctList;

	Account* get(int account_number) { return &acctList[account_number]; }
	void open_account(const Account &input) { acctList.push_back(input); return; }
	//void close_account(int account_number) { acctList.erase(account_number); }
};


Bank::Bank(){
	concealed = new Bank::Implementation();
}


bool Bank::deposit(int account_number, float amount, string title = ""){
	return concealed->get(account_number)->deposit(amount, title);
}

bool Bank::withdraw(int account_number, float amount, string title = ""){
	return concealed->get(account_number)->deposit(amount, title);
}