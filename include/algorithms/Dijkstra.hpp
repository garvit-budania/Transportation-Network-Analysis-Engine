#pragma once

#include <vector>

#include "core/Graph.hpp"

enum class RouteMetric {
    Distance,
    Time,
    Cost
};

struct PathResult {
    double totalWeight;
    std::vector<int> path;
};

class Dijkstra {
public:
    static PathResult shortestPath(
        const Graph& graph,
        int source,
        int destination,
        RouteMetric metric = RouteMetric::Distance
    );
};