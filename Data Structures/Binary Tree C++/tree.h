#include <iostream>

struct TNode{
	TNode(int data = 0; TNode* left, TNode* right);

};

class BinaryTree{
	friend std::ostream& operator<<(std::ostream&,const BinaryTree&);
private:
	TNode* root;
	size_t currSize;
public:
	BinaryTree();

	~BinaryTree();

	BinaryTree(const BinaryTree&);

	BinaryTree& operator=(const BinaryTree&);

	size_t size() const;

	bool empty() const;

	int sum() const;

	void push_back();
};