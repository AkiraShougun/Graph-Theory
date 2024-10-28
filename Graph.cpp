#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <map>

// Constructor
Graph::Graph(int n)
{
    this->VertexNumber = n;
    matrix.resize(n);
    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(n);
    }
    EdgeNumber = 0;
}

// Add a vertex
void Graph::addVertex()
{
    VertexNumber++;
    matrix.resize(VertexNumber);
    for (int i = 0; i < VertexNumber; i++)
    {
        matrix[i].resize(VertexNumber);
    }
}

// Add an edge between u and v
void Graph::addEdge(int u, int v)
{
    if (u >= VertexNumber || v >= VertexNumber)
    {
        return;
    }
    matrix[u][v]++;
    matrix[v][u]++;
    EdgeNumber++;
}

// Remove an edge between u and v..
void Graph::removeEdge(int u, int v)
{
    if (matrix[u][v] > 0)
    {
        matrix[u][v]--;
        matrix[v][u]--;
        EdgeNumber--;
    }
}

// Check if there is an edge between u and v
bool Graph::isEdge(int u, int v)
{
    return matrix[u][v] > 0;
}

int Graph::H_1()
{
    return EdgeNumber - VertexNumber + 1;
}

// Degree
int Graph::degree(int u)
{
    int deg = 0;
    for (int i = 0; i < VertexNumber; i++)
    {
        deg += matrix[u][i];
    }
    return deg;
}

// Eulerian Cycle
bool Graph::isEulerianCycle()
{
    for (int i = 0; i < VertexNumber; i++)
    {
        if (degree(i) % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

// Print.
void Graph::printGraph()
{
    for (int i = 0; i < VertexNumber; i++)
    {
        for (int j = 0; j < VertexNumber; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Adjacency List
std::map<int, std::vector<int>> Graph::AdjList()
{
    std::map<int, std::vector<int>> adjList;
    for (int i = 0; i < VertexNumber; i++)
    {
        for (int j = 0; j < VertexNumber; j++)
        {
            if (matrix[i][j] > 0)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

Graph::~Graph()
{
    for (int i = 0; i < VertexNumber; i++)
    {
        matrix[i].clear();
    }
    matrix.clear();
}

Graph completeGraph(int n)
{
    Graph g(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i != j)
            {
                g.addEdge(i, j);
            }
        }
    }
    return g;
}

Graph cycleGraph(int n)
{
    Graph g(n);
    for (int i = 0; i < n; i++)
    {
        g.addEdge(i, (i + 1) % n);
    }
    return g;
}

Graph starGraph(int n)
{
    Graph g(n);
    for (int i = 1; i < n; i++)
    {
        g.addEdge(0, i);
    }
    return g;
}

bool isIsomorphic(Graph *g, Graph *h)
{
    if (g->VertexNumber != h->VertexNumber)
    {
        return false;
    }
    if (g->EdgeNumber != h->EdgeNumber)
    {
        return false;
    }
    if (g->H_1() != h->H_1())
    {
        return false;
    }
    if (g->isEulerianCycle() != h->isEulerianCycle())
    {
        return false;
    }
    return true;
};
