#include <iostream>
#include "LinkedList.h"

using namespace std;

namespace STL{
	//Task 1
	List::List(){
		header = new Node();
		trailer = new Node();
		header->next = trailer;
		trailer->prev = header;
		currSize = 0;
	}

	void List::push_back(int data){
		List::Node* newNode = new List::Node(data);
		List::Node* prevNode = trailer->prev;

		prevNode->next = newNode;
		newNode->prev = prevNode;

		newNode->next = trailer;
		trailer->prev = newNode;

		++currSize;
	}

	void List::pop_back(){
		if(!empty()){
			List::Node* victim = trailer->prev;

			victim->prev->next = trailer;
			trailer->prev = victim->prev;

			delete victim;
			--currSize;
		}
	}

	int List::front() const{
		//if(!empty()){
			return header->next->data;
		//}
	}
	int List::back() const {
			return trailer->prev->data;
	}

	int& List::front(){
		return header->next->data;
	}

	int& List::back(){
		return trailer->prev->data;
	}

	size_t List::size() const {
		return currSize;
	}

	bool List::empty() const {
		return (currSize == 0);
	}

	List::Node::Node(int data, List::Node* next, List::Node* prev) :
		data(data), next(next), prev(prev){}

	ostream& operator<<(ostream& os, const List& rhs){
		const List::Node* p = rhs.header->next;
		while (p->next){
			os << p->data << " ";
			p = p->next;
		}
		os << endl;
		return os;
	}


	//TASK 2
	void List::push_front(int data){
		List::Node* newNode = new Node(data);
		List::Node* oldNode = header->next;

		header->next = newNode;
		newNode->prev = header;

		newNode->next = oldNode;
		oldNode->prev = newNode;

		++currSize;
	}

	void List::pop_front(){
		List::Node* victim = header->next;

		header->next = victim->next;
		victim->next-> prev = header;

		delete victim;
		--currSize;
	}

	//TASK 3
	void List::clear(){
		while (currSize){
        	pop_back();
    	}
    	currSize = 0;
	}

	// //TASK 4
	int List::operator[](size_t index) const {
	 	List::Node* p = header->next;
	 	for(size_t i = 0; i < index; ++i){
	 		p = p->next;
	 	}
	 	return p->data;
	 }

	int& List::operator[](size_t index) {
		List::Node* p = header->next;
		for(size_t i = 0; i < index; ++i){
			p = p->next;
		}
		return p->data;
	}


	// //TASK5 - ITERATOR
	List::Iterator List::begin() {
		return List::Iterator(header->next);
	}

	List::Iterator List::end() {
		return List::Iterator(trailer);
	}

	List::Iterator::Iterator(const Iterator& rhs) : 
		nodePtr(new Node(*rhs.nodePtr)){}

	bool operator==(const List::Iterator& lhs,const List::Iterator& rhs){
		return (lhs.nodePtr == rhs.nodePtr);
	}

	bool operator!=(const List::Iterator& lhs,const List::Iterator& rhs){
		return !(lhs == rhs);
	}

	List::Iterator::Iterator(Node* nodePtr) : nodePtr(nodePtr){}

	List::Iterator& List::Iterator::operator++(){
		if(nodePtr->next){
			nodePtr = nodePtr->next;
		}
		return *this;
	}

	List::Iterator& List::Iterator::operator--(){
		if(nodePtr->prev){
			nodePtr = nodePtr->prev;
		}
		return *this;
	}

	int List::Iterator::operator*(){
		if(nodePtr){
			return nodePtr->data;
		}
		return -1;	
	}

	//Task 6
	List::Node* List::Iterator::getNode(){
		return nodePtr;
	}

	List::Iterator List::insert(List::Iterator iter, int data){
		List::Node* newNode = new Node(data);
		List::Node* currNode = iter.getNode();
		List::Node* prevNode = currNode->prev;

		prevNode->next = newNode;
		newNode->prev = prevNode;

		newNode->next = currNode;
		currNode->prev = newNode;
		
		++currSize;
		return iter;

	}

		//Task 7
	List::Iterator List::erase(Iterator iter){
		List::Node* victim = iter.getNode();
		++iter;
		List::Node* nextNode = iter.getNode();
		--iter;
		--iter;
		List::Node* prevNode = iter.getNode();

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		++iter;
		++iter;
		--currSize;
		return iter;
	}

	List::~List(){
		
		clear();
		delete header;
		delete trailer;
		cout << "~List" << endl;
	}

	List::List(const List& rhs){
		cout << "List(const List& rhs)"<< endl;
		List::Node* currNode = rhs.header->next;
		header = new Node(*rhs.header);
		trailer = new Node(*rhs.trailer);
		header->next = trailer;
		trailer->prev = header;
		while(currNode){
			int val = currNode->data;
			push_back(val);
			currNode = currNode->next;
		}
		currSize=rhs.currSize;
	}

	List& List::operator=(const List& rhs){
		cout << "operator=(const List& rhs)" << endl;
		if(this != &rhs){
			clear();
			List::Node* currNode = rhs.header->next;
			while(currNode){
				int val = currNode->data;
				push_back(val);
				currNode = currNode->next;
			}
		}
		currSize = rhs.currSize;
		return *this;
	}


}











