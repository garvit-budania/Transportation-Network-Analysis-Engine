#pragma once

#include <vector>
#include "core/Graph.hpp"

struct PathResult {
    double totalDistance;
    std::vector<int> path;
};

class Dijkstra {
public:
    static PathResult shortestPath(
        const Graph& graph,
        int source,
        int destination
    );
};