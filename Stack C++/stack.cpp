#include <iostream>

template<typename T>
Stack::Stack(int capacity = 1) : mySize(0), capacity(capacity){
	data = new T[capacity];

}

Stack::~Stack(){
	delete [] data;
}

size_t Stack::size() const {
	return mySize;
}

bool Stack::empty(){
	return mySize == 0;
}

void Stack::push(T val){
	if(mySize == capacity){
		T* old = data;
		data = new T[2*capacity];
		for(size_t i = 0; i < mySize; ++i){
			data[i] = old[i];
		} 
		delete [] old;
		capacity*=2;
	}
	data[mySize] = val;
	++mySize;
}

T Stack::pop(){
	if(empty()){
		cerr << "Stack is Empty!" << endl;
		return -1;
	}
	T val = data[mySize-1];
	--mySize;
	return val;
}

T Stack::top(){
	if(empty()){
		cerr << "STACK EMPTY;" << endl;
		return -1;
	}
	return data[mySize-1];
}

ostream& operator<<(ostream& os, const Stack& rhs){
	while(!rhs.empty()){
		os << rhs.pop() << " ";
	}
	os << endl;
	return os;
}
