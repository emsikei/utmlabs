#include <iostream>
#include <fstream>
#include "lib.h"

void Node::print()
{
    std::cout << data->name << "\t" << data->model << "\t" << data->country << "\t" << data->year << "\t" << data->hp << "\t" << data->price << std::endl;
}

Node::~Node()
{
    delete data;
}

void list::print()
{
    size_t idx = 1;
    for (Node *tmp = head; tmp; tmp = tmp->next)
    {
        std::cout << idx << ". ";
        tmp->print();
        std::cout << std::endl;
        idx++;
    }
}

void list::push_front(Car *obj)
{
    Node *tmp = head;
    head = new Node(obj);
    head->next = tmp;
    size++;
    return;
}

void list::push_back(Car *obj)
{
    Node *tmp = new Node(obj);
    Node *last = head;
    tmp->next = nullptr;
    if (head == nullptr)
    {
        head = tmp;
        return;
    }
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = tmp;
    size++;
    return;
}

void list::find_name(const std::string &name)
{
    while (head->data->name != name)
    {
        head = head->next;
    }
    std::cout << head->data->name << "\t" << head->data->model << "\t" << head->data->country << "\t" << head->data->year << "\t" << head->data->hp << "\t" << head->data->price << std::endl;
}

void list::edit(size_t pos, Car *obj)
{
    Node *cur = head;
    Node *tmp = new Node(obj);

    if (pos == 0)
    {
        head = tmp;
        head->next = cur;
    }
    else
    {
        size_t count = 1;
        while (count != pos)
        {
            cur = cur->next;
            count++;
        }
        cur->data = tmp->data;
    }
}

void list::sort()
{
    Node *i, *j;
    i = head;

    for (i = head; i != nullptr; i = i->next)
    {
        for (j = i->next; j != nullptr; j = j->next)
        {
            if (i->data->price > j->data->price)
            {
                std::swap(i->data, j->data);
            }
        }
    }
}

void list::pop(size_t pos)
{
    if (head == nullptr)
    {
        return;
    }

    Node *tmp = head;
    if (pos == 1)
    {
        head = tmp->next;
        delete tmp;
        return;
    }

    for (size_t i = 1; tmp != nullptr && i < pos - 1; ++i)
    {
        tmp = tmp->next;
    }
    if (tmp == nullptr || tmp->next == nullptr)
    {
        return;
    }
    Node *next = tmp->next->next;
    delete tmp->next;
    tmp->next = next;
    size--;
}

void list::pop_front()
{
    if (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    size--;
}

void list::pop_back()
{

    if (head == nullptr)
    {
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
    }

    Node *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (second_last->next);
    second_last->next = nullptr;
    size--;
}

void list::insertAfter(size_t pos, Car *obj)
{
    Node *cur = head;
    Node *tmp = new Node(obj);

    if (pos == 0)
    {
        head = tmp;
        head->next = cur;
    }
    else
    {
        size_t count = 1;
        while (count != pos)
        {
            cur = cur->next;
            count++;
        }
        tmp->next = cur->next;
        cur->next = tmp;
    }
    size++;
}

void list::insertAt(size_t pos, Car *obj)
{
    Node *cur = head;
    Node *tmp = new Node(obj);

    if (pos == 0)
    {
        head = tmp;
        head->next = cur;
    }
    else
    {
        size_t count = 1;
        while (count != (pos - 1))
        {
            cur = cur->next;
            count++;
        }
        tmp->next = cur->next;
        cur->next = tmp;
    }
    size++;
}

void list::getAddress()
{
    while (head->next != nullptr)
    {
        head = head->next;
    }
    std::cout << head << std::endl;
}

void list::showSize()
{
    std::cout << size << std::endl;
}

void splitList(list &l1, list &l2)
{
    Node *slow, *fast;
    if (l1.head->next == nullptr)
    {
        return;
    }

    slow = fast = l1.head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    l2.head = slow->next;
    slow->next = nullptr;
    l1.calcLen();
    l2.calcLen();
}

void mergeList(list &l1, list &l2)
{
    Node *tmp = l1.head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = l2.head;
    l1.calcLen();
}

list::~list()
{
    while (head)
    {
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void list::clear()
{
    while (head)
    {
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void list::calcLen()
{
    size_t count = 0;
    Node *cur = head;
    while (cur != nullptr)
    {
        cur = cur->next;
        count++;
    }
    size = count;
}

void readFromFile(list &l)
{
    std::ifstream file;
    std::string line;
    file.open("SDA\\89\\cars.csv");
    if (!file.is_open())
    {
        return;
    }

    l.size = 1;
    size_t p = 0, start = 0;
    const std::string delim = "\",\n";
    std::string str;
    std::string t_name = "";
    std::string t_model = "";
    std::string t_country = "";
    int t_year = 0, t_hp = 0, t_price = 0;
    while (getline(file, line, '\n'))
    {
        if (!line.find("Name"))
            continue;
        size_t len = line.length();
        start = line.find_first_not_of(delim, p);
        p = line.find_first_of(delim, start);
        while (p != std::string::npos)
        {
            str = line.substr(start, p - start);
            if (t_name == "")
            {
                t_name = str;
            }
            else if (t_model == "")
            {
                t_model = str;
            }
            else if (t_country == "")
            {
                t_country = str;
            }
            else if (t_year == 0)
            {
                t_year = std::stoi(str);
            }
            else if (t_hp == 0)
            {
                t_hp = std::stoi(str);
            }
            start = line.find_first_not_of(delim, p);
            p = line.find_first_of(delim, start);
        }
        if (len > start) //rest
        {
            str = line.substr(start, len - start);
            if (t_price == 0)
            {
                t_price = std::stoi(str);
            }
        }
        p = 0, start = 0;
        l.newNode(t_name, t_model, t_country, t_year, t_hp, t_price);
        t_name = "";
        t_model = "";
        t_country = "";
        t_year = 0, t_hp = 0, t_price = 0;
    }
    file.close();
}

void list::newNode(const std::string &t_name, const std::string &t_model, const std::string &t_country, int t_year, int t_hp, int t_price)
{
    Node *tmp = new Node();
    tmp->data->name = t_name;
    tmp->data->model = t_model;
    tmp->data->country = t_country;
    tmp->data->year = t_year;
    tmp->data->hp = t_hp;
    tmp->data->price = t_price;
    tmp->next = nullptr;
    Node *last = head;
    if (head == nullptr)
    {
        head = tmp;
        return;
    }

    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = tmp;
    size++;
}

void writeToFile(list &l)
{
    std::ofstream file;
    file.open("SDA\\89\\cars.csv", std::ios::app);
    if (!file.is_open())
    {
        return;
    }
    std::string str;
    std::string t_name = "";
    std::string t_model = "";
    std::string t_country = "";
    int t_year = 0, t_hp = 0, t_price = 0;

    if (l.head == nullptr)
    {
        return;
    }
    Node *cur = l.head;
    while (cur->next != nullptr)
    {
        t_name = cur->data->name;
        t_model = cur->data->model;
        t_country = cur->data->country;
        t_year = cur->data->year;
        t_hp = cur->data->hp;
        t_price = cur->data->price;
        file << t_name << "," << t_model << "," << t_country << "," << t_year << "," << t_hp << "," << t_price << std::endl;
        cur = cur->next;
    }
    file.close();
}

void Car::clear()
{
    name = "";
    model = "";
    country = "";
    year = 0;
    hp = 0;
    price = 0;
} 