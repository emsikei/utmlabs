// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<int> adjList[], int s, int d)
{
    adjList[s].push_back(d);
}

// Print the graph
void printAdjList(vector<int> adjList[], int V)
{
    for (int d = 0; d < V; ++d)
    {
        cout << d + 1;
        for (auto x : adjList[d])
            cout << " -> " << x + 1;
        printf("\n");
    }
}

int main()
{
    int V = 4, E = 6;

    // Create a graph
    vector<int> adjList[V];

    // Add edges

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 3, 2); 

    vector<vector<int>> adjMat;
    vector<vector<int>> incMat;

    // init adj matrix to 0
    /* for (int i = 0; i < V; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            tmp.push_back(0);
        }
        adjMat.push_back(tmp);
    } */

    // list to adj matrix
    /* for (int i = 0; i < V; ++i)
    {
        int k;
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            k = adjList[i][j];
            adjMat[i][k] = 1;
        }
    } */

    // input the adj matrix

    int num = 0;
    /* for (int i = 0; i < V; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            cin >> num;
            tmp.push_back(num);
        }
        adjMat.push_back(tmp);
    }

    // adj mat to list
    for (int i = 0; i < adjMat.size(); ++i)
    {
        for (int j = 0; j < adjMat[i].size(); ++j)
        {
            if (adjMat[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }

    // printing the adj matrix
    cout << '\t';
    for (int k = 0; k < V; ++k)
    {
        cout << "x" << k + 1 << '\t';
    }
    cout << endl;

    for (int i = 0; i < adjMat.size(); i++)
    {
        cout << "x" << i + 1 << '\t';
        for (int j = 0; j < adjMat[i].size(); j++)
        {
            cout << " " << adjMat[i][j] << '\t';
        }
        cout << endl;
    } */

    // input the incedence matrix

   /*  for (int i = 0; i < E; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < V; ++j)
        {
            cin >> num;
            tmp.push_back(num);
        }
        incMat.push_back(tmp);
    }
 */
    /* // printing the incedence matrix
    cout << '\t';
    for (int k = 0; k < V; ++k)
    {
        cout << "x" << k + 1 << '\t';
    }
    cout << endl;

    for (int i = 0; i < incMat.size(); i++)
    {
        cout << "e" << i + 1 << '\t';
        for (int j = 0; j < incMat[i].size(); j++)
        {
            cout << " " << incMat[i][j] << '\t';
        }
        cout << endl;
    }

    // incMat to adjList
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
    } */

    // adjList to incMat
/*     int q = 0;
    for (int i = 0; i < V; ++i)
    {
        int k;
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            k = adjList[i][j];
            incMat[i][k] = 1;
        }
        if (q < E)
        {
            ++q;
        }
    } */

    // 
    vector <vector<int>> edge_mat;
    for (int i = 0; i < V; ++i) {
        vector <int> tmp;
        for (int j = 0; j < adjList[i].size(); ++j) {
            tmp.push_back(adjList[i][j]);
        }
    }

    printAdjList(adjList, V);
}