#include <iostream>
#include <vector>

#include "lib.h"

void initAdjMat(t_vec2D &adjMat, int V)
{
    for (int i = 0; i < V; ++i)
    {
        t_vec1D tmp;
        for (int j = 0; j < V; ++j)
        {
            tmp.push_back(0);
        }
        adjMat.push_back(tmp);
    }
}

void fillAdjMat(t_vec2D &adjMat, int V)
{
    int num = 0;
    for (int i = 0; i < V; ++i)
    {
        std::cout << "Enter row " << i + 1 << ": ";
        t_vec1D tmp;
        for (int j = 0; j < V; ++j)
        {
            std::cin >> num;
            tmp.push_back(num);
        }
        adjMat.push_back(tmp);
    }
}

void printAdjMat(t_vec2D adjMat, int V)
{
    std::cout << '\t';
    for (int k = 0; k < V; ++k)
    {
        std::cout << "x" << k + 1 << '\t';
    }
    std::cout << std::endl;
    for (int i = 0; i < V; i++)
    {
        std::cout << "x" << i + 1 << '\t';
        for (int j = 0; j < V; j++)
        {
            std::cout << " " << adjMat[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void adjMatToList(t_vec2D adjMat, t_vec1D adjList[]) // adj mat to list
{
    for (size_t i = 0; i < adjMat.size(); ++i)
    {
        for (size_t j = 0; j < adjMat[i].size(); ++j)
        {
            if (adjMat[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
}

void listToAdjMat(t_vec1D adjList[], t_vec2D &adjMat, int V)
{
    for (int i = 0; i < V; ++i)
    {
        int k;
        for (size_t j = 0; j < adjList[i].size(); ++j)
        {
            k = adjList[i][j];
            adjMat[i][k] = 1;
        }
    }
}

void adjMatToIncMat(t_vec2D adjMat, t_vec2D &incMat, int V)
{
    t_vec2D edge_mat;
    for (int i = 0; i < V; ++i)
    {
        t_vec1D tmp;
        for (int j = 0; j < V; ++j)
        {
            if (adjMat[i][j] == 1)
            {
                tmp.push_back(i);
                tmp.push_back(j);
                edge_mat.push_back(tmp);
                tmp.clear();
            }
        }
    }

    int start_v, end_v;
    for (size_t i = 0; i < edge_mat.size(); ++i)
    {
        start_v = edge_mat[i][0];
        end_v = edge_mat[i][1];
        incMat[i][start_v] = -1;
        incMat[i][end_v] = 1;
    }
}

void initIncMat(t_vec2D &incMat, int V, int E)
{
    for (int i = 0; i < E; ++i)
    {
        t_vec1D tmp;
        for (int j = 0; j < V; ++j)
        {
            tmp.push_back(0);
        }
        incMat.push_back(tmp);
    }
}

void fillIncMat(t_vec2D &incMat, int V, int E)
{
    int num = 0;
    for (int i = 0; i < E; ++i)
    {
        std::cout << "Enter row " << i + 1 << ": ";
        t_vec1D tmp;
        for (int j = 0; j < V; ++j)
        {
            std::cin >> num;
            tmp.push_back(num);
        }
        incMat.push_back(tmp);
    }
}

void printIncMat(t_vec2D incMat, int V, int E)
{
    std::cout << '\t';
    for (int k = 0; k < V; ++k)
    {
        std::cout << "x" << k + 1 << '\t';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < incMat.size(); i++)
    {
        std::cout << "e" << i + 1 << '\t';
        for (size_t j = 0; j < incMat[i].size(); j++)
        {
            std::cout << " " << incMat[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void incMatToList(t_vec2D incMat, t_vec1D adjList[], int V, int E)
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            if (incMat[j][i] == -1)
            {
                for (int k = 0; k < V; ++k)
                {
                    if (incMat[j][k] == 1)
                    {
                        adjList[i].push_back(k);
                    }
                }
            }
        }
    }
}

void incMatToAdjMat(t_vec2D incMat, t_vec2D &adjMat, int V, int E)
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            if (incMat[j][i] == -1)
            {
                for (int k = 0; k < V; ++k)
                {
                    if (incMat[j][k] == 1)
                    {
                        adjMat[i][k] = 1;
                    }
                }
            }
        }
    }
}

void listToIncMat(t_vec1D adjList[], t_vec2D &incMat, int V)
{
    t_vec2D edge_mat;
    for (int i = 0; i < V; ++i)
    {
        t_vec1D tmp;
        for (size_t j = 0; j < adjList[i].size(); ++j)
        {
            tmp.push_back(i);
            tmp.push_back(adjList[i][j]);
            edge_mat.push_back(tmp);
            tmp.clear();
        }
    }

    int start_v, end_v;
    for (size_t i = 0; i < edge_mat.size(); ++i)
    {
        start_v = edge_mat[i][0];
        end_v = edge_mat[i][1];
        incMat[i][start_v] = -1;
        incMat[i][end_v] = 1;
    }
}

void fillAdjList(t_vec1D adjList[], int E)
{
    int start_v = 0, end_v = 0;
    std::cout << "All the input is needed to be done with whitespaces!!! You have " << E << " edges." << std::endl;
    for (int i = 0; i < E; ++i)
    {
        std::cout << "Enter edge " << i + 1 << ": ";
        std::cin >> start_v >> end_v;
        addEdge(adjList, start_v - 1, end_v - 1);
    }
}

void addEdge(t_vec1D adjList[], int start_v, int end_v)
{
    adjList[start_v].push_back(end_v);
}

void printAdjList(t_vec1D adjList[], int V)
{
    for (int i = 0; i < V; ++i)
    {
        std::cout << "Vertex " << i + 1;
        for (auto x : adjList[i])
        {
            std::cout << " -> " << x + 1;
        }
        std::cout << std::endl;
    }
}

void printStartMenu()
{
    std::cout << '\n'
         << "     "
         << "Start Menu" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "| 1. Enter Graph   |" << std::endl;
    std::cout << "| 2. Display Graph |" << std::endl;
    std::cout << "| 3. Exit          |" << std::endl;
    std::cout << "--------------------" << std::endl;
}

void printInputMenu()
{
    std::cout << '\n'
         << '\t' << "Input Menu" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "| 1. Enter Adjacency Matrix |" << std::endl;
    std::cout << "| 2. Enter Adjacency List   |" << std::endl;
    std::cout << "| 3. Enter Incidence Matrix |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

void printOutputMenu()
{
    std::cout << '\n'
         << '\t' << "Output Menu" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "| 1. Display Adjacency Matrix |" << std::endl;
    std::cout << "| 2. Display Adjacency List   |" << std::endl;
    std::cout << "| 3. Display Incidence Matrix |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}