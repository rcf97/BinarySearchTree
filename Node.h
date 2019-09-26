#pragma once

#include <iostream>
#include "NodeInterface.h"
using namespace std;

class Node : public NodeInterface {
public:
	Node* left;
	Node* right;
	int data;
	Node(int data);
	virtual ~Node() {}
	int getData() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
};