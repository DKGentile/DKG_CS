/*
   W4Lab_Demitri.cpp
   Demitri Gentile
   6/12/2022
   Version: 1.0
   The following program will ask the user for
   the title, director, year, and run time of
   two movies. The information will be stored 
   in an array who's datatype is an abstract
   datatype named 'MovieData'. The information
   of each movie will be stored as a variable
   within an array. The array will then be 
   passed into another function, which will then
   display the information within each variable
   of the array.
*/


#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

struct MovieData { //creating the 'MovieData' structure
	string title; //allowing a string variable to be stored within the structure
	string director; //allowing another string
	int year; //allowing an integer variable to be stored within the structure
	int rtime; //allowing another integer
};

void displayfunc(MovieData B[]) { //The following function will display the information contained within each variable of the array (which has been passed from the main() function
	//the following for-loop will display each each component if the variables contained within the array
	for (int i = 0; i < 2; i++) {
		cout << "Movie " << i + 1 << ": " << endl;
		cout << "Title: " << B[i].title << endl;
		cout << "Director: " << B[i].director << endl;
		cout << "Year: " << B[i].year << endl;
		cout << "Run time: " << B[i].rtime << endl;
		cout << "======================================" << endl;
	}
}

int main() { //the following function will assign data to the array and pass it into the displayfunc() function
	MovieData a[2]; //creating an array ('a') who's datatype is defined by the 'MovieData' structure
	string b; //creating a string variable that will be used to store string values
	int d; //creating an integer variable that will be used to store integer values
	for (int i = 0; i < 2; i++) { //the following for-loop will assign information to each variable within the 'MovieData' array
		cout << "What is the name of movie number " << i + 1 << "?: "; //getting 'title' from user
		cin >> b; //storing the entered string value
		a[i].title = b; //assigning the string value to a variable within the array
		cout << "What who directed that movie?: "; //getting 'director' from user
		cin >> b;
		a[i].director = b;
		cout << "When was that movie released?: "; //getting 'year' from user
		cin >> d;
		a[i].year = d;
		cout << "How long, in minutes, is the movie?: "; //getting 'rtime' from user
		cin >> d;
		a[i].rtime = d;
		cout << endl;
	}
	displayfunc(a); //calling upon the displayfunc() function, passing the 'a' array through
	return 0;
}