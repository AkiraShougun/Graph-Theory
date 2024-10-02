#include <iostream>
#include <vector>
#include <map>

struct Graph
{
    std::vector<std::vector<int>> matrix;
    int n;
    int EdgeNumber;

    Graph(int n)
    {
        this->n = n;
        matrix.resize(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
        }
        EdgeNumber = 0;
    }

    void addVertex()
    {
        n++;
        matrix.resize(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
        }
    }

    void addEdge(int u, int v)
    {
        if (u >= n || v >= n)
        {
            return;
        }
        matrix[u][v]++;
        matrix[v][u]++;
        EdgeNumber++;
    }

    void removeEdge(int u, int v)
    {
        if (matrix[u][v] > 0)
        {
            matrix[u][v]--;
            matrix[v][u]--;
            EdgeNumber--;
        }
    }

    bool isEdge(int u, int v)
    {
        return matrix[u][v] > 0;
    }

    int H_1()
    {
        return EdgeNumber - n + 1;
    }

    int degree(int u)
    {
        int deg = 0;
        for (int i = 0; i < n; i++)
        {
            deg += matrix[u][i];
        }
        return deg;
    }

    bool isEulerianCycle()
    {
        for (int i = 0; i < n; i++)
        {
            if (degree(i) % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }

    void adjMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::map<int, std::vector<int>> AdjList()
    {
        std::map<int, std::vector<int>> adjList;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] > 0)
                {
                    adjList[i].push_back(j);
                }
            }
        }
        return adjList;
    }

    ~Graph()
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i].clear();
        }
        matrix.clear();
    }
};

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

bool isIsomorphic(Graph *g, Graph *h)
{
    if (g->n != h->n)
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