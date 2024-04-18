#pragma once
#include "Node.h"

const int BOXWIDTH = 6;
const int BOXHEIGHT = 2;
const int XPADDING = 25;
const int YPADDING = 5;

class BinaryTree : public Node
{
private:

	void InsertAt(Node* n, int val, int level);
	void PrintAt(Node* n, int xParent =-1,int yParent = -1);
public:
	Node* root;
	BinaryTree();
	BinaryTree(int v, int x, int y);
	void Insert(int val);
	void PrintTree();
	void DeleteTree();
	void DeleteTreeAt(Node *n);
	void SetRoot(int v, int x, int y);
	bool IsComplete();
	bool IsCompleteCalc(Node* ptr, int* hasLeft);
	bool IsFull();
	bool IsFullCalc(Node* ptr);
};