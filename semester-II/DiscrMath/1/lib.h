#pragma once
#include <vector>

typedef std::vector<std::vector<int>> t_vec2D;
typedef std::vector<int> t_vec1D;


void initAdjMat(t_vec2D &adjMat, int V);
void fillAdjMat(t_vec2D &adjMat, int V);
void printAdjMat(t_vec2D adjMat, int V);
void adjMatToList(t_vec2D adjMat, t_vec1D adjList[]);
void listToAdjMat(t_vec1D adjList[], t_vec2D &adjMat, int V);
void adjMatToIncMat(t_vec2D adjMat, t_vec2D &incMat, int V);
void initIncMat(t_vec2D &incMat, int V, int E);
void fillIncMat(t_vec2D &incMat, int V, int E);
void printIncMat(t_vec2D incMat, int V, int E);
void incMatToList(t_vec2D incMat, t_vec1D adjList[], int V, int E);
void listToIncMat(t_vec1D adjList[], t_vec2D &incMat, int V);
void incMatToAdjMat(t_vec2D incMat, t_vec2D &adjMat, int V, int E);
void fillAdjList(t_vec1D adjList[], int E);
void addEdge(t_vec1D adjList[], int start_v, int end_v);
void printAdjList(t_vec1D adjList[], int V);
void printStartMenu();
void printInputMenu();
void printOutputMenu();