#include <algorithm>
#include <iostream>

struct Vector
{
    unsigned int _size{0};
    int *_list{nullptr};
    // переменная _list должна быть массивом/списком из элементов типа int;
};

int norm(Vector &data);
void init(Vector &data, unsigned int size);
void clear(Vector &data);
int pop(Vector &data);
void push(Vector &data, int val);

bool cmp(int left, int right)
{
    return left < right;
}

int main(void)
{
    Vector v;
    unsigned int size = 0;
    std::cin >> size;
    int push_val = 0;
    std::cin >> push_val;

    init(v, size);
    for (size_t i = 0; i < v._size; i++)
    {
        std::cin >> v._list[i];
    }

    push(v, push_val);

    for (size_t i = 0; i < v._size; i++)
    {
        std::cout << v._list[i] << " ";
    }

    // укажите начало и конец списка в соответствии с вашей реализацией
    std::sort(v._list, v._list + v._size, cmp);

    std::cout << pop(v) << " ";

    for (size_t i = 0; i < v._size; i++)
    {
        std::cout << v._list[i] << " ";
    }

    std::cout << norm(v) << " ";

    clear(v);

    std::cout << norm(v);
}

int norm(Vector &data)
{
    int sum = 0;
    for (int i = 0; i < data._size; ++i)
    {
        sum += data._list[i];
    }
    return sum;
}

void init(Vector &data, unsigned int size)
{
    data._list = new int[size];
    data._size = size;
}

void clear(Vector &data)
{
    delete[] data._list;
    data._size = 0;
    data._list = nullptr;
}

int pop(Vector &data)
{
    Vector new_vec;
    init(new_vec, --data._size);
    for (int i = 0; i < data._size; ++i)
    {
        new_vec._list[i] = data._list[i];
    }
    int popped = data._list[data._size];
    clear(data);
    data = new_vec;
    return popped;
}

void push(Vector &data, int val)
{
    Vector new_vec;
    init(new_vec, ++data._size);
    for (int i = 0; i < data._size - 1; ++i)
    {
        new_vec._list[i] = data._list[i];
    }
    new_vec._list[data._size - 1] = val;
    clear(data);
    data = new_vec;
}