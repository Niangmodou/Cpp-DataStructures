

template<typename T>
Vector<int>::Vector() {
    theSize = 0;
    theCapacity = 1;
    data = new int[theCapacity];
}

template<typename T>
Vector<int>::~Vector() {
    delete [] data;
}

template<typename T>
Vector<int>::Vector(const Vector& rhs) {
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
    data = new int[theCapacity];

    for (size_t index = 0; index < theSize; ++index) {
        data[index] = rhs.data[index];
    }

}

template<typename T>
Vector& Vector<int>::operator=(const Vector& rhs) {
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

template<typename T>
void Vector<int>::push_back(int val) {
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

template<typename T>
size_t Vector<int>::size() const { return theSize; }

template<typename T>
void Vector<int>::pop_back() { --theSize; }

template<typename T>
void Vector<int>::clear() {
    theSize = 0;
}

template<typename T>
int Vector<int>::operator[](size_t index) const { return data[index]; }

template<typename T>
int& Vector<int>::operator[](size_t index) { return data[index]; }

template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& rhs){
	for(size_t i = 0; i < rhs.size(); ++i){
		cout << rhs[i] << " " <<;
	}
	os << endl;
	return os;
}





