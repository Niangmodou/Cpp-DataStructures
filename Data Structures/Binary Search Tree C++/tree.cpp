#include "tree.h"

Node::Node(int data = 0, Node* right = nullptr, Node* left = nullptr) :
	left(left),right(right),data(data){}