#include <iostream>

template<typename T>
class Queue{
	friend std::ostream& operator<<(std::ostream&, const Queue<T>&);
public:
	Queue(size_t capacity = 1);

	~Queue();

	size_t size() const;

	bool empty() const ;

	void enqueue(T val);

	T dequeue();

	T first() const;

private:
	int* data;
	size_t mySize;
	size_t capacity;
	int frontInd;

};
