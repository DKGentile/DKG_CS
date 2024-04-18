/*
   W4HW_Demitri.cpp
   Demitri Gentile
   6/12/2022
   Version: 1.0
   The following program will create a 'Mortgage' class that will then
   be called upon by the main function. When called, the user will be
   asked to input values for variables within the class, and will output
   the calculated monthly payment and total payment of the mortgage.
*/


#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

class Mortgage {
private:
	double princ;
	double rate;
	double term;
	double mip;
	double total;
public:
	Mortgage() {}
	double setRate() { //setting the rate
		cout << "What is the rate?: ";
		cin >> rate;
		while (rate < 0) { //input validation
			cout << "Please enter a positive number: ";
			cin >> rate;
		}
		return rate;
	}
	double setPrinc() { //setting the principal
		cout << "How much are you borrowing?: ";
		cin >> princ;
		while (princ < 0) { //input validation
			cout << "Please enter a positive number: ";
			cin >> princ;
		}
		return princ;
	}
	double setTerm() { //setting the term
		cout << "How long is the term (in years)?: ";
		cin >> term;
		while (term < 0) { //input validation
			cout << "Please enter a positive number: ";
			cin >> term;
		}
		return term;
	}
	void getPrinc() {
		cout << princ;
	}
	void getRate() {
		cout << rate;
	}
	void getTerm() {
		cout << term;
	}
	double setMP() { //calculating monthly payment
		term = term * 12;
		rate = rate / 1200;
		mip = princ * rate / (1.0 - pow(rate + 1, -term));
		term = term / 12;
		return mip, term;
	}
	double setTotal() { //calculating total payment
		term = term * 12;
		rate = rate * 12;
		total = princ + (princ * rate);
		term = term / 12;
		return total, term;
	}
	void getCalc() { //informing user of both monthly and total payment
		cout << endl;
		cout << "===========================================================================" << endl;
		cout << "Your monthly payment should be: $" << mip << endl << "The total loan payment will be:  $" << total << endl;
		cout << "===========================================================================";
		cout << endl;
	}

};

int main() 
{
	Mortgage ef;
	char a;
	ef.setPrinc(); //setting the principal
	ef.setRate(); //setting the rate
	ef.setTerm(); //setting the term
	/* The following is simply validating the information with the user */
	cout << endl << "============================================================" << endl << "Principal: ";
	ef.getPrinc();
	cout << " Rate: ";
	ef.getRate();
	cout << "% Term: ";
	ef.getTerm();
	cout << " years" << endl << "============================================================" << endl;
	cout << "Is the following information correct?: [y/n]  ";
	cin >> a;
	while (a != 'y') { //the following loop allows the user to correct any errors
		ef.setPrinc(); 
		ef.setRate(); 
		ef.setTerm(); 
		cout << endl << "============================================================" << endl << "Principal: ";
		ef.getPrinc();
		cout << " Rate: ";
		ef.getRate();
		cout << "% Term: ";
		ef.getTerm();
		cout << " years" << endl << "============================================================" << endl;
		cout << "Is the following information correct?: [y/n]  ";
		cin >> a;
	}
	ef.setMP(); //calculating the monthly payment
	ef.setTotal(); //calculating the total payment
	ef.getCalc(); //informing the user of bother monthly and total payment
}