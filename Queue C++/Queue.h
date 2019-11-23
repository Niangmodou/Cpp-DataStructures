#include <vector>


template <class queueType>
class Queue{
private:
	std::vector<queueType> queueData;
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