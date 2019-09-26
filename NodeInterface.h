#pragma once

#include <iostream>

class NodeInterface {

public:
	NodeInterface() {}
	virtual ~NodeInterface() {}
	virtual int getData() const = 0;
	virtual NodeInterface * getLeftChild() const = 0;
	virtual NodeInterface * getRightChild() const = 0;

};