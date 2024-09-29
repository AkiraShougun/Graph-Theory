#include <iostream>
#include <vector>

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

    void addEdge(int u, int v)
    {
        matrix[u][v]++;
        EdgeNumber++;
    }

    int HoleCount()
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

    bool IsEulerianCycle()
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

    void printGraph()
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

    ~Graph()
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i].clear();
        }
        matrix.clear();
    }
};

int main()
{
    int n = 9;
    Graph g(n);
    g.printGraph();
    return 0;
}
