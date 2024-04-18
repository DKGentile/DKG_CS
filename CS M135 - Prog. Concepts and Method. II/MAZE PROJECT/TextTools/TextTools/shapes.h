#pragma once
#include "Coordinates.h"
#include <map>
#include <vector>

class Shapes:public Coordinates
{
private:
	HANDLE  hConsole;
	map<int, int> colors;
public:
	Shapes();
	void PrintSymbol(int val);
	void MapValueToColor(int v, int clr);
	void Displayshape(vector <int> vec, int columns, int x, int y);
};
