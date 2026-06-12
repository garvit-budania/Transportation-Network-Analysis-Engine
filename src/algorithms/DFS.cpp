#include "algorithms/DFS.hpp"

void DFS::dfs(
    const Graph& graph,
    int currentNode,
    std::unordered_set<int>& visited,
    std::vector<int>& traversal
) {
    visited.insert(currentNode);
    traversal.push_back(currentNode);

    for (const auto& edge : graph.getNeighbors(currentNode)) {
        int nextNode = edge.destination;

        if (visited.find(nextNode) == visited.end())
            dfs(graph, nextNode, visited, traversal);
    }
}

std::vector<int> DFS::run(const Graph& graph, int startNode) {
    std::vector<int> traversal;

    if (!graph.hasNode(startNode))
        return traversal;

    std::unordered_set<int> visited;

    dfs(graph, startNode, visited, traversal);

    return traversal;
}