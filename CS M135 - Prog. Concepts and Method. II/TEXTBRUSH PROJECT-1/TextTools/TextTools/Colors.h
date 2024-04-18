#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;


class Colors
{
private:
	HANDLE hConsole;
public:
	void SetColor(int bg, int fg);
	void DisplayColors();
};