/*
   W3HW_Demitri.cpp
   Demitri Gentile
   6/12/2022
   Version: 1.0
   The following program will ask the user for
   a number and then proceed to create an array
   the size of the number entered by the user.
   The array will be populated with the square
   of every number beggining with one up to the
   value specified by the user.
*/


#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	int inp = 0; //initializing inp
	while (inp <= 0) { //the following while loop will ensure the user enters a value greater than zero
		cout << "Enter a number greater than 0: ";
		cin >> inp;
	}	
	int* foo = new int[inp]; //a new array of size 'inp' is allocated to pointer 'foo'
	for (int i = 0; i < inp; i++) { //the following for loop will populate the array with integers sqaured
		foo[i] = pow((i+1),2);		//starting with one up to the array size defined by 'inp'
	}
	for (int i = 0; i < inp; i++) { //the following for loop will print to the users all of the integers withing array 'foo'
		cout << foo[i] << " ";
	}
	return 0;
}