#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace STL{
	class List {
		friend std::ostream& operator<<(std::ostream&, const List&);
	private:
		struct Node{
			Node(int data = 0, Node* next = nullptr, Node* prev = nullptr);
			int data;
			Node* next;
			Node* prev;
		};

		List::Node* header;
		List::Node* trailer;
		size_t currSize;
	public:
		//Task 5
		class Iterator{
			friend bool operator==(const List::Iterator&,const List::Iterator&);

			friend bool operator!=(const List::Iterator&,const List::Iterator&);
		public:
			Iterator(Node*);

			Iterator(const Iterator&);

			Iterator& operator++();

			Iterator& operator--();

			int operator*();

			Node* getNode();

		private:
			Node* nodePtr;
		};
		//Task 1
		List();

		void push_back(int);

		void pop_back();

		int& front();

		int& back();

		int front() const;

		int back() const;

		size_t size() const;

		bool empty() const;

		//Task 2
		void push_front(int);

		void pop_front();

		//Task 3
		void clear();

		//Task 4
		int operator[](size_t) const;

		int& operator[](size_t);

		//Task 5
		Iterator begin();

		Iterator end();

		//Task 6
		Iterator insert(Iterator, int);

		//Task 7
		Iterator erase(Iterator);

		// //Task 8
		~List();

		List(const List&);

		List& operator=(const List&);
	};

}

#endif