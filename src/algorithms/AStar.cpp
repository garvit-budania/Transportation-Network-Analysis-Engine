#include "algorithms/AStar.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>

double AStar::heuristic(
    const Node& current,
    const Node& destination
) {
    double dx = current.x - destination.x;
    double dy = current.y - destination.y;

    return std::sqrt(dx * dx + dy * dy);
}

PathResult AStar::shortestPath(
    const Graph& graph,
    int source,
    int destination
) {
    PathResult result;
    result.totalDistance = std::numeric_limits<double>::infinity();

    if (!graph.hasNode(source) || !graph.hasNode(destination))
        return result;

    std::unordered_map<int, double> gScore;
    std::unordered_map<int, double> fScore;
    std::unordered_map<int, int> parent;

    for (const auto& node : graph.getAllNodes()) {
        gScore[node.first] = std::numeric_limits<double>::infinity();
        fScore[node.first] = std::numeric_limits<double>::infinity();
    }

    gScore[source] = 0;

    fScore[source] = heuristic(
        graph.getNode(source),
        graph.getNode(destination)
    );

    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    pq.push({fScore[source], source});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        pq.pop();

        if (currentNode == destination)
            break;

        for (const auto& edge : graph.getNeighbors(currentNode)) {
            double tentativeScore =
                gScore[currentNode] + edge.distance;

            if (tentativeScore < gScore[edge.destination]) {
                parent[edge.destination] = currentNode;

                gScore[edge.destination] = tentativeScore;

                fScore[edge.destination] =
                    tentativeScore +
                    heuristic(
                        graph.getNode(edge.destination),
                        graph.getNode(destination)
                    );

                pq.push({
                    fScore[edge.destination],
                    edge.destination
                });
            }
        }
    }

    if (gScore[destination] ==
        std::numeric_limits<double>::infinity())
        return result;

    result.totalDistance = gScore[destination];

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