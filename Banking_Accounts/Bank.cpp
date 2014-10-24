#include "Bank.h"
#include "Clump.h"

struct Bank::Implementation{
	Clump<Account> acctList;

	Account* get(int account_number) { return acctList[account_number]; }
	void open_account(const Account &input) { acctList.append(input); }
	bool close_account(int account_number) { acctList.remove(account_number); }
};


bool Bank::deposit(int account_number, float amount, string title = ""){
	return concealed->get(account_number).deposit(amount, title);
}

bool Bank::withdraw(int account_number, float amount, string title = ""){
	return concealed->get(account_number).withdraw(amount, title);
}