#include <iostream>

template<typename T>
class Vector {
    friend std::ostream& operator<<(std::ostream&, const Vector<T>);
public:
    Vector();

    ~Vector();

    Vector(const Vector& rhs);
    
    Vector& operator=(const Vector& rhs);

    void push_back(int val);

    size_t size() const;

    void pop_back();
    
    void clear();
    
    int operator[](size_t index) const;

    int& operator[](size_t index);

    
private:
    size_t theSize;
    size_t theCapacity;
    int* data;
};