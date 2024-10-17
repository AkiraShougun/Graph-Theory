# Graph.hpp Documentation

## Overview
The `Graph` class represents an undirected graph using an adjacency matrix. It provides methods to add vertices and edges, remove edges, check for edges, and perform various graph-related computations.

## Classes and Functions

### `Graph`
Represents an undirected graph.

#### Attributes
- `std::vector<std::vector<int>> matrix`: The adjacency matrix representing the graph.
- `int n`: The number of vertices in the graph.
- `int EdgeNumber`: The number of edges in the graph.

#### Methods

- **Constructor**
  - `Graph(int n)`: Initializes a graph with `n` vertices.

- **void addVertex()**
  - Adds a new vertex to the graph.

- **void addEdge(int u, int v)**
  - Adds an edge between vertices `u` and `v`.

- **void removeEdge(int u, int v)**
  - Removes the edge between vertices `u` and `v`.

- **bool isEdge(int u, int v)**
  - Checks if there is an edge between vertices `u` and `v`.

- **int H_1()**
  - Computes and returns the dimension of the first homology group of the graph.

- **int degree(int u)**
  - Returns the degree of vertex `u`.

- **bool isEulerianCycle()**
  - Checks if the graph contains an Eulerian cycle.

- **void adjMatrix()**
  - Prints the adjacency matrix of the graph.

- **std::map<int, std::vector<int>> AdjList()**
  - Returns the adjacency list representation of the graph.

- **Destructor**
  - `~Graph()`: Cleans up the graph.

### Global Functions

- **Graph completeGraph(int n)**
  - Creates and returns a complete graph with `n` vertices.

- **Graph cycleGraph(int n)**
  - Creates and returns a cycle graph with `n` vertices.

- **bool isIsomorphic(Graph *g, Graph *h)**
  - Checks if two graphs `g` and `h` are isomorphic.

## Usage
To use the graph data structure, include the `Graph.hpp` file in your project and create instances of `Graph`. Use the provided methods to manipulate the graph.

## Example
```cpp
#include "Graph.hpp"
#include <iostream>

int main() {
    Graph g = completeGraph(5);
    g.adjMatrix();
    return 0;
}