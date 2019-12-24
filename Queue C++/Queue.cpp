#include <iostream>
#include "Queue.h"

using namespace std;

template <typename T>
Queue<T>::Queue(size_t capacity) : capacity(capacity), mySize(0) {
	data = new T[capacity];
}

template <typename T>
Queue<T>::~Queue(){
	delete [] data;
}

template <typename T>
size_t Queue<T>::size() const {
	return mySize;
}

template <typename T>
bool Queue<T>::empty() const {
	return size() == 0;
}

template <typename T>
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

template <typename T>
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

template <typename T>
T Queue<T>::first() const {
	if(empty()){
		cerr << "Queue is Empty!" << endl;
		return -1;
	}
	return data[mySize - 1];
}

template <typename T>
ostream& operator<<(ostream& os, const Queue<T>& rhs){
	while(!rhs.empty()){
		os << rhs.pop() << " ";
	}
	os << endl;
	return os;
}














