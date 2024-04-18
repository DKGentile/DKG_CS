#include "Colors.h"
void Colors::SetColor(int bg, int fg)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (15 * bg) + fg);
}

void Colors::DisplayColors()
{
	system("cls");
	for (int i = 0; i <= 15; i++)
	{
		SetColor(i, 15);
		cout << i << endl;
	}
}