#include <iostream>
#include <fstream>

#define COUNT 10

#include "lib.h"

void insert(Node *&root, Car *obj)
{
    if (!root)
    {
        root = new Node(obj);
        return;
    }

    if (obj->name > root->data->name)
    {
        insert(root->right, obj);
    }
    else
    {
        insert(root->left, obj);
    }
}

void print(Node *root, int space)
{
    if (!root)
        return;
    space += COUNT;
    print(root->right, space);
    for (int i = COUNT; i < space; i++)
    {
        std::cout << "\t";
    }
    std::cout << root->data->name << "\n";
    print(root->left, space);
}

void sort(Node *root, std::vector<Car *> &vec, int &i)
{
    if (!root)
    {
        return;
    }
    sort(root->left, vec, i);
    vec[i++] = root->data;
    sort(root->right, vec, i);
}

int maxHeight(Node *root)
{
    if (!root)
        return 0;
    else
    {
        int lHeight = maxHeight(root->left);
        int rHeight = maxHeight(root->right);

        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}

int countNodes(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void readFromFile(std::vector<Car *> &vec)
{
    std::ifstream file;
    std::string line;
    file.open("SDA/10/cars.csv");
    if (!file.is_open())
    {
        std::cout << "Couldn't open the file!"
                  << "\n";
        return;
    }

    size_t p = 0, start = 0;
    const std::string delim = "\",\n";
    std::string str;
    while (getline(file, line, '\n'))
    {

        Car *tmp = new Car();
        if (!line.find("Name"))
            continue;
        size_t len = line.length();
        start = line.find_first_not_of(delim, p);
        p = line.find_first_of(delim, start);
        while (p != std::string::npos)
        {
            str = line.substr(start, p - start);
            if (tmp->name == "")
            {
                tmp->name = str;
            }
            else if (tmp->model == "")
            {
                tmp->model = str;
            }
            else if (tmp->country == "")
            {
                tmp->country = str;
            }
            else if (tmp->year == 0)
            {
                tmp->year = std::stoi(str);
            }
            else if (tmp->hp == 0)
            {
                tmp->hp = std::stoi(str);
            }
            start = line.find_first_not_of(delim, p);
            p = line.find_first_of(delim, start);
        }
        if (len > start)
        {
            str = line.substr(start, len - start);
            if (tmp->price == 0)
            {
                tmp->price = std::stoi(str);
            }
        }
        vec.push_back(tmp);
        p = 0, start = 0;
    }
    file.close();
}

Node *searchName(Node *root, const std::string & str)
{
    if (!root)
        return nullptr;

    if (str < root->data->name)
    {
        return searchName(root->left, str);
    }
    else if (str > root->data->name)
    {
        return searchName(root->right, str);
    }
    return root;
}

void free(Node *&root)
{
    if (!root)
    {
        return;
    }
    free(root->left);
    free(root->right);
    delete root;
    root = nullptr;
}

void clearVec(std::vector<Car *> &vec) {
    for (auto T : vec) {
        delete T;
    }
    vec.clear();
}

