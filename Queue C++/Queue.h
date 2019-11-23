#include <vector>

<<<<<<< HEAD
=======
using namespace std;
>>>>>>> a897570f3a7d6cde78adfe81957bdb726f6e8ce7

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
