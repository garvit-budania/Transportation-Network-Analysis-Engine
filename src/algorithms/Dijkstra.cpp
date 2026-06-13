#include "algorithms/Dijkstra.hpp"

#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>

PathResult Dijkstra::shortestPath(
    const Graph& graph,
    int source,
    int destination,
    RouteMetric metric
) {
    PathResult result;
    result.totalWeight = std::numeric_limits<double>::infinity();

    if (!graph.hasNode(source) || !graph.hasNode(destination))
        return result;

    std::unordered_map<int, double> dist;
    std::unordered_map<int, int> parent;

    for (const auto& node : graph.getAllNodes())
        dist[node.first] = std::numeric_limits<double>::infinity();

    dist[source] = 0;

    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    pq.push({0, source});

    while (!pq.empty()) {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (currentDistance > dist[currentNode])
            continue;

        for (const auto& edge : graph.getNeighbors(currentNode)) {
            double weight = edge.distance;

            if (metric == RouteMetric::Time)
                weight = edge.travelTime;
            else if (metric == RouteMetric::Cost)
                weight = edge.cost;

            double newDistance =
                dist[currentNode] + weight;

            if (newDistance < dist[edge.destination]) {
                dist[edge.destination] = newDistance;
                parent[edge.destination] = currentNode;

                pq.push({
                    newDistance,
                    edge.destination
                });
            }
        }
    }

    if (dist[destination] ==
        std::numeric_limits<double>::infinity())
        return result;

    result.totalWeight = dist[destination];

    int currentNode = destination;

    while (currentNode != source) {
        result.path.push_back(currentNode);
        currentNode = parent[currentNode];
    }

    result.path.push_back(source);

    std::reverse(
        result.path.begin(),
        result.path.end()
    );

    return result;
}