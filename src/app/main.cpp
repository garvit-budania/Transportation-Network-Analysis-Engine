#include <iostream>

#include "core/Graph.hpp"
#include "io/CSVReader.hpp"

#include "algorithms/BFS.hpp"
#include "algorithms/DFS.hpp"
#include "algorithms/Dijkstra.hpp"
#include "algorithms/AStar.hpp"
#include "algorithms/Kruskal.hpp"
#include "algorithms/MaxFlow.hpp"
#include "algorithms/NetworkAnalyzer.hpp"
#include "algorithms/NetworkResilience.hpp"

void printRoute(
    const Graph& graph,
    const PathResult& result
) {
    for (size_t i = 0; i < result.path.size(); i++) {
        std::cout << graph.getNodeName(result.path[i]);

        if (i + 1 < result.path.size())
            std::cout << " -> ";
    }

    std::cout << "\n";
}

int main() {
    Graph graph(false);
    CSVReader reader;

    if (!reader.loadNodes("data/nodes.csv", graph) ||
        !reader.loadEdges("data/routes.csv", graph)) {
        std::cout << "Failed to load network data\n";
        return 1;
    }

    std::cout << "Network Statistics\n";
    std::cout << "------------------\n";

    std::cout << "Nodes: "
              << graph.nodeCount()
              << "\n";

    std::cout << "Edges: "
              << graph.edgeCount()
              << "\n";

    std::cout << "Connected Components: "
              << NetworkAnalyzer::connectedComponents(graph)
              << "\n";

    std::cout << "Average Degree: "
              << NetworkAnalyzer::averageDegree(graph)
              << "\n";

    std::cout << "Density: "
              << NetworkAnalyzer::networkDensity(graph)
              << "\n";

    int hubCity =
        NetworkAnalyzer::mostConnectedNode(graph);

    std::cout << "Most Connected City: "
              << graph.getNodeName(hubCity)
              << "\n";

    std::cout << "\nCritical Cities\n";
    std::cout << "---------------\n";

    auto criticalCities =
        NetworkResilience::articulationPoints(graph);

    if (criticalCities.empty()) {
        std::cout << "None\n";
    }
    else {
        for (int city : criticalCities)
            std::cout
                << graph.getNodeName(city)
                << "\n";
    }

    std::cout << "\nCritical Routes\n";
    std::cout << "---------------\n";

    auto criticalRoutes =
        NetworkResilience::bridges(graph);

    if (criticalRoutes.empty()) {
        std::cout << "None\n";
    }
    else {
        for (const auto& route : criticalRoutes) {
            std::cout
                << graph.getNodeName(route.first)
                << " - "
                << graph.getNodeName(route.second)
                << "\n";
        }
    }

    std::cout << "\n";

    std::cout << "BFS: ";

    for (int node : BFS::traverse(graph, 1))
        std::cout << graph.getNodeName(node) << " ";

    std::cout << "\n";

    std::cout << "DFS: ";

    for (int node : DFS::run(graph, 1))
        std::cout << graph.getNodeName(node) << " ";

    std::cout << "\n\n";

    auto shortestRoute =
        Dijkstra::shortestPath(
            graph,
            1,
            5,
            RouteMetric::Distance
        );

    std::cout << "Shortest Route (Distance)\n";

    printRoute(graph, shortestRoute);

    std::cout << "Distance: "
              << shortestRoute.totalWeight
              << " km\n\n";

    auto fastestRoute =
        Dijkstra::shortestPath(
            graph,
            1,
            5,
            RouteMetric::Time
        );

    std::cout << "Fastest Route (Time)\n";

    printRoute(graph, fastestRoute);

    std::cout << "Travel Time: "
              << fastestRoute.totalWeight
              << " hrs\n\n";

    auto cheapestRoute =
        Dijkstra::shortestPath(
            graph,
            1,
            5,
            RouteMetric::Cost
        );

    std::cout << "Cheapest Route (Cost)\n";

    printRoute(graph, cheapestRoute);

    std::cout << "Cost: "
              << cheapestRoute.totalWeight
              << "\n\n";

    auto heuristicRoute =
        AStar::shortestPath(graph, 1, 5);

    std::cout << "A* Route\n";

    printRoute(graph, heuristicRoute);

    std::cout << "Distance: "
              << heuristicRoute.totalWeight
              << " km\n\n";

    auto mst = Kruskal::findMST(graph);

    std::cout << "MST Routes:\n";

    for (const auto& edge : mst.edges) {
        std::cout
            << graph.getNodeName(edge.source)
            << " - "
            << graph.getNodeName(edge.destination)
            << " ("
            << edge.distance
            << " km)\n";
    }

    std::cout << "\nMST Cost: "
              << mst.totalCost
              << " km\n\n";

    int maxFlow =
        MaxFlow::edmondsKarp(graph, 1, 5);

    std::cout << "Maximum Flow (Delhi -> Pune): "
              << maxFlow
              << "\n";

    return 0;
}