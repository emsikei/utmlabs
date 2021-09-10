#include <iostream>

class Vector
{
public:
    int norm(const Vector &data);
    void init(unsigned int size);
    void clear();
    int pop();
    void push(int val);
    void print();

private:
    int idx{0};
    unsigned int _size{0};
    int * _list;
};

int main()
{
    Vector vec;
    vec.init(6);

    vec.push(1);    
    vec.push(2);    
    vec.push(3);    
    vec.push(4);    
    vec.push(5);

    vec.print();    

    vec.clear();
}

int Vector::norm(const Vector & data) {
    int sum = 0;

    for (int i = 0; i < _size; ++i) {
        sum += _list[i];
    }

    return sum;
}

void Vector::init(unsigned int size) {
    _list = new int[size];
    for (int i = 0; i < size; ++i) {
        _list[i] = 0;
    }
    this->_size = size;
}

void Vector::clear() {
    delete [] _list;
    this->_size = 0;
}

int Vector::pop() {
    int * tmpArr = new int[_size - 1];
    for (int i = 0; i < _size - 1; ++i) {
        tmpArr[i] = _list[i];
    }
    int poppedElement = _list[_size - 1];

    delete [] _list;
    _list = tmpArr;

    this->_size--;

    return poppedElement;
}

void Vector::push(int val) {
    _list[idx] = val;
    ++idx;
    // this->_size++;
}

void Vector::print() {
    for (int i = 0; i < _size; ++i) {
        std::cout << _list[i] << "\t";
    }
}