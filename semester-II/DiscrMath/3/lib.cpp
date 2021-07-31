#include <iostream>
#include "lib.h"

void enterGraph(t_list *&adjLists, const int V)
{
    std::cout << "Enter two -1 when you want to end entering edges for current vertex!\n";
    for (int i = 0; i < V; ++i)
    {
        int t_dst = 0;
        int t_w = 0;
        while (t_dst != -1 && t_w != -1)
        {
            std::cout << "Vertex " << i << ": ";
            std::cin >> t_dst >> t_w;
            if (t_dst != -1 && t_w != -1)
            {
                addEdge(adjLists, i, t_dst, t_w);
            }
        }
    }
}

void addEdge(t_list *&adjLists, int src, int dst, int w)
{
    adjLists[src].push_back(std::make_pair(dst, w));
}

void printAdjLists(t_list *&adjLists, const int V)
{
    std::cout << "\nAdjacency List Graph Representation:"
              << "\n";
    for (int i = 0; i < V; ++i)
    {
        if (adjLists[i].size() == 0)
        {
            std::cout << i << " -> NULL";
        }
        else
        {
            std::cout << i;
        }
        for (auto j = adjLists[i].begin(); j != adjLists[i].end(); ++j)
        {
            std::cout << " -> " << j->first << "(" << j->second << ")";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void listToMatrix(t_list *&adjLists, t_vec2D &weightArray, const int V)
{
    for (int i = 0; i < V; ++i)
    {
        t_vec1D tmp(V, 0);
        weightArray.push_back(tmp);
    }

    for (int i = 0; i < V; ++i)
    {
        for (auto it = adjLists[i].begin(); it != adjLists[i].end(); ++it)
        {
            int src = i;
            int dst = it->first;
            int w = it->second;
            weightArray[src][dst] = w;
        }
    }
}

void printDisplayArray(t_vec2D &displayArray, const int V)
{
    std::cout << "\n";
    for (size_t i = 0; i < displayArray.size(); ++i)
    {
        for (size_t j = 0; j < displayArray[i].size(); ++j)
        {
            if (displayArray[i][j] == INT_MAX)
            {
                std::cout << "\u221E"
                          << "\t";
            }
            else
            {
                std::cout << displayArray[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Ford Algorithm

void fillLabels(t_vec2D &weightArray, t_vec2D &displayArray, t_vec1D &labels, const int V)
{
    labels[0] = 0;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if ((labels[j] - labels[i]) >= weightArray[i][j] && weightArray[i][j] != 0)
            {
                labels[j] = labels[i] + weightArray[i][j];
                displayArray[i][j] = labels[j];
            }
        }
    }
}

int _minElementFord(t_vec2D &displayArray, const int V, int current)
{
    int min = INT_MAX;
    for (int j = 0; j < V; ++j)
    {
        if (min > displayArray[j][current] && displayArray[j][current] != 0)
        {
            min = displayArray[j][current];
        }
    }
    return min;
}

void pathsReconstructFord(int current, t_vec2D &displayArray, const int V, t_vec1D &vecPath)
{
    if (current == 0)
    {
        printFordPaths(vecPath, V);
        vecPath.pop_back();
        return;
    }
    else
    {
        int min = _minElementFord(displayArray, V, current);
        for (int i = 0; i < V; ++i)
        {
            if (displayArray[i][current] == min)
            {
                vecPath.push_back(i);
                pathsReconstructFord(i, displayArray, V, vecPath);
            }
        }
        if (current != V - 1)
        {
            vecPath.pop_back();
        }
    }
}

void printFordPaths(t_vec1D &vecPath, const int V)
{
    for (auto it = vecPath.rbegin(); it != vecPath.rend(); ++it)
    {
        std::cout << *it;
        std::cout << " -> ";
    }
    std::cout << V - 1;
    std::cout << std::endl;
}

// Bellman-Collab Algorithm

void fillBellmanArray(t_vec2D &weightArray, t_vec2D &displayArray, const int V)
{
    t_vec1D tmp;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (i == j)
            {
                displayArray[i][j] = 0;
            }
            else if (weightArray[i][j] != 0)
            {
                displayArray[i][j] = weightArray[i][j];
            }
            else
            {
                displayArray[i][j] = INT_MAX;
            }
            if (j == V - 1)
            {
                tmp.push_back(displayArray[i][j]);
            }
        }
    }
    displayArray.push_back(tmp);
    int count = 1;

    while (count < 4)
    {
        _addVec(displayArray, V);
        count++;
    }
    while (!_cmpVecs(displayArray, V))
    {
        _addVec(displayArray, V);
        count++;
    }
}

void _addVec(t_vec2D &displayArray, const int V)
{
    static int countVec = 0;
    static int num_vec = V;
    int vec_idx = V + countVec + 2;
    displayArray.resize(vec_idx);
    t_vec1D tmp;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (displayArray[i][j] == 0)
            {
                continue;
            }
            else
            {
                tmp.push_back(displayArray[i][j] + displayArray[num_vec][j]);
            }
        }
        if (i != V - 1)
        {
            int min = _minElementBellman(tmp);
            displayArray[vec_idx - 1].push_back(min);
        }
        else
        {
            displayArray[vec_idx - 1].push_back(0);
        }
        tmp.clear();
    }
    num_vec++;
    countVec++;
}

int _minElementBellman(t_vec1D &vec)
{
    int min = INT_MAX;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (min > vec[i] && vec[i] > 0)
        {
            min = vec[i];
        }
    }
    return min;
}

bool _cmpVecs(t_vec2D &displayArray, const int V)
{
    size_t sz = displayArray.size();
    for (int i = 0; i < V; ++i)
    {
        if (displayArray[sz - 1][i] != displayArray[sz - 2][i])
        {
            return false;
        }
    }
    return true;
}

void pathsReconstructBellman(t_vec2D &displayArray, const int V, int cur, t_vec1D &vec)
{
    int sz = displayArray.size();
    if (cur == V - 1)
    {
        printBellmanPaths(vec);
        vec.pop_back();
        return;
    }
    else
    {
        for (int i = 0; i < V; ++i)
        {
            if (displayArray[sz - 1][cur] - displayArray[sz - 1][i] == displayArray[cur][i] && cur != i)
            {
                vec.push_back(i);
                pathsReconstructBellman(displayArray, V, i, vec);
            }
        }
        if (cur != 0)
        {
            vec.pop_back();
        }
    }
}

void printBellmanPaths(t_vec1D &vec)
{
    std::cout << "0";
    std::cout << " -> ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1)
        {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

void printMenu()
{
    std::cout << "\n"
              << "        "
              << "      Menu" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "| 1. Enter Graph              |" << std::endl;
    std::cout << "| 2. Ford Algorithm           |" << std::endl;
    std::cout << "| 3. Bellman-Collab Algorithm |" << std::endl;
    std::cout << "| 4. Exit                     |" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

void init(t_vec2D &displayArray, t_vec1D &labels, const int V)
{
    for (int i = 0; i < V; ++i)
    {
        t_vec1D tmp(V, INT_MAX);
        displayArray.push_back(tmp);
        labels[i] = INT_MAX;
    }
}