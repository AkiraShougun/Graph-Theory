#include <iostream>
#include <fstream>
#include "graph.hpp"

void createGraph(Graph &g, std::string filename, std::string params)
{
    std::ofstream file;
    file.open(filename);
    file << "graph G {\n";
    file << params << "\n";
    file << "node [shape=circle];\n";
    // Print all vertices
    for (int i = 0; i < g.n; i++)
    {
        file << i << ";\n";
    }
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (g.matrix[i][j] > 0)
            {
                file << i << " -- " << j << "\n";
            }
        }
    }
    file << "}";
    file.close();
}

int main()
{
    Graph g = completeGraph(50);

    // std::cout << "H_1 = " << g.H_1() << std::endl;
    createGraph(g, "graph.dot", "layout=circo");
    system("dot -Tpng graph.dot -o graph.png");
    return 0;
}