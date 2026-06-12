#include <iostream>
#include <vector>

#include "core/Graph.hpp"
#include "io/CSVReader.hpp"
#include "algorithms/BFS.hpp"

int main() {
    Graph graph;
    CSVReader reader;

    reader.loadNodes("data/nodes.csv", graph);
    reader.loadEdges("data/routes.csv", graph);

    std::vector<int> traversal = BFS::traverse(graph, 1);

    std::cout << "BFS Traversal: ";

    for (int node : traversal)
        std::cout << node << " ";

    std::cout << '\n';

    return 0;
}