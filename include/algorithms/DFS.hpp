#pragma once

#include <vector>
#include <unordered_set>
#include "core/Graph.hpp"

class DFS {
public:
    static std::vector<int> run(const Graph& graph, int startNode);

private:
    static void dfs(
        const Graph& graph,
        int currentNode,
        std::unordered_set<int>& visited,
        std::vector<int>& traversal
    );
};