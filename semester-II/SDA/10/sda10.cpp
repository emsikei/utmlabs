#include <iostream>
#include "lib.h"

int main()
{
    std::vector<Car *> vec;
    readFromFile(vec);
    Node *root = nullptr;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        insert(root, vec[i]);
    }

    int i = 0;
    sort(root, vec, i);
    for (size_t i = 0; i != vec.size(); ++i)
    {
        if (i != vec.size() - 1)
        {
            std::cout << vec[i]->name << ", ";
        } else {
            std::cout << vec[i]->name;
        }
    }

    std::cout << "\n";
    int height = maxHeight(root);
    std::cout << "The Height of the BST is: " << height << "\n";
    int count = countNodes(root);
    std::cout << "The BST has " << count << " nodes"
              << "\n";

    Node *tmp = searchName(root, "Lada");
    if (tmp != nullptr)
    {
        std::cout << tmp->data->price << "\n";
    }

    print(root);
    free(root);
    clearVec(vec);
    tmp = nullptr;
    return 0;
}
