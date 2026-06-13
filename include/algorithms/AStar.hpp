#pragma once

#include "algorithms/Dijkstra.hpp"
#include "core/Graph.hpp"

class AStar {
public:
    static PathResult shortestPath(
        const Graph& graph,
        int source,
        int destination
    );

private:
    static double heuristic(
        const Node& current,
        const Node& destination
    );
};