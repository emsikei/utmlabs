#pragma once
#include <list>

enum status
{
    UNKNOWN,
    DISCOVERED,
    VISITED,
};

struct Graph
{
    int numVertices;
    status *visited;
    std::list<int> *adjLists;
    Graph(int vertices);
    ~Graph();
    void addEdge(int src, int dst);
    void printAdjLists();
    void DFS(int strt);
    void BFS(int strt);
};

void printMenu();