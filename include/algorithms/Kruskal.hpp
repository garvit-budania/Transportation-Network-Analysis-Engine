#pragma once

#include <vector>

#include "core/Edge.hpp"
#include "core/Graph.hpp"

struct MSTResult {
    double totalCost;
    std::vector<Edge> edges;
};

class Kruskal {
public:
    static MSTResult findMST(const Graph& graph);
};