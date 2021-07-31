#pragma once
#include <string>
#include <vector>

struct Car
{
    std::string name{""};
    std::string model{""};
    std::string country{""};
    int year{0};
    int hp{0};
    int price{0};
};

struct Node
{
    Car *data{nullptr};
    Node *left{nullptr};
    Node *right{nullptr};

    Node() : data(new Car){};
    Node(Car *obj) : data(obj){};
};

void insert(Node *&root, Car *obj);
void print(Node *root, int space = 0);
int maxHeight(Node *root);
int countNodes(Node *root);
void sort(Node *root, std::vector<Car *> &vec, int &i);
Node *searchName(Node *root, const std::string &str);
void free(Node *&root);
void readFromFile(std::vector<Car *> &vec);
void clearVec(std::vector<Car *> &vec);