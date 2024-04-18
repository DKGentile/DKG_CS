#include "shapes.h"

Shapes::Shapes()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Shapes::MapValueToColor(int v, int clr)
{
	colors.insert(pair <int, int>(v, clr));
}

void Shapes::PrintSymbol(int val)
{
	if (colors.find(val) != colors.end())
		SetConsoleTextAttribute(hConsole, colors.find(val)->second);
	else
		SetConsoleTextAttribute(hConsole, 245);
	//if (val == 176)
	//{
	//	val = 219;
	//}
	//else if (val == 196)
	//{
	//	val = 32;
	//}
	cout << char(val);
}

void Shapes::Displayshape(vector <int> vec, int columns, int x, int y)
{
	int forcenewline = 0;
	int tempX = x;
	for (int i = 0; i < vec.size(); i++)
	{
		gotoxy(tempX,y);
		PrintSymbol(vec[i]);
		tempX++;
		forcenewline++;
		if ((forcenewline % columns) == 0)
		{
			y++;
			tempX = x;
			cout << endl;
		}
	}
}