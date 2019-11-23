#include <iostream>

class SinglyLinkedList{
private:
	int size = 0;
	struct Node{
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};
public:
	SinglyLinkedList();

	~SinglyLinkedList();

	int length();

	bool isEmpty();

	void addLast();

	Node deleteNode();

	Node deleteLast();
}