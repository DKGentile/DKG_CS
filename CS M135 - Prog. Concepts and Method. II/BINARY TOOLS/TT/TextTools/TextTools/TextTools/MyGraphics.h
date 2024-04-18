#pragma once
#include "Coordinates.h"

class MyGraphics
{
private:
	HWND myconsole;
	HDC mydc;
	COLORREF COLOR;
public:
	MyGraphics();
	~MyGraphics();
	void SetColor(int R, int G, int B);
	void DrawPixel(int x, int y);
	void DrawCircle(int x, int y, int radius);
};