#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

int Node::getData() const {
    return this->data;
}

NodeInterface * Node::getLeftChild() const {
    return this->left;
}

NodeInterface * Node::getRightChild() const {
    return this->right;
}
