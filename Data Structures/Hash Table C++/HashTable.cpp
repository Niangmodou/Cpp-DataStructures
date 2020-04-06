#include <iostream>
#include <string>
#include <exception>
#include "HashTable.h"

using namespace std;

Item::Item(){}

Item::Item(int key , const std::string& value) : 
	key(key), value(value){}

ArrayMap::ArrayMap(int capacity) : capacity(capacity),size(0) {
	Item* data = new Item[capacity];
}

ArrayMap::~ArrayMap(){
	delete [] data;
}

void ArrayMap::resize(size_t newCapacity){
	Item* oldData = data;
	Item* data = new Item[newCapacity];
	for(size_t index = 0; index < size; ++index){
		data[index] = oldData[index];
	}
	delete [] oldData;
	capacity = newCapacity;
}


bool ArrayMap::empty(){
	return size == 0;
}

string ArrayMap::find(int number){
	if(empty()){
		cerr << "Hash Table is Empty";
	}
	for(size_t index = 0; index < size; ++index){
		if(data[index].key == number){
			return data[index].value;
		}
	}
	return "NULL";
}

bool ArrayMap::erase(int number){
	if(empty()){
		cerr << "Hash Table is Empty";
	}
	for(size_t index = 0; index < size; ++index){
		if(data[index].key == number){
			data[index] = data[size - 1];
			return true;
		}
	}
	return false;
}

void ArrayMap::insert(int number, const string& name){
	//RESIZE
	if(size == capacity){
		resize(2*capacity);
	}
	for(size_t index = 0; index < size; ++index){
		if(data[index].key == number){
			data[index].value = name;
			return;
		}
	}
	Item newItem = Item(number,name);
	data[size] = newItem;
	++size;
}

ostream& operator<<(ostream& os, const ArrayMap& rhs){
	for(size_t index = 0; index < rhs.size; ++index){
		Item item = rhs.data[index];
		cout << item.value << ": " << item.key << endl;
	}
	return os;
}