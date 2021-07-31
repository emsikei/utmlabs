#include <iostream>
#include "lib.h"

int main()
{
    int V = 0;
    int E = 0;
    while (V <= 0)
    {
        std::cout << "Num of Vertices: ";
        std::cin >> V;
    }

    while (E <= 0)
    {
        std::cout << "Num of Edges: ";
        std::cin >> E;
    }
    t_vec1D adjList[V];
    t_vec2D adjMat;
    t_vec2D incMat;
    short int choice = 0;

    printStartMenu();
    while (choice < 1 || choice > 3)
    {
        std::cout << "Choose between these three options: ";
        std::cin >> choice;
    }

    std::cout << std::endl;
    bool isGraph = false;
    if (choice == 1)
    {
        isGraph = true;
        printInputMenu();
        std::cout << "Choose between these three options: ";
        std::cin >> choice;
        while (choice < 1 || choice > 3)
        {
            std::cout << "Enter valid option: ";
            std::cin >> choice;
        }

        if (choice == 1)
        {
            fillAdjMat(adjMat, V);
            adjMatToList(adjMat, adjList);
            initIncMat(incMat, V, E);
            adjMatToIncMat(adjMat, incMat, V);
        }
        else if (choice == 2)
        {
            fillAdjList(adjList, E);
            initAdjMat(adjMat, V);
            listToAdjMat(adjList, adjMat, V);
            initIncMat(incMat, V, E);
            listToIncMat(adjList, incMat, V);
        }
        else if (choice == 3)
        {
            fillIncMat(incMat, V, E);
            incMatToList(incMat, adjList, V, E);
            initAdjMat(adjMat, V);
            incMatToAdjMat(incMat, adjMat, V, E);
        }

        printStartMenu();
        std::cout << "Choose what do want to do next. You can either display your graph or exit the program." << std::endl;
        std::cout << "Choose between these two options (2 or 3): ";
        std::cin >> choice;
        while (choice != 2 && choice != 3)
        {
            std::cout << "Enter valid option: ";
            std::cin >> choice;
        }

        if (choice == 2)
        {
            do
            {
                printOutputMenu();
                std::cout << "Choose between these three options: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    printAdjMat(adjMat, V);
                }
                else if (choice == 2)
                {
                    printAdjList(adjList, V);
                }
                else if (choice == 3)
                {
                    printIncMat(incMat, V, E);
                }
            } while (choice == 1 || choice == 2 || choice == 3);
        }
        else if (choice == 3)
        {
            return 1;
        }
    }
    else if (choice == 2)
    {
        if (isGraph)
        {
            do
            {
                printOutputMenu();
                std::cout << "Choose between these three options: ";
                std::cin >> choice;
                while (choice != 1 && choice != 2 && choice != 3)
                {
                    std::cout << "Enter valid option: ";
                    std::cin >> choice;
                }

                if (choice == 1)
                {
                    printAdjMat(adjMat, V);
                }
                else if (choice == 2)
                {
                    printAdjList(adjList, V);
                }
                else if (choice == 3)
                {
                    printIncMat(incMat, V, E);
                }
            } while (choice == 1 || choice == 2 || choice == 3);
        }
        else
        {
            std::cout << "You need to enter your graph before you can display it!" << std::endl;
            std::cout << "You can either enter your graph or exit the program. Choose 1 or 3: ";
            std::cin >> choice;
            while (choice != 1 && choice != 3)
            {
                std::cout << "Enter valid option: ";
                std::cin >> choice;
            }
            if (choice == 1)
            {
                printInputMenu();
                std::cout << "Choose between these three options: ";
                std::cin >> choice;
                while (choice < 1 || choice > 3)
                {
                    std::cout << "Enter valid option: ";
                    std::cin >> choice;
                }

                if (choice == 1)
                {
                    fillAdjMat(adjMat, V);
                    adjMatToList(adjMat, adjList);
                    initIncMat(incMat, V, E);
                    adjMatToIncMat(adjMat, incMat, V);
                }
                else if (choice == 2)
                {
                    fillAdjList(adjList, E);
                    initAdjMat(adjMat, V);
                    listToAdjMat(adjList, adjMat, V);
                    initIncMat(incMat, V, E);
                    listToIncMat(adjList, incMat, V);
                }
                else if (choice == 3)
                {
                    fillIncMat(incMat, V, E);
                    incMatToList(incMat, adjList, V, E);
                    initAdjMat(adjMat, V);
                    incMatToAdjMat(incMat, adjMat, V, E);
                }

                printStartMenu();
                std::cout << "Choose what do want to do next. You can either display your graph or exit the program." << std::endl;
                std::cout << "Choose between these two options (2 or 3): ";
                std::cin >> choice;
                while (choice != 2 && choice != 3)
                {
                    std::cout << "Enter valid option: ";
                    std::cin >> choice;
                }

                if (choice == 2)
                {
                    do
                    {
                        printOutputMenu();
                        std::cout << "Choose between these three options: ";
                        std::cin >> choice;
                        if (choice == 1)
                        {
                            printAdjMat(adjMat, V);
                        }
                        else if (choice == 2)
                        {
                            printAdjList(adjList, V);
                        }
                        else if (choice == 3)
                        {
                            printIncMat(incMat, V, E);
                        }
                    } while (choice == 1 || choice == 2 || choice == 3);
                }
                else if (choice == 3)
                {
                    return 1;
                }
            }
            else if (choice == 3)
            {
                return 1;
            }
        }
    }
    else if (choice == 3)
    {
        return 1;
    }
}

