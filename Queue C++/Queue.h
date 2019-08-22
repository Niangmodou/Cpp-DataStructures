#include <iostream>
#include <vector>

using namespace std;

void func1();

template <class queueType>
class Queue{
private:
	vector<queueType> queueData;
	queueType frontInd;
	int numElems;

public:
	Queue();

	~Queue();

	int length();

	bool is_empty();

	void enqueue(queueType elem);

	queueType dequeue();

	queueType first();

	void displayQueue();
};