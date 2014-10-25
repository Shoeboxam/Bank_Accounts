#include "Bank.h"
#include <vector>
using std::vector;

class Bank::Implementation{
public:
	Implementation();
	~Implementation();
	vector<Account> acctList;

	Account get(int account_number) { return acctList[account_number]; }
	void open_account(const Account &input) { acctList.push_back(input); }
	//void close_account(int account_number) { acctList.erase(account_number); }
};


bool Bank::deposit(int account_number, float amount, string title = ""){
	return concealed->get(account_number).withdraw(amount, title);
}

bool Bank::withdraw(int account_number, float amount, string title = ""){
	return concealed->get(account_number).withdraw(amount, title);
}