/*
   W1HW_Demitri.cpp
   Demitri Gentile
   5/24/2022
   Version: 1.4
   The following program will ask for the principal, rate, and term of
   a loan, then inform the user of the monthly payment they have agreed
   to.
*/


#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double princ, rate, term, mP;

	//getting the information required
	cout << "How much money are you borrowing?: ";
	cin >> princ;

	cout << "What is the interest on said loan?: ";
	cin >> rate;

	cout << "How long is the loan term?: ";
	cin >> term;

	//converting rate and term to month
	rate = rate / 1200.0;
	term = term * 12;

	//calculating monthly payment
	mP = (princ * rate) / (1.0 - pow(rate + 1, -term));

	//informing the user
	cout << "Your monthly payment is: $" << mP << endl;

}