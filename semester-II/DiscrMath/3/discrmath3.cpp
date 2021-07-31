#include <iostream>
#include "lib.h"

/* 
    Enter graph: 
    Vertex i: to weight
    Vertex i: -1 -1

    ------------------------
    i.e. a graph
    ------------------------
    0 1 6
    0 2 8
    0 4 12
    1 2 2
    1 3 6
    2 3 5
    2 4 4
    2 6 8
    3 4 7
    3 5 7
    3 7 10
    4 5 5
    4 6 4
    4 7 8
    5 7 6
    6 7 4

    ------------------------
    will look like: 
    ------------------------
    Vertex 0: 1 6
    Vertex 0: 2 8
    Vertex 0: 4 12
    Vertex 0: -1 -1
    Vertex 1: 2 2
    Vertex 1: 3 6
    Vertex 1: -1 -1
    Vertex 2: 3 5
    Vertex 2: 4 4
    Vertex 2: 6 8
    Vertex 2: -1 -1
    Vertex 3: 4 7
    Vertex 3: 5 7
    Vertex 3: 7 10
    Vertex 3: -1 -1
    Vertex 4: 5 5
    Vertex 4: 6 4
    Vertex 4: 7 8
    Vertex 4: -1 -1
    Vertex 5: 7 6
    Vertex 5: -1 -1
    Vertex 6: 7 4
    Vertex 6: -1 -1
    Vertex 7: -1 -1
 */

int main()
{
    int V = 0;
    std::cout << "Enter the amount of vertices: ";
    std::cin >> V;
    while (V <= 1)
    {
        std::cout << "The amount of vertices must be bigger then 1. Try again: ";
        std::cin >> V;
    }
    t_list *adjLists = new t_list[V];
    t_vec1D labels(V, INT_MAX);
    t_vec2D weightArray, displayArray;
    t_vec1D vecPath;
    printMenu();
    int choice = 0;
    std::cout << "What to want to do? ";
    std::cin >> choice;
    while (choice <= 0 || choice > 4)
    {
        std::cout << "Please enter valid number: 1, 2, 3 or 4 - ";
        std::cin >> choice;
    }

    bool isGraph = false;
    while (1)
    {
        if (choice == 1)
        {
            enterGraph(adjLists, V);
            listToMatrix(adjLists, weightArray, V);
            printAdjLists(adjLists, V);
            isGraph = true;
        }
        else if (choice == 2)
        {
            if (!isGraph)
            {
                std::cout << "Enter a graph first: \n";
                enterGraph(adjLists, V);
                listToMatrix(adjLists, weightArray, V);
                printAdjLists(adjLists, V);
                isGraph = true;
            }
            displayArray.clear();
            init(displayArray, labels, V);
            fillLabels(weightArray, displayArray, labels, V);
            printDisplayArray(displayArray, V);
            std::cout << "\nlmin(" << 0 << "-" << V << ") = " << labels[V - 1] << "\n";
            std::cout << "\n";
            pathsReconstructFord(V - 1, displayArray, V, vecPath);
        }
        else if (choice == 3)
        {
            if (!isGraph)
            {
                std::cout << "Enter a graph first: \n";
                enterGraph(adjLists, V);
                listToMatrix(adjLists, weightArray, V);
                printAdjLists(adjLists, V);
                isGraph = true;
            }
            displayArray.clear();
            init(displayArray, labels, V);
            fillBellmanArray(weightArray, displayArray, V);
            printDisplayArray(displayArray, V);
            int sz = displayArray.size();
            std::cout << "\nlmin(" << 0 << "-" << V << ") = " << displayArray[sz - 1][0] << "\n";
            pathsReconstructBellman(displayArray, V, 0, vecPath);
        }
        printMenu();
        std::cout << "What do you want to do next? ";
        std::cin >> choice;

        if (choice == 4)
        {
            return 0;
        }
    }
    return 0;
}