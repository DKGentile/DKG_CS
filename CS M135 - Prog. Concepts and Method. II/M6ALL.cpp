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
		if (i == 1)
		{
			while (1)
			{
				c = _getch();
				if (c == 27)
				{
					break;
				}
				cout << c;
				Node* newnode = new Node(c);
				if (start == nullptr)
				{
					start = newnode;
				}
				else
				{
					end = start;
					while (end->next != nullptr)
					{
						end = end->next;
					}
					end->next = newnode;
				}
			}
			cout << endl;
			Sleep(100);
		}
		if (i == 4)
		{
			t = start;
			while (t != nullptr)
			{
				cout << t->letter;
				t = t->next;
			}
			Sleep(100);
			cout << endl;
		}
		if (i == 2)
		{
			t = start;
			string inp;
			cout << endl;
			cout << "What letter would you like to remove?";
			c = _getch();
			if (start != nullptr) {
				if (start->letter == c)
				{
					start = start->next;
					delete t;
				}
			}
			else if (t!=nullptr) {
				while (t->letter != c)
				{
					if (t->next == nullptr)
					{
						cout << endl;
						cout << "Invalid input!";
						break;
						cout << endl;
					}
					t = t->next;
				}
				if (t->letter == c)
				{
					Node* p = start;
					while (p->next != t)
					{
						p = p->next;
					}
					p2 = t->next;
					delete t;
					p->next = p2;
				}
				Sleep(100);

			}
			cout << endl;
		}
		if (i == 3)
		{
			cout << endl;
			t = start;
			cout << "What character you like to insert?";
			c1 = _getch();
			cout << endl;
			cout << "What do you want to place it after?";
			c = _getch();
			cout << endl;
			if (t != nullptr)
			{
				while (t->letter != c)
				{
					if (t->next == nullptr)
					{
						cout << "Invalid input!" << endl;
						break;
					}
					t = t->next;
				}
				if (t->letter == c)
				{
					p = t->next;
					p2 = new Node(c1);
					p2->next = p;
					t->next = p2;

				}
			}
			Sleep(100);
		}
		if (i == 5)
		{
			return 0;
		}
	}

}

