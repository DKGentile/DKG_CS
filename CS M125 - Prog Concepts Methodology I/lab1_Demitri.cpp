/*
   lab1_Demitri.cpp
   Demitri Gentile
   5/24/2022
   Version: 1.0
   The following program will ask the user for
   a measurment in fahrenheit, then it will convert
   the measurment into celcius and inform the user
   of the measurment.
*/


#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double f, c;
	//asking the user for an input
	cout << "What is the tempurature, in Fahrenheit?:";
	cin >> f;
	//calculating the conversion
	c = (5.0 / 9.0) * (f - 32.0);
	//informing the user of the conversion
	cout << "The tempurature in Celcius is:" << c << endl;
}