#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

class Coordinates
{
public:
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	HANDLE hOutput;
	void gotoxy(int x, int y)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		_COORD pos;
		pos.X = x;
		pos.Y = y;

		SetConsoleCursorPosition(hConsole, pos);
	}

	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}
	void ReadScreenShot();
	void RefreshArea(int x1, int y1, int x2, int y2);

	void setcolor(WORD color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		return;
	}

	void setForeGroundAndBackGroundColor(int ForeGroundColor, int BackGroundColor) {
		int color = 16 * BackGroundColor + ForeGroundColor;
		setcolor(color);
	}
};


