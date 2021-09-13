#include <iostream>

class Vector
{
    unsigned int _size;
    int *_list;
    // _list; реализация списка целых чисел
public:
    ~Vector() // dtor
    {
        // реализация здесь
        delete[] _list;
        _list = nullptr;
        _size = 0;
    }

    Vector() // default ctor
    {
        // реализация здесь
        _list = nullptr;
        _size = 0;
    }

    Vector(const unsigned int size, const int val = 0) // parametric ctor
    {
        // реализация здесь
        this->_size = size;
        this->_list = new int[size]{val};
        for (int i = 0; i < size; ++i)
        {
            _list[i] = val;
        }
    }

    Vector(const Vector &other) // copy ctor
    {
        // реализация здесь
        this->_list = new int[other._size];
        for (int i = 0; i < _size; ++i)
        {
            _list[i] = other._list[i];
        }
    }

    Vector(Vector &&other) noexcept // move ctor
    {
        // реализация здесь
        this->_size = other._size;
        this->_list = new int[other._size];
        for (int i = 0; i < _size; ++i)
        {
            this->_list[i] = other._list[i];
        }

        other._size = 0;
        delete[] other._list;
        other._list = nullptr;
    }

    Vector &operator=(const Vector &other)
    {
        // реализация здесь

        //* Скопировать всё из other в this

        if (this->_list)
        {
            delete[] _list;
            _list = nullptr;
        }

        this->_size = other._size;
        this->_list = new int[other._size];
        for (int i = 0; i < _size; ++i)
        {
            this->_list[i] = other._list[i];
        }

        return *this;
    }

    Vector &operator=(Vector &&other) noexcept
    {
        // реализация здесь

        if (this->_list)
        {
            delete[] _list;
            _list = nullptr;
        }

        this->_size = other._size;
        this->_list = new int[other._size];
        for (int i = 0; i < _size; ++i)
        {
            this->_list[i] = other._list[i];
        }

        other._size = 0;
        delete[] other._list;
        other._list = nullptr;

        return *this;
    }

    const int &operator[](std::size_t idx) const
    {
        // реализация здесь
        return _list[idx];
    }

    int &operator[](std::size_t idx)
    {
        // реализация здесь
        return _list[idx];
    }

    Vector &operator+=(const Vector &rhs)
    {
        // реализация здесь

        Vector tmp;
        tmp._size = this->_size + rhs._size;
        tmp._list = new int[tmp._size];

        int j = 0;

        for (int i = 0; i < this->_size; ++i)
        {
            tmp[j] = this->_list[i];
            j++;
        }

        for (int i = 0; i < rhs._size; ++i)
        {
            tmp[j] = rhs._list[i];
            j++;
        }

        delete[] this->_list;
        this->_list = tmp._list;

        return *this;
    }

    friend Vector operator+(Vector lhs, const Vector &rhs)
    {
        // реализация здесь
        Vector tmp;
        return tmp;
    }

    Vector operator--(int)
    {
        // реализация здесь
        return;
    }

    friend std::istream &operator>>(std::istream &is, Vector &obj)
    {
        // реализация здесь
        return is;
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

int main()
{

    return 0;
}