#include <iostream>
#include <fstream>
#include "Graph.hpp"

void createGraph(Graph &g, std::string filename, std::string params)
{
    std::ofstream file;
    file.open(filename);
    file << "graph G {\n";
    file << params << "\n";
    file << "node [shape=circle];\n";
    // Print all vertices.....
    for (int i = 0; i < g.VertexNumber; i++)
    {
        file << i << ";\n";
    }
    // Print all edges......
    for (int i = 0; i < g.VertexNumber; i++)
    {
        for (int j = i; j < g.VertexNumber; j++)
        {
            if (g.isEdge(i, j))
            {
                file << i << " -- " << j << ";\n";
            }
        }
    }
    file << "}";
}

int main()
{
    Graph g = completeGraph(4);

    std::cout << "H_1 = " << g.H_1() << std::endl;
    // createGraph(g, "graph.dot", "layout=circo");
    // system("dot -Tpng graph.dot -o graph.png");
    return 0;
}