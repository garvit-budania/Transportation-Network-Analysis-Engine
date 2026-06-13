#include "algorithms/NetworkResilience.hpp"

#include <algorithm>
#include <unordered_map>

namespace {

void findArticulationPoints(
    const Graph& graph,
    int current,
    int parent,
    int& timer,
    std::unordered_map<int, bool>& visited,
    std::unordered_map<int, int>& discovery,
    std::unordered_map<int, int>& low,
    std::vector<int>& articulationPoints
) {
    visited[current] = true;

    discovery[current] = low[current] = timer++;

    int children = 0;

    for (const auto& edge : graph.getNeighbors(current)) {
        int next = edge.destination;

        if (next == parent)
            continue;

        if (!visited[next]) {
            children++;

            findArticulationPoints(
                graph,
                next,
                current,
                timer,
                visited,
                discovery,
                low,
                articulationPoints
            );

            low[current] =
                std::min(low[current], low[next]);

            if (parent != -1 &&
                low[next] >= discovery[current]) {

                articulationPoints.push_back(current);
            }
        }
        else {
            low[current] =
                std::min(low[current], discovery[next]);
        }
    }

    if (parent == -1 && children > 1)
        articulationPoints.push_back(current);
}

void findBridges(
    const Graph& graph,
    int current,
    int parent,
    int& timer,
    std::unordered_map<int, bool>& visited,
    std::unordered_map<int, int>& discovery,
    std::unordered_map<int, int>& low,
    std::vector<std::pair<int, int>>& bridges
) {
    visited[current] = true;

    discovery[current] = low[current] = timer++;

    for (const auto& edge : graph.getNeighbors(current)) {
        int next = edge.destination;

        if (next == parent)
            continue;

        if (!visited[next]) {
            findBridges(
                graph,
                next,
                current,
                timer,
                visited,
                discovery,
                low,
                bridges
            );

            low[current] =
                std::min(low[current], low[next]);

            if (low[next] > discovery[current]) {
                bridges.push_back({
                    current,
                    next
                });
            }
        }
        else {
            low[current] =
                std::min(low[current], discovery[next]);
        }
    }
}

}

std::vector<int>
NetworkResilience::articulationPoints(
    const Graph& graph
) {
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, int> discovery;
    std::unordered_map<int, int> low;

    std::vector<int> points;

    int timer = 0;

    for (const auto& node : graph.getAllNodes()) {
        if (!visited[node.first]) {
            findArticulationPoints(
                graph,
                node.first,
                -1,
                timer,
                visited,
                discovery,
                low,
                points
            );
        }
    }

    std::sort(points.begin(), points.end());

    points.erase(
        std::unique(points.begin(), points.end()),
        points.end()
    );

    return points;
}

std::vector<std::pair<int, int>>
NetworkResilience::bridges(
    const Graph& graph
) {
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, int> discovery;
    std::unordered_map<int, int> low;

    std::vector<std::pair<int, int>> bridges;

    int timer = 0;

    for (const auto& node : graph.getAllNodes()) {
        if (!visited[node.first]) {
            findBridges(
                graph,
                node.first,
                -1,
                timer,
                visited,
                discovery,
                low,
                bridges
            );
        }
    }

    return bridges;
}