#include "algorithms/Kruskal.hpp"
#include "algorithms/UnionFind.hpp"

#include <algorithm>

MSTResult Kruskal::findMST(const Graph& graph) {
    MSTResult result;
    result.totalCost = 0;

    std::vector<Edge> edges;

    for (const auto& node : graph.getAllNodes()) {
        int source = node.first;

        for (const auto& edge : graph.getNeighbors(source))
            edges.push_back(edge);
    }

    std::sort(
        edges.begin(),
        edges.end(),
        [](const Edge& a, const Edge& b) {
            return a.distance < b.distance;
        }
    );

    UnionFind uf;

    for (const auto& node : graph.getAllNodes())
        uf.makeSet(node.first);

    for (const auto& edge : edges) {
        if (uf.unite(edge.source, edge.destination)) {
            result.edges.push_back(edge);
            result.totalCost += edge.distance;
        }
    }

    return result;
}