#include <iostream>
#include "BinaryTree.h"
#include "MyRectangle.h"
using namespace std;

void stuffy(BinaryTree L, int y) {
	
	if (L.IsFull()) {
		L.gotoxy(0, y);
		cout << "IS FULL";
	}
	else {
		L.gotoxy(0, y);
		cout << "IS NOT FULL";
	}
	if (L.IsComplete()) {
		L.gotoxy(0, y+1);
		cout << "IS COMPLETE";
	}else {
		L.gotoxy(0, y+1);
		cout << "IS NOT COMPLETE";
	}
	if (L.IsComplete() && L.IsFull()) {
		L.gotoxy(0, y+2);
		cout << "IS PERFECT";
	}else {
		L.gotoxy(0, y+2);
		cout << "IS NOT PERFECT";
	}
}

void main()
{
	int x, y;
	int a, b;
	a = b = 0;
	y = 50;
	x = 0;
	BinaryTree L(10, 100, 50);
	L.Insert(11);
	L.Insert(9);	
//	L.Insert(3);
//	L.Insert(5);
//	L.Insert(7);
//	L.Insert(2);
//	L.Insert(32);
//	L.Insert(12);
//	L.Insert(2);
//	L.Insert(6);
	L.PrintTree();
	stuffy(L, y);
	L.gotoxy(0, 53);
	cout << L.pcont << " parents";
	L.gotoxy(0, 54);
	cout << L.lcont << " leafs";
	while (1);


}