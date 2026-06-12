#pragma once

#include <unordered_map>
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

class Graph {
private:
    bool directed;
    std::unordered_map<int, Node> nodes;
    std::unordered_map<int, std::vector<Edge>> adjacencyList;
    size_t totalEdges;

public:
    Graph(bool directed = true);

    bool addNode(const Node& node);
    bool addEdge(const Edge& edge);

    bool hasNode(int nodeId) const;
    const Node& getNode(int nodeId) const;
    const std::vector<Edge>& getNeighbors(int nodeId) const;
    const std::unordered_map<int, Node>& getAllNodes() const;

    size_t nodeCount() const;
    size_t edgeCount() const;
    bool isDirected() const;
};