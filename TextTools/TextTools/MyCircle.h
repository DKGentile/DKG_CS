#pragma once
#include "Coordinates.h"

class MyCircle : public Coordinates
{
public:
	int m_x, m_y, m_radius;
	int Circ(int x, int y, int r) {
		m_x = x;
		m_y = y;
		m_radius = r;

	}
	void DrawCircle();
	int GetType() {
		return 1;
	}
};

