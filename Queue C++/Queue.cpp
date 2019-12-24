#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue(size_t capacity = 1) : capacity(capacity), mySize(0) {
	data = new T[capacity];
}

template <class T>
Queue<T>::~Queue(){
	delete [] data;
}

template <class T>
size_t Queue<T>::size() const {
	return mySize;
}

template <class T>
bool Queue<T>::empty(){
	return size() == 0;
}

template <class T>
void Queue<T>::enqueue(T val){
	if(mySize == capacity){ //Full
		T* old = data;
		data = new T[2*capacity];
		for(size_t i = 0; i < mySize; ++i){
			data[i] = old[i];
		} 
		delete [] old;
		capacity*=2;
	}
	if(empty()){
		data[0] = val;
		frontInd = 0;
		++mySize;
	}else{
		int backInd = (frontInd + mySize) % capacity;
		data[backInd] = val;
		++mySize;
	}

}

template <class T>
T Queue<T>::dequeue(){
	if(empty()){
		cerr << "Queue is Empty!" << endl;
		return -1;
	}
	T val = data[frontInd];
	data[frontInd] = nullptr;
	frontInd = (frontInd + 1) % capacity;
	--mySize;
	if(empty()){
		frontInd = nullptr;
	}
	return val;
}

template <class T>
T Queue<T>::first(){
	if(empty()){
		cerr << "Queue is Empty!" << endl;
		return -1;
	}
	return data[mySize - 1];
}

ostream& operator<<(ostream& os, const Queue& rhs){
	while(!rhs.empty()){
		os << rhs.pop() << " ";
	}
	os << endl;
	return os;
}














