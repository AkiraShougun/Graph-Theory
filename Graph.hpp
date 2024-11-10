#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <vector>

struct Graph
{
    std::vector<std::vector<int>> matrix;
    int VertexNumber;
    int EdgeNumber;

    Graph(int n);
    void addVertex();
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool isEdge(int u, int v);
    int H_1();
    int degree(int u);
    bool isEulerianCycle();
    void printGraph();
    std::map<int, std::vector<int>> AdjList();
};

Graph completeGraph(int n);
Graph cycleGraph(int n);
Graph starGraph(int n);
bool isIsomorphic(Graph *g, Graph *h);
#endif // GRAPH_HPP