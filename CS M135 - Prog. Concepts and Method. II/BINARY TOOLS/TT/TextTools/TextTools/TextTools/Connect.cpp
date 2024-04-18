#include "Connect.h"

void Connect::Link(int x1, int y1, int x2, int y2)
{	
	if (x2 > x1 && y2 > y1) // if object is right bottom
	{
		gotoxy(x1, y1);
		cout << char(179);
		gotoxy(x1, y1 + 1);
		cout << char(192);
		for (int i = x1 + 1; i < x2; i++)
		{
			gotoxy(i, y1 + 1);
			cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		cout << char(191);
		for (int i = y1 + 2; i < y2; i++)
		{
			gotoxy(x2, i);
			cout << char(179);
		}
	}
	else if (x2 > x1 && y2 < y1) // if object is right top
	{
		gotoxy(x1, y1);
		cout << char(179);
		gotoxy(x1, y1 + 1);
		cout << char(192);
		for (int i = x1 + 1; i < x2; i++)
		{
			gotoxy(i, y1 + 1);
			cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		cout << char(217);
		for (int i = y1; i > y2; i--)
		{
			gotoxy(x2, i);
			cout << char(179);
		}
	}
	else if (x2 < x1 && y2 > y1) // if object is left bottom
	{
		gotoxy(x1, y1);
		cout << char(179);
		gotoxy(x1, y1 + 1);
		cout << char(217);
		for (int i = x1 - 1; i > x2; i--)
		{
			gotoxy(i, y1 + 1);
			cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		cout << char(218);
		for (int i = y1 + 2; i < y2; i++)
		{
			gotoxy(x2, i);
			cout << char(179);
		}
	}
	else if (x2 < x1 && y2 < y1) // if object is Left top
	{
		gotoxy(x1, y1);
		cout << char(179);
		gotoxy(x1, y1 + 1);
		cout << char(217);
		for (int i = x1 - 1; i > x2; i--)
		{
			gotoxy(i, y1 + 1);
			cout << char(196);
		}
		gotoxy(x2, y1 + 1);
		cout << char(192);
		for (int i = y1; i > y2; i--)
		{
			gotoxy(x2, i);
			cout << char(179);
		}
	}

}
