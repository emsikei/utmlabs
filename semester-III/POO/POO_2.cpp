#include <iostream>
#include <vector>

class Vector
{
    unsigned int _size;
    // _list; реализация списка целых чисел
    int *_list;
public:
    Vector() // default ctor
    {
        // реализация здесь
        std::cout << "default ctor ";
        _list = nullptr;
        _size = 0;
    }
    ~Vector() // dtor
    {
        // реализация здесь
        std::cout << "dtor ";
        delete[] _list;
        _list = nullptr;
        _size = 0;
    }

    Vector(const unsigned int size, const int val = 0) // parametric ctor
    {
        std::cout << "param ctor ";
        // реализация здесь
        this->_size = size;
        this->_list = new int[size]{val};
        for (int i = 0; i < size; ++i)
        {
            this->_list[i] = val;
        }
    }

    Vector(const Vector &other) : _size(other._size) // copy ctor
    {
        std::cout << "copy ctor ";
        // реализация здесь
        this->_list = new int[other._size];

        for (int i = 0; i < _size; ++i)
        {
            this->_list[i] = other._list[i];
        }
    }

    Vector(Vector &&other) noexcept // move ctor
    {
        std::cout << "move ctor ";
        // реализация здесь
        this->_size = other._size;
        this->_list = new int[other._size];
        for (int i = 0; i < _size; ++i)
        {
            this->_list[i] = other._list[i];
        }

        other._size = 0;
        delete [] other._list;
        other._list = nullptr;
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Vector &obj)
    {
        for (unsigned int i = 0; i < obj._size; i++)
        {
            os << obj._list[i] << " ";
        }

        return os;
    }
};

int main(int argc, char const *argv[])
{
    int x, y, z;

    std::cin >> x >> y >> z;

    Vector a;

    std::cout << a << " ";

    Vector b(x);

    std::cout << b << " ";

    Vector c(std::move(b));

    std::cout << c << " " << b << " ";

    Vector d(Vector(y, z));

    std::cout << d << " ";

    Vector e = d;

    std::cout << d;

    return 0;
}

// 5 4 7 
//* Expected: default ctor  param ctor 0 0 0 0 0  move ctor 0 0 0 0 0   param ctor 7 7 7 7  copy ctor 7 7 7 7 dtor dtor dtor dtor dtor 

// 6 6 6
//* Expected:  default ctor  param ctor 0 0 0 0 0 0  move ctor 0 0 0 0 0 0   param ctor 6 6 6 6 6 6  copy ctor 6 6 6 6 6 6 dtor dtor dtor dtor dtor

// 3 4 99
//* Expected: default ctor  param ctor 0 0 0  move ctor 0 0 0   param ctor 99 99 99 99  copy ctor 99 99 99 99 dtor dtor dtor dtor dtor