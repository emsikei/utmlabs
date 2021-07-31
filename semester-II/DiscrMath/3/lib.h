#pragma once
#include <vector>
#include <list>

typedef std::vector<std::vector<int>> t_vec2D;
typedef std::vector<int> t_vec1D;
typedef std::list<std::pair<int, int>> t_list;

void enterGraph(t_list *&adjLists, const int V);
void addEdge(t_list *&adjLists, int src, int dst, int w);
void printAdjLists(t_list *&adjLists, const int V);
void listToMatrix(t_list *&adjLists, t_vec2D &weightArray, const int V);
void printDisplayArray(t_vec2D &displayArray, const int V);

void printMenu();
void init(t_vec2D &displayArray, t_vec1D &labels, const int V);

// Ford Algorithm
void fillLabels(t_vec2D &weightArray, t_vec2D &displayArray, t_vec1D &labels, const int V);
void pathsReconstructFord(int current, t_vec2D &displayArray, const int V, t_vec1D &vec);
int _minElementFord(t_vec2D &displayArray, const int V, int current);
void printFordPaths(t_vec1D &vecPath, const int V);

// Bellman-Collab Algorithm
void fillBellmanArray(t_vec2D &weightArray, t_vec2D &displayArray, const int V);
void pathsReconstructBellman(t_vec2D &displayArray, const int V, int cur, t_vec1D &vec);
void printBellmanPaths(t_vec1D &vecPath);
void _addVec(t_vec2D &displayArray, const int V);
int _minElementBellman(t_vec1D &vec);
bool _cmpVecs(t_vec2D &displayArray, const int V);


