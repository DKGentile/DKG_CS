/*
   W3Lab_Demitri.cpp
   Demitri Gentile
   6/12/2022
   Version: 1.0
   The following program will ask the user for
   the term, rate, and principal of a loan in the
   'main' function. Then, these values will be passed
   to the 'calc' function in order to calculate the
   monthly payment on said loan.
*/


#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

//the following function will accept three variables from the 'main' function.
//then, this function will calculate the monthly payment with the passed variables.
int calc(long double p, long double r, long double t) { 
	r = r / 1200;
	t *= 12;
	long double mp;
	mp = (p * r) / (1 - pow(r + 1, -t));
	cout << "The monthly payment for this loan is $" << mp;
	return 0;
}

//the following function will collect the prinipal (p), rate (r), and term (t) of a loan from user.
//then, these three variables will be passed back to the 'calc' function.
int main() {
	//initializing the variables that will be used.
	//variables are given a negative value to trigger the following while loops.
	long double p = -1, r = -1, t = -1;
	//the following three loops will assign valued to their respective variables.
	while (p < 0) {
		cout << "How much is the loan?: ";
		cin >> p;
	}
	while (r < 0) {
		cout << "What is the rate?: ";
		cin >> r;
	}
	while (t < 0) {
		cout << "How long is the term?: ";
		cin >> t;
	}
	//the previous three variables, now assigned a positive value, will be passed into the 'calc'
	//function for further processing.
	calc(p, r, t);
}

