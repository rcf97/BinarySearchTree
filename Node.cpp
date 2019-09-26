#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}
//virtual ~Node() {}
	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
int Node::getData() const {
    return this->data;
}
	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
NodeInterface * Node::getLeftChild() const {
    return this->left;
}
	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
NodeInterface * Node::getRightChild() const {
    return this->right;
}