#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
	Node(){}
};

void printList(Node& node){
	Node* currNode;
	currNode = &node;

	cout << "[ ";
	while(currNode){
		cout << currNode->data;
		if(currNode->next){ cout << " -> ";}
		currNode = currNode->next;
	}
	cout << " ]";
	
}


int main(){

	Node num1(1);
	Node num2(2);
	Node num3(3);
	Node num4(4);
	Node num5(5);

	num1.next = &num2;
	num2.next = &num3;
	num3.next = &num4;
	num4.next = &num5;

	printList(num1);

	cout << endl << "RUN FINISHED;";
	return 0;
}