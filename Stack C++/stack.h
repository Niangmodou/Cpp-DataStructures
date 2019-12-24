#include <iostream>

template<typename T>
class Stack{
	friend std::ostream& operator<<(std::ostream&, const Stack&);
public:
	Stack(int capacity = 1);

	~Stack();

	size_t size() const;

	bool empty();

	void push(T val);

	T pop();

	T top();

private:
	T* data;
	size_t mySize;
	size_t capacity;
};