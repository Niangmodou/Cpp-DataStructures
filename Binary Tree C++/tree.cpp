#include <iostream>
#include "tree.h"

using namespace std;

TNode(int data = 0; TNode* left, TNode* right);

BinaryTree::BinaryTree();

BinaryTree::~BinaryTree();

BinaryTree::BinaryTree(const BinaryTree&);

BinaryTree& BinaryTree::operator=(const BinaryTree&);

int sum() const;

size_t BinaryTree::size() const {
	return currSize;
}

bool BinaryTree::empty() const {
	return size() == 0;
}