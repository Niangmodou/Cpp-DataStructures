#include <iostream>

template<typename T>
Stack<T>::Stack(int capacity = 1) : mySize(0), capacity(capacity){
	data = new T[capacity];

}

template<typename T>
Stack<T>::~Stack(){
	delete [] data;
}

template<typename T>
size_t Stack<T>::size() const {
	return mySize;
}

template<typename T>
bool Stack<T>::empty(){
	return mySize == 0;
}

template<typename T>
void Stack<T>::push(T val){
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

template<typename T>
T Stack<T>::pop(){
	if(empty()){
		cerr << "Stack is Empty!" << endl;
		return -1;
	}
	T val = data[mySize-1];
	--mySize;
	return val;
}

template<typename T>
T Stack::top(){
	if(empty()){
		cerr << "STACK EMPTY;" << endl;
		return -1;
	}
	return data[mySize-1];
}

template<typename T>
ostream& operator<<(ostream& os, const Stack<T>& rhs){
	while(!rhs.empty()){
		os << rhs.pop() << " ";
	}
	os << endl;
	return os;
}
