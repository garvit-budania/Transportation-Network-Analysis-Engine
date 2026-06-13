#include "algorithms/NetworkAnalyzer.hpp"

#include <queue>
#include <unordered_set>

int NetworkAnalyzer::connectedComponents(const Graph& graph) {
    std::unordered_set<int> visited;
    int components = 0;

    for (const auto& node : graph.getAllNodes()) {
        int startNode = node.first;

        if (visited.count(startNode))
            continue;

        components++;

        std::queue<int> q;
        q.push(startNode);
        visited.insert(startNode);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (const auto& edge : graph.getNeighbors(current)) {
                if (!visited.count(edge.destination)) {
                    visited.insert(edge.destination);
                    q.push(edge.destination);
                }
            }
        }
    }

    return components;
}

double NetworkAnalyzer::averageDegree(const Graph& graph) {
    if (graph.nodeCount() == 0)
        return 0;

    int totalDegree = 0;

    for (const auto& node : graph.getAllNodes())
        totalDegree += graph.getNeighbors(node.first).size();

    return static_cast<double>(totalDegree)
           / graph.nodeCount();
}

double NetworkAnalyzer::networkDensity(const Graph& graph) {
    int n = graph.nodeCount();

    if (n < 2)
        return 0;

    return static_cast<double>(graph.edgeCount())
           / (n * (n - 1));
}

int NetworkAnalyzer::mostConnectedNode(const Graph& graph) {
    int bestNode = -1;
    int maxDegree = -1;

    for (const auto& node : graph.getAllNodes()) {
        int degree =
            graph.getNeighbors(node.first).size();

        if (degree > maxDegree) {
            maxDegree = degree;
            bestNode = node.first;
        }
    }

    return bestNode;
}