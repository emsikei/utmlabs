#include <iostream>
#include "lib.h"

int main()
{
    int V;
    std::cout << "Enter the number of your graph's vertices: ";
    std::cin >> V;
    Graph g(V);

    int choice = 0;
    bool isGraph = false;
    while (choice != -1)
    {
        printMenu();
        std::cout << "Make your choice (press -1 to exit): ";
        std::cin >> choice;

        int strtV;

        if (choice == 1)
        {
            if (!isGraph)
            {
                isGraph = true;
                int dst;
                std::cout << "Enter -1 to end entering an adjacency list!"
                          << "\n";
                for (int i = 0; i < V; ++i)
                {
                    dst = 0;
                    while (dst != -1)
                    {
                        std::cout << "Vertex " << i << ": ";
                        std::cin >> dst;
                        g.addEdge(i, dst);
                    }
                }

                std::cout << std::endl;
                std::cout << "Your graph: " << std::endl;
                g.printAdjLists();
            }
            else
            {
                std::cout << "You have already entered the graph. Do you want to enter another one? Press 1 to do so or press -1 to exit: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    g.~Graph();
                    std::cout << "Enter the number of your graph's vertices: ";
                    std::cin >> V;
                    Graph g(V);
                    isGraph = false;

                    int dst;
                    std::cout << "Enter -1 to end entering an adjacency list!"
                              << "\n";
                    for (int i = 0; i < V; ++i)
                    {
                        dst = 0;
                        while (dst != -1)
                        {
                            std::cout << "Vertex " << i << ": ";
                            std::cin >> dst;
                            g.addEdge(i, dst);
                        }
                    }

                    std::cout << std::endl;
                    std::cout << "Your graph: " << std::endl;
                    g.printAdjLists();
                }
                else if (choice == -1)
                {
                    return 0;
                }
            }
        }
        else if (choice == 2)
        {
            if (isGraph)
            {
                std::cout << "Enter start vertex for DFS: ";
                std::cin >> strtV;
                while (strtV < 0)
                {
                    std::cout << "Start vertex must be >= 0: ";
                    std::cin >> strtV;
                }
                g.DFS(strtV);
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You haven't entered the graph yet. Press 1 to do it or press -1 to exit the program: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    isGraph = true;
                    int dst;
                    std::cout << "Enter -1 to end entering an adjacency list!"
                              << "\n";
                    for (int i = 0; i < V; ++i)
                    {
                        dst = 0;
                        while (dst != -1)
                        {
                            std::cout << "Vertex " << i << ": ";
                            std::cin >> dst;
                            g.addEdge(i, dst);
                        }
                    }

                    std::cout << std::endl;
                    std::cout << "Your graph: " << std::endl;
                    g.printAdjLists();
                }
                else if (choice == -1)
                {
                    return 0;
                }
            }
        }

        else if (choice == 3)
        {
            if (isGraph)
            {
                std::cout << "Enter start vertex for BFS: ";
                std::cin >> strtV;
                while (strtV < 0)
                {
                    std::cout << "Start vertex must be >= 0: ";
                    std::cin >> strtV;
                }
                g.BFS(strtV);
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You haven't entered the graph yet. Press 1 to do it or press -1 to exit the program: ";
                std::cin >> choice;
                if (choice == 1)
                {
                    isGraph = true;
                    int dst;
                    std::cout << "Enter -1 to end entering an adjacency list!"
                              << "\n";
                    for (int i = 0; i < V; ++i)
                    {
                        dst = 0;
                        while (dst != -1)
                        {
                            std::cout << "Vertex " << i << ": ";
                            std::cin >> dst;
                            g.addEdge(i, dst);
                        }
                    }

                    std::cout << std::endl;
                    std::cout << "Your graph: " << std::endl;
                    g.printAdjLists();
                }
                else if (choice == -1)
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}


