#pragma once

#include <vector>
#include "core/Graph.hpp"

class BFS {
public:
    static std::vector<int> traverse(const Graph& graph, int startNode);
};