#include <iostream>
#include <vector>

#include "core/Graph.hpp"
#include "io/CSVReader.hpp"
#include "algorithms/BFS.hpp"
#include "algorithms/DFS.hpp"
#include "algorithms/Dijkstra.hpp"

int main() {
    Graph graph;
    CSVReader reader;

    if (!reader.loadNodes("data/nodes.csv", graph)) {
        std::cout << "Failed to load nodes\n";
        return 1;
    }

    if (!reader.loadEdges("data/routes.csv", graph)) {
        std::cout << "Failed to load routes\n";
        return 1;
    }

    std::vector<int> bfsTraversal = BFS::traverse(graph, 1);

    std::cout << "BFS Traversal: ";

    for (int node : bfsTraversal)
        std::cout << node << " ";

    std::cout << '\n';

    std::vector<int> dfsTraversal = DFS::run(graph, 1);

    std::cout << "DFS Traversal: ";

    for (int node : dfsTraversal)
        std::cout << node << " ";

    std::cout << '\n';

    PathResult result =
        Dijkstra::shortestPath(graph, 1, 5);

    std::cout << "\nShortest Path (1 -> 5): ";

    for (int node : result.path)
        std::cout << node << " ";

    std::cout << '\n';

    std::cout << "Total Distance: "
              << result.totalDistance
              << '\n';

    return 0;
}