#include <iostream>

class Vector {
public:
    Vector() {
        theSize = 0;
        theCapacity = 1;
        data = new int[theCapacity];
    }

    ~Vector() {
        delete [] data;
    }

    Vector(const Vector& rhs) {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];

        for (size_t index = 0; index < theSize; ++index) {
            data[index] = rhs.data[index];
        }

    }
    
    Vector& operator=(const Vector& rhs) {
        if (&rhs != this) {
            delete [] data;
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            data = new int[theCapacity];

            for (size_t index = 0; index < theSize; ++index) {
                data[index] = rhs.data[index];
            }

        }
        return *this;
    }

    void push_back(int val) {
        if (theSize == theCapacity) {
            // handle no room
            int* oldData = data;
            data = new int[2*theCapacity];
            for (size_t index = 0; index < theSize; ++index) {
                data[index] = oldData[index];
            }
            delete [] oldData;
            theCapacity *= 2;
        }

        data[theSize] = val;
        ++theSize;
    }

    size_t size() const { return theSize; }

    void pop_back() { --theSize; }
    
    void clear() {
        theSize = 0;
    }
    
    int operator[](size_t index) const { return data[index]; }

    int& operator[](size_t index) { return data[index]; }

    
private:
    size_t theSize;
    size_t theCapacity;
    int* data;
};