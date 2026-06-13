#include "algorithms/MaxFlow.hpp"

#include <climits>
#include <queue>
#include <unordered_map>

int MaxFlow::edmondsKarp(
    const Graph& graph,
    int source,
    int sink
) {
    std::unordered_map<int,
        std::unordered_map<int, int>> residual;

    for (const auto& node : graph.getAllNodes()) {
        for (const auto& edge : graph.getNeighbors(node.first)) {
            residual[edge.source][edge.destination] =
                edge.capacity;
        }
    }

    int maxFlow = 0;

    while (true) {
        std::queue<int> q;
        std::unordered_map<int, int> parent;

        q.push(source);
        parent[source] = -1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (const auto& neighbor :
                 residual[current]) {

                if (neighbor.second > 0 &&
                    parent.find(neighbor.first)
                        == parent.end()) {

                    parent[neighbor.first] = current;
                    q.push(neighbor.first);
                }
            }
        }

        if (parent.find(sink) == parent.end())
            break;

        int pathFlow = INT_MAX;

        int current = sink;

        while (current != source) {
            int previous = parent[current];

            pathFlow = std::min(
                pathFlow,
                residual[previous][current]
            );

            current = previous;
        }

        current = sink;

        while (current != source) {
            int previous = parent[current];

            residual[previous][current] -= pathFlow;
            residual[current][previous] += pathFlow;

            current = previous;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}