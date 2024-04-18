#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include <stdio.h>	
#include <stdlib.h>
#include <Windows.h>


// using namespace std;
using std::cout;
using std::endl;

class Node
{
public:
	char letter;
	Node* next;
	Node(int n) { letter = n; next = nullptr; }
};

void main()
{
	char c;	
	Node* start = nullptr;
	while (1)
	{
		if (_kbhit()) {
			c = _getch();
			if (c == 27) {
				break;
			}
		}
		int d = rand() % 90 + 65;
		char c;
		c = d;
		cout << c;
		Node* temp = new Node(c);
		if (start == nullptr)
		{
			start = temp;
		}
		else {
			Node* p = new Node(c);
			p = start;
			while (p->next != nullptr)
			{
				p = p->next;
			}
			p->next = temp;
		}

		Sleep(200);
	}
	cout << endl;
	Node* ptr;
	ptr = start;
	while (ptr != nullptr)
	{
		cout << ptr->letter << endl;
		ptr = ptr->next;
	}
}
