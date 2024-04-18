#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Coordinates.h"

class Node: public Coordinates {
	int value;
	int level;
public:
	int x, y;
	Node* right;
	Node* left;
	bool r, g, yel;
	

	Node();
	Node(int val, int xx, int yy);
	int getValue();
};
