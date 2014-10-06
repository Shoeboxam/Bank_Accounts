
//Banking accounts

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Savings.h"
#include "Checking.h"
#include "CreditCard.h"

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
	cout << "\t" << Savings::get_interest_rate() << "% Interest rate | " << CreditCard::get_finance_rate() << "% Finance rate" << endl << endl;

	//Initialize accounts
	Savings WellsFargo(500);
	Checking Chase(500);
	CreditCard Visa(5000);

	cout << endl << "Opening Balances" << endl;
	cout << WellsFargo.get_account_number() << " Wells Fargo Savings\t" << std::setw(7) << WellsFargo.get_balance() << "$" << endl;
	cout << Chase.get_account_number() << " Chase Checking\t" << std::setw(7) << Chase.get_balance() << "$" << endl;
	cout << Visa.get_account_number() << " Visa Credit Limit\t" << std::setw(7) << Visa.get_balance() << "$" << endl << endl;

	cout << endl << "Press any button to simulate " << timespanMonths << " months." << endl << endl;
	system("pause > nul");



	cout << "... Simulating ..." << endl << endl;

	float accumulatedBounces = 0;
	int elapsedMonths = 0;
	while (elapsedMonths < timespanMonths){
		float payment;

		elapsedMonths++;

		//Deposit pay
		Chase.deposit(generateValue(1000, 2000), "Paycheck");

		//Deposit Savings
		WellsFargo.deposit(generateValue(100, 200), "Savings");

		//Loan Payment
		payment = generateValue(700, 800);
		if (!Chase.withdraw(payment, "Loan Payment")){
			cout << "Chase checking short $" << payment - Chase.get_balance() << " for loan." << endl;
			accumulatedBounces += payment;
		}
		
		//Pay five bills
		for (int bill = 1; bill <= 5; bill++){
			payment = generateValue(30, 80);
			if (!Chase.withdraw(payment, "Bill #" + std::to_string(bill))){
				cout << "Chase checking short $" << payment - Chase.get_balance() << " for bill #" << bill << "." << endl;
				accumulatedBounces += payment;
			}
		}

		//Charge ten times Credit Card
		for (int charge = 1; charge <= 10; charge++){
			payment = generateValue(20, 90);
			if (!Visa.withdraw(payment, "Charge #" + std::to_string(charge))){
				cout << "Visa credit card short $" << payment - Visa.get_balance() << " for charge #" << charge << "." << endl;
				accumulatedBounces += payment;
			}
		}

		//Pay Credit Card
		payment = generateValue(200, 300);
		if (!Visa.transfer_from(Chase, payment, "Credit Card Payment")){
			cout << "Chase checking short $" << payment - Chase.get_balance() << " for credit card payment." << endl;
		}

		//End of month tidying - optional, transfers from checking and savings to reduce credit financing
		if (Visa.get_debt()) {

			float payPartial = Chase.get_balance() > Visa.get_debt() ? Visa.get_debt() : Chase.get_balance();
			if (Visa.transfer_from(Chase, payPartial, "Checking transfer")){
				cout << "\tPartial credit pay $" << payPartial << " from checking." << endl;
			}
			
			payPartial = WellsFargo.get_balance() > Visa.get_debt() ? Visa.get_debt() : WellsFargo.get_balance();
			if (Visa.transfer_from(WellsFargo, payPartial, "Savings transfer")){
				cout << "\tPartial credit pay $" << payPartial << " from savings." << endl;
			}
		}

		Visa.compound();
		WellsFargo.compound();

	}

	cout << endl << "Press any button to print history." << endl << endl;
	system("pause > nul");


	cout << "Wells Fargo savings history" << endl
		 << "---------------------------" << endl
		 << WellsFargo.get_history_string()
		 << "\t________" << endl << "\t" << std::setw(7) << WellsFargo.get_balance() << " | Balance ($)" << endl << endl;

	cout << "Chase checking history" << endl
		 << "----------------------" << endl
		 << Chase.get_history_string()
		 << "\t________" << endl << "\t" << std::setw(7) << Chase.get_balance() << " | Balance ($)" << endl << endl;

	cout << "Visa credit card history" << endl
		 << "------------------------" << endl
		 << Visa.get_history_string()
		 << "\t________" << endl << "\t" << std::setw(7) << Visa.get_balance() << " | Balance ($)" << endl << endl;

	cout << "\tAccumulated bounces: $" << accumulatedBounces << endl;


	system("pause > nul");
	cout << endl << "Press any button to exit." << endl << endl;

	return 0;
}