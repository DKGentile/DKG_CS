#pragma once
#include <string>
#include <fstream>
#include "Coordinates.h"

class Node: public Coordinates {
	int value;
	int level;
public:
	int x, y;
	Node* right;
	Node* left;

	Node();
	Node(int val, int xx, int yy);
	int getValue();
};
