#pragma once
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Coordinates.h"
using namespace std;

class MyMouse : public Coordinates
{
public:
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole;

	HANDLE hout;
	HANDLE hin;
	INPUT_RECORD InputRecord;
	DWORD Events;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	int buttonX,buttonY;

public:
	MyMouse();
	~MyMouse();
	void ReadMouseInput();
	void drawpixel(unsigned char x, unsigned char y, unsigned char Color);
	void drawpixel2(unsigned char x, unsigned char y, unsigned char Color, char character);
	void drawcircle(int x, int y, int a, int b, int color);
	void drawline(int x0, int y0, int x1, int y1, int color);
	void drawfilledrectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol);
	void drawframe(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char col, unsigned char col2, char text_[]);
	void drawwindow(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char col, unsigned char col2, unsigned char bkcol, char text_[]);
};