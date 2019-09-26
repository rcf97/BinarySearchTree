#include "Node.h"
#include "BST.h"

using namespace std;

BST::BST() {
    this->root = nullptr;
}
BST::~BST() {
    delTree(this->root);
}

NodeInterface * BST::getRootNode() const {
    return this->root;
}

bool BST::add(int data) {
    if (this->root == nullptr) {
        Node* newPtr = new Node(data);
        this->root = newPtr;
        return true;
    }
    if (search(this->root, data) == true) {
        return false;
    }
    else {
        return insert(this->root, data);
    }
}

bool BST::search(Node* localRoot, int data) const {
    if (localRoot->data == data) {
        return true;
    }
    else if (data < localRoot->data && localRoot->left == nullptr) {
        return false;
    }
    else if (data > localRoot->data && localRoot->right == nullptr) {
        return false;
    }
    else if (data < localRoot->data) {
        return search(localRoot->left, data);
    }
    else if (data > localRoot->data) {
        return search(localRoot->right, data);
    }
    else {
        return false;
    }
}

bool BST::insert(Node*& localRoot, int data) {
    if (localRoot == nullptr) {
        Node* newPtr = new Node(data);
        return true;
    }
    else if (localRoot->data > data && localRoot->left == nullptr) {
        localRoot->left = new Node(data);
        return true;
    }
    else if (localRoot->data < data && localRoot->right == nullptr) {
        localRoot->right = new Node(data);
        return true;
    }
    else if (localRoot->data > data) {
        return insert(localRoot->left, data);
    }
    else if (localRoot->data < data) {
        return insert(localRoot->right, data);
    }
    else {
        return false;
    }
}

bool BST::remove(int data) {
    if (search(this->root, data) == false) {
        return false;
    }
    return delVal(this->root, data);
}

bool BST::delVal(Node*& localRoot, int data) {
    if (localRoot == nullptr) {
        return false;
    }
    else if ((data < localRoot->data && localRoot->left == nullptr) || (data > localRoot->data && localRoot->right == nullptr)) {
        return false;
    }
    else if (data < localRoot->data) {
        return delVal(localRoot->left, data);
    }
    else if (data > localRoot->data) {
        return delVal(localRoot->right, data);
    }
    else {
        if (localRoot->left == nullptr && localRoot->right == nullptr) {
            Node* tmp = localRoot;
            localRoot = nullptr;
            delete tmp;
            return true;
        }
        else if (localRoot->left == nullptr) {
            Node* tmp = localRoot;
            localRoot = localRoot->right;
            delete tmp;
            return true;
        }
        else if (localRoot->right == nullptr) {
            Node* tmp = localRoot;
            localRoot = localRoot->left;
            delete tmp;
            return true;
        }
        else {
            if (localRoot->left->right == nullptr) {
                Node* tmp = localRoot->right;
                localRoot->left->right = tmp;
                tmp = localRoot;
                localRoot = localRoot->left;
                delete tmp;
                return true;
            }
            else {
                Node* newRoot = localRoot->left;
                do {
                    newRoot = newRoot->right;
                } while (newRoot->right != nullptr);
                localRoot->data = newRoot->data;
                delVal(localRoot->left, localRoot->data);
                return true;
            }
        }
    }
}

void BST::delTree(Node*& localRoot) {
    if (localRoot == nullptr) {
        return;
    }
    delTree(localRoot->left);
    delTree(localRoot->right);
    delete localRoot;
}
void BST::clear() {
    delTree(this->root);
    this->root = nullptr;
}
