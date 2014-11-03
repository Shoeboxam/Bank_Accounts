//Application.cpp - test driver
//Banking accounts

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Bank.h"

using std::cout;
using std::endl;

const int timespanMonths = 8; //Configurable

float generateValue(int min, int max){
	// mul/div by 100 to generate pennies
	min *= 100;
	max *= 100;
	return float(( min + rand() % (max - min + 1))) / 100;
}

int main(){
	//Seed random number generator
	srand(static_cast<int>(time(NULL)));
	//Format output
	cout << std::fixed << std::setprecision(2) << std::showpoint;

	cout << "\tBank Account Simulator" << endl
		 << "\t----------------------" << endl;

	//Initialize accounts

	Bank WellsFargo;

	int id_savings = WellsFargo.open_savings(500);
	int id_checking = WellsFargo.open_checking(500);
	int id_credit = WellsFargo.open_credit(5000);

	cout << endl << "Opening Balances" << endl;
	cout << id_savings  << " Savings\t" << std::setw(7) << WellsFargo.get_balance(id_savings) << "$" << endl;
	cout << id_checking << " Checking\t" << std::setw(7) << WellsFargo.get_balance(id_checking) << "$" << endl;
	cout << id_credit << " Credit Limit\t" << std::setw(7) << WellsFargo.get_balance(id_credit) << "$" << endl << endl;

	cout << endl << "Press any button to simulate " << timespanMonths << " months." << endl << endl;
	system("pause > nul");



	cout << "... Simulating ..." << endl << endl;

	float accumulatedBounces = 0;
	int elapsedMonths = 0;
	while (elapsedMonths < timespanMonths){
		cout << "\tMonth " << elapsedMonths+1 << endl;
		float payment;

		elapsedMonths++;

		//Deposit pay
		WellsFargo.deposit(id_checking, generateValue(1000, 2000), "Paycheck");

		//Deposit Savings
		WellsFargo.deposit(id_savings, generateValue(100, 200), "Savings");

		//Loan Payment
		payment = generateValue(700, 800);
		if (!WellsFargo.withdraw(id_checking, payment, "Loan Payment")){
			cout << "Checking short $" << payment - WellsFargo.get_balance(id_checking) << " for loan." << endl;
			accumulatedBounces += payment;
		}
		
		//Pay five bills
		for (int bill = 1; bill <= 5; bill++){
			payment = generateValue(30, 80);
			if (!WellsFargo.withdraw(id_checking, payment, "Bill #" + std::to_string(bill))){
				cout << "Checking short $" << payment - WellsFargo.get_balance(id_checking) << " for bill #" << bill << "." << endl;
				accumulatedBounces += payment;
			}
		}
		
		//Charge ten times Credit Card
		for (int charge = 1; charge <= 10; charge++){
			payment = generateValue(20, 90);
			if (!WellsFargo.withdraw(id_credit, payment, "Charge #" + std::to_string(charge))){
				cout << "Credit card short $" << payment - WellsFargo.get_balance(id_checking) << " for charge #" << charge << "." << endl;
				accumulatedBounces += payment;
			}
		}

		//Pay Credit Card
		payment = generateValue(200, 300);
		if (!WellsFargo.transfer(id_checking, id_credit, payment, "Credit Card Payment")){
			cout << "Checking short $" << payment - WellsFargo.get_balance(id_checking) << " for credit card payment." << endl;
		}

		//credit_account.compound();
		//save_account.compound();

		cout << endl << "\tBalances" << endl;
		cout << "Savings:  $" << WellsFargo.get_balance(id_savings) << endl;
		cout << "Checking: $" << WellsFargo.get_balance(id_checking) << endl;
		cout << "Credit:   $" << WellsFargo.get_balance(id_credit) << endl
			<<	"-----------------" << endl << endl;
	}

	cout << endl << "Press any button to print history." << endl << endl;
	system("pause > nul");


	cout << "Wells Fargo savings history" << endl
		 << "---------------------------" << endl
		 << WellsFargo.get_history(id_savings)
		 << "\t________" << endl << "\t" << std::setw(7) << WellsFargo.get_balance(id_savings) << " | Balance ($)" << endl << endl;

	cout << "Checking history" << endl
		 << "----------------------" << endl
		 << WellsFargo.get_history(id_checking)
		 << "\t________" << endl << "\t" << std::setw(7) << WellsFargo.get_balance(id_checking) << " | Balance ($)" << endl << endl;

	cout << "Credit card history" << endl
		 << "------------------------" << endl
		 << WellsFargo.get_history(id_credit)
		 << "\t________" << endl << "\t" << std::setw(7) << WellsFargo.get_balance(id_credit) << " | Balance ($)" << endl << endl;

	cout << "\tAccumulated bounces: $" << accumulatedBounces << endl;

	//Simply demonstrates closing an account
	WellsFargo.close(2);

	system("pause > nul");
	cout << endl << "Press any button to exit." << endl << endl;

	return 0;
}