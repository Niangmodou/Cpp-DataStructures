#include <iostream>
#include <vector>
#include "Queue.h"

using namespace std;

template <class queueType>
Queue<queueType>::Queue(){
	this->frontInd = -1;
	this->numElems = 0;
}

template <class queueType>
Queue<queueType>::~Queue(){
	cout << "Queue Terminated :(" << endl;
}

template <class queueType>
int Queue<queueType>::length(){
	return this->numElems;
}

template <class queueType>
bool Queue<queueType>::is_empty(){
	bool empty = numElems == 0 ? true : false;
	return empty;
}

template <class queueType>
void Queue<queueType>::enqueue(queueType elem){
	queueData.push_back(elem);
	numElems++;
	frontInd = numElems - 1;
}

template <class queueType>
queueType Queue<queueType>::dequeue(){
	queueType val = queueData.at(frontInd);
	queueData.popBack();
	return val;
}

template <class queueType>
queueType Queue<queueType>::first(){
	return queueData.at(frontInd);
}

template <class queueType>
void Queue<queueType>::displayQueue(){
	for(int i = numElems-1; i >= 0; i--){
		cout << queueData.at(i) << endl;
	}
}
