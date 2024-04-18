/*
   W2L1_Demitri.cpp
   Demitri Gentile
   6/6/2022
   Version: 1.0
   The following program will ask the user for
   their weight and height, and will calculate
   their BMI. The program will also inform them
   if they are considered underweight, overweight,
   or have an optimal BMI measurment.
*/


#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	double weight, height, bmi; //creating the variables that will be used
	cout << "What is your weight?"; //getting the weight from user
	cin >> weight; //storing the weight from user
	cout << "What is your height (in inches)?"; //getting height from user
	cin >> height; //storing height of user
	bmi = (weight * 703) / pow(height, 2); //calculating user's BMI
	cout << "Your BMI is " << bmi << endl; //informing the user of their BMI
	//the following lines of if/else statements will inform the user what their BMI means
	if (bmi < 18.5) cout << "You are considered underweight." << endl; 
	else if (bmi > 25) cout << "You are considered overweight." << endl;
	else cout << "You have an optimal BMI." << endl;
	return 0;
}