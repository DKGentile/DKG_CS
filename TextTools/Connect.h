#pragma once
#include "Coordinates.h"

class Connect : public Coordinates
{
public:
	void Link(int x1, int y1, int x2, int y2);
};