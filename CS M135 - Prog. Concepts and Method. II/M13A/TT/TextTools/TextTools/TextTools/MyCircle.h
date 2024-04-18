#pragma once
#include "Coordinates.h"

class MyCircle : public Coordinates
{
public:
	int m_x, m_y, m_radius;

	void DrawCircle();
};

