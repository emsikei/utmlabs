#pragma once
#include <string>

struct Car
{
    std::string name{""};
    std::string model{""};
    std::string country{""};
    int year{0};
    int hp{0};
    int price{0};

    Car(const std::string name = "", const std::string model = "", const std::string country = "", const int year = 0, const int hp = 0, const int price = 0) : name(name), model(model), country(country), year(year), hp(hp), price(price){};

    void clear();
};

struct Node
{
    Car *data{nullptr};
    Node *next{nullptr};

    Node() : data(new Car){};
    Node(Car *obj) : data(obj){};
    ~Node();

    void print();
};

struct list
{
    Node *head{nullptr};
    size_t size{0};

    list(){};
    ~list(); // при слиянии двух списков использовать l.clear() для списка, в котором происходило слияние

    void print();
    void push_front(Car *obj);
    void push_back(Car *obj);
    void find_name(const std::string &name);
    void pop(size_t pos);
    void pop_front();
    void pop_back();
    void insertAfter(size_t pos, Car *obj);
    void insertAt(size_t pos, Car *obj);
    void edit(size_t pos, Car *obj);
    void newNode(const std::string &t_name, const std::string &t_model, const std::string &t_country, int t_year, int t_hp, int t_price);
    void sort();
    void getAddress();
    void showSize();
    void calcLen();
    void clear();
};

void splitList(list &l1, list &l2);
void mergeList(list &l1, list &l2);
void readFromFile(list &l);
void writeToFile(list &l);