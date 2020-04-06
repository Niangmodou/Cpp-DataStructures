#include <iostream>
#include <string>

struct Item{
	Item();
	Item(int, const std::string&);
	int key;
	std::string value;
};

class ArrayMap{
	friend std::ostream& operator<<(std::ostream&, const ArrayMap&);
public:
	ArrayMap(int capacity = 1);

	~ArrayMap();

	bool empty();

	std::string find(int);

	bool erase(int);

	void insert(int, const std::string&);
private:
	void resize(size_t);

	Item* data;
	size_t capacity;
	size_t size;
};
