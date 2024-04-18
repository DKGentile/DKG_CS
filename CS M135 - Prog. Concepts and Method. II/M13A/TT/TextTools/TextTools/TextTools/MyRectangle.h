#pragma once
#include "Coordinates.h"


class MyRectangle : public Coordinates
{
public:
	int m_x, m_y, m_w, m_h;
	char m_symbol;
	bool m_hollow;
	int m_recColor, m_textColor;
	HANDLE hConsole;
	string m_text;
	int m_sleepTime;

	MyRectangle();
	MyRectangle(int xx, int yy, int ww, int hh, char cc, bool hol = false, int recCol = 15, int txtCol = 15, string text = "", int sleepTime = 250);
	void Draw();
	void Draw(int x, int y, int w, int h, int symbol = 219, int color = 15, string txt = "");
	void DrawSkelaton(int x, int y, int w, int h, string txt = "", int color = 15);
	void SetX(int xx);
	void SetY(int yy);
	void setWidth(int ww);
	void setHeight(int hh);
	void setSymbol(char cc);
	void setHollow(bool h);
	void setRectangleColor(int colr);
	void setTextColor(int colr);
	void setText(string txt);
	void DrawPath(string path);
	void setSleepTime(int s);
	void EraseBox();
	void Impolode();
};
