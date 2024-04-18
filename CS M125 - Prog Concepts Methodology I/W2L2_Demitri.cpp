/*
   W2L2_Demitri.cpp
   Demitri Gentile
   6/6/2022
   Version: 1.0
   The following program will ask the user for
   their balance and the amount of checks they
   would like to deposit. Then, the program will
   inform them of their monthly fee based on the
   given information. The program also has data
   validation to make sure the balance and amount
   of checks entered by the user are positive, or 
   atleast greater than zero.
*/


#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	double balance, fees; //creating the balance and fees variable
	int checks; //creating the checks variable as an integer
	fees = 0;
	cout << "Welcome to the bank." << endl;
	cout << "What would be your balance?: "; //getting the user's balance
	cin >> balance; //storing the users balance
	if (balance < 0) { //if the user's balance is less than 0 (negative), the program will not proceed
		cout << "!URGENT!: Your account is overdrawn!" << endl;
	}
	else {
		cout << "How many checks will you be depositing this month?: "; //getting the amount of user's checks
		cin >> checks; //storing the amount of user's checks
		while (checks < 0) { //data validation so the user does not input a negative value
			cout << "Invalid input. Please enter a positive number: ";
			cin >> checks;
		}
		//the following if/else statement will calculate the 'fees' that will charged to the user
		//the amount of fees charged to the user is based on an increment system.
		if (checks < 20) {
			fees = checks * 0.1;
		}
		else if (checks >= 20 and checks < 40) {
			fees = checks * 0.08;
		}
		else if (checks >= 40 and checks < 60) {
			fees = checks * .06;
		}
		else if (checks >= 60) {
			fees = checks * .04;
		}
		fees = fees + 10;
		//the following if/else statement will determine whether or not the user is charged another 15 due to the lack of a balance,
		//then the program will inform the user how much they will be charged in fees.
		if (balance < 400) {
			fees = fees + 15;
			cout << "Your monthly fee will be $" << fees << endl;
		}
		else {
			cout << "Your monthly fee will be $" << fees << endl;
		}

	}
	
	return 0;

}