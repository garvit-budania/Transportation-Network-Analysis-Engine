#include <iostream>
#include <vector>

#include "core/Graph.hpp"
#include "io/CSVReader.hpp"
#include "algorithms/BFS.hpp"
#include "algorithms/DFS.hpp"
#include "algorithms/Dijkstra.hpp"
#include "algorithms/AStar.hpp"

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
        std::cout << graph.getNodeName(node) << " ";

    std::cout << "\n";

    std::vector<int> dfsTraversal = DFS::run(graph, 1);

    std::cout << "DFS Traversal: ";

    for (int node : dfsTraversal)
        std::cout << graph.getNodeName(node) << " ";

    std::cout << "\n\n";

    PathResult dijkstraResult =
        Dijkstra::shortestPath(graph, 1, 5);

    std::cout << "Dijkstra Route:\n";

    for (size_t i = 0; i < dijkstraResult.path.size(); i++) {
        std::cout << graph.getNodeName(dijkstraResult.path[i]);

        if (i != dijkstraResult.path.size() - 1)
            std::cout << " -> ";
    }

    std::cout << "\n";
    std::cout << "Total Distance: "
              << dijkstraResult.totalDistance
              << " km\n\n";

    PathResult aStarResult =
        AStar::shortestPath(graph, 1, 5);

    std::cout << "A* Route:\n";

    for (size_t i = 0; i < aStarResult.path.size(); i++) {
        std::cout << graph.getNodeName(aStarResult.path[i]);

        if (i != aStarResult.path.size() - 1)
            std::cout << " -> ";
    }

    std::cout << "\n";
    std::cout << "Total Distance: "
              << aStarResult.totalDistance
              << " km\n";

    return 0;
}