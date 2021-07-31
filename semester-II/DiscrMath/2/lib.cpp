#include <iostream>
#include <stack>
#include <queue>
#include <list>

#include "lib.h"

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
}

Graph::~Graph() {
    delete [] adjLists;
}

void Graph::addEdge(int src, int dst)
{
    adjLists[src].push_back(dst);
}

void Graph::DFS(int strt)
{
    visited = new status[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = UNKNOWN;
    }
    std::stack<int> S;
    S.push(strt);
    while (!S.empty())
    {
        int curr = S.top();
        S.pop();
        if (visited[curr] == VISITED)
        {
            continue;
        }
        visited[curr] = VISITED;
        for (auto i = adjLists[curr].begin(); i != adjLists[curr].end(); ++i)
        {
            if (*i == -1)
            {
                break;
            }
            if (visited[*i] != VISITED)
            {
                S.push(*i);
            }
        }
        std::cout << curr << "\t";
    }
    delete[] visited;
}

void Graph::BFS(int strt)
{
    visited = new status[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = UNKNOWN;
    }
    std::queue<int> Q;
    Q.push(strt);

    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        visited[curr] = VISITED;

        for (auto i = adjLists[curr].begin(); i != adjLists[curr].end(); ++i)
        {
            if (*i == -1)
            {
                break;
            }
            if (visited[*i] == UNKNOWN)
            {
                Q.push(*i);
                visited[*i] = DISCOVERED;
            }
        }
        std::cout << curr << "\t";
    }
    delete[] visited;
}

void Graph::printAdjLists()
{
    for (int i = 0; i < numVertices; ++i)
    {
        std::cout << i;
        for (auto j = adjLists[i].begin(); j != adjLists[i].end(); ++j)
        {
            if (*j != -1)
            {
                std::cout << " -> " << *j;
            }
        }
        std::cout << std::endl;
    }
}

void printMenu()
{
    std::cout << "\n\n"
              << "        "
              << "Menu" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "| 1. Enter Graph   |" << std::endl;
    std::cout << "| 2. DFS           |" << std::endl;
    std::cout << "| 3. BFS           |" << std::endl;
    std::cout << "--------------------" << std::endl;
}
