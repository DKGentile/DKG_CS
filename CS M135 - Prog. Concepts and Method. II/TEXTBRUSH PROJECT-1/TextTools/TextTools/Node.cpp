#include "Node.h"

Node::Node()
{
	left = right = nullptr;
	level = 0;
}

Node::Node(int val, int xx, int yy): Node()
{
	x = xx;
	y = yy;
	value = val;
}

int Node::getValue()
{
	return value;
}