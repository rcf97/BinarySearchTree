#pragma once

#include "NodeInterface.h"

using namespace std;

class BSTInterface {
public:
	BSTInterface() {}
	virtual ~BSTInterface() {}
	virtual NodeInterface * getRootNode() const = 0;
	virtual bool add(int data) = 0;
	virtual bool remove(int data) = 0;
	virtual void clear() = 0;
};