#include "algorithms/BFS.hpp"

#include <queue>
#include <unordered_set>

std::vector<int> BFS::traverse(const Graph& graph, int startNode) {
    std::vector<int> traversal;

    if (!graph.hasNode(startNode))
        return traversal;

    std::queue<int> q;
    std::unordered_set<int> visited;

    q.push(startNode);
    visited.insert(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        traversal.push_back(current);

        for (const auto& edge : graph.getNeighbors(current)) {
            int neighbor = edge.destination;

            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    return traversal;
}