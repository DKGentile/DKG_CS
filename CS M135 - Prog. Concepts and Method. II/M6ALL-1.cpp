#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

class Node
{
public:
	char letter;
	Node* next;
	Node(char cc) {
		letter = cc;
		next = nullptr;
	}
};

int main() {
	cout << "1) Create/Append linked list" << endl;
	cout << "2) Delete from linked list" << endl;
	cout << "3) Insert into linked list" << endl;
	cout << "4) Display Linked List" << endl;
	cout << "5) Exit" << endl;
	char c, c1;
	Node* start = nullptr;
	Node* end;
	Node* p;
	Node* p2;
	Node* t;
	int i;

	while (1) {
		cout << "Enter Your Choice: ";
		cin >> i;
		//if user enters 1, create a new linked list/append an existing one
		if (i == 1)
		{
			while (1)
			{
				c = _getch(); //recieving desired value for node
				if (c == 27) //if user presses escape, break
				{
					break;
				}
				cout << c; //print the user's input
				Node* newnode = new Node(c); //creating a new node containing the user's input
				if (start == nullptr) //if start is null, set it to the new node
				{
					start = newnode;
				}
				else //if there is a starting node, append the new node 
				{
					end = start;
					while (end->next != nullptr) //looping through the linked list to reach the end in order to append the new node
					{
						end = end->next; //self explainatory
					}
					end->next = newnode; //appending the new node onto the linked list
				}
			}
			cout << endl;
			Sleep(100);
		}
		//if user enters 4, display the linked list
		if (i == 4)
		{
			t = start; //setting t = start
			while (t != nullptr) //looping through entire linked list and printing each node
			{
				cout << t->letter;
				t = t->next;
			}
			Sleep(100);
			cout << endl;
		}
		//if user enters 2, trigger delete sequence
		if (i == 2)
		{
			t = start; //setting 't' to 'start'
			string inp;
			cout << endl;
			cout << "What letter would you like to remove?";
			c = _getch(); //recieving desired node from user
			if (start != nullptr) { //making sure start exists
				if (start->letter == c) //if user wants to delete first node, move start to the next node and delete t
				{
					start = start->next;
					delete t;
				}
			}
			else if (t != nullptr) { //if user does not want to delete first node and t/start != null, execute sequence
				while (t->letter != c) //searching through the linked list for desired node
				{
					if (t->next == nullptr) //if we reach the end of the list without finding the desired node, break and inform user
					{
						cout << endl;
						cout << "Invalid input!";
						break;
						cout << endl;
					}
					t = t->next; //moving along the linked list
				}
				if (t->letter == c) //if the desired node was found, execute following sequence
				{
					Node* p = start; //creating a new node 
					while (p->next != t) //using new node to find desired node that was found previously
					{
						p = p->next; //must I explain?
					}
					p2 = t->next; //storing the location of the node after the desired node
					delete t; //deleting the desired node
					p->next = p2; //connecting the linked list after having removed a node
				}
				Sleep(100);

			}
			cout << endl;
		}
		//if user enters 3, trigger instert operations
		if (i == 3)
		{
			cout << endl;
			t = start;
			cout << "What character you like to insert?";
			c1 = _getch(); //asking and recieving user's desired input
			cout << endl;
			cout << "What do you want to place it after?";
			c = _getch(); //asking and recieving user's desired input
			cout << endl;
			if (t != nullptr) //making sure t/start is not null
			{
				while (t->letter != c) //looping through the list searching for user's input. will break when desired node is found or not found
				{
					if (t->next == nullptr) //if while searching through the loop we encounter a null, break
					{
						cout << "Invalid input!" << endl;
						break;
					}
					t = t->next; //looping through to the next node
				}
				if (t->letter == c) //if the desired node is found, insert letter after
				{
					p = t->next; //creating a node after to point to
					p2 = new Node(c1); //creating the new node
					p2->next = p; //pointing the new node to the one after
					t->next = p2; //setting previous node to point to new node
					//visualization: desired node -> node after => desired node -> new node -> node after

				}
			}
			Sleep(100);
		}
		//if the user enters 5, return 0 and end the program
		if (i == 5)
		{
			return 0;
		}
	}

}

