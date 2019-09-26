#pragma once

#include "NodeInterface.h"
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {
	Node* root;
public:
	BST();
	~BST();
	NodeInterface * getRootNode() const;
	bool add(int data);
	bool insert(Node* &localRoot, int data);
	bool search(Node* localRoot, int data) const;
	bool remove(int data);
	bool delVal(Node*& localRoot, int data);
	void delTree(Node*& localRoot);
	void clear();
};
