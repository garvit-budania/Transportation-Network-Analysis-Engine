#include "core/Graph.hpp"

#include <stdexcept>

Graph::Graph(bool isDirected) {
    directed = isDirected;
    totalEdges = 0;
}

bool Graph::addNode(const Node& node) {
    if (hasNode(node.id))
        return false;

    nodes[node.id] = node;
    adjacencyList[node.id] = {};

    return true;
}

bool Graph::addEdge(const Edge& edge) {
    if (!hasNode(edge.source) || !hasNode(edge.destination))
        return false;

    adjacencyList[edge.source].push_back(edge);

    if (!directed) {
        Edge reverseEdge = edge;
        reverseEdge.source = edge.destination;
        reverseEdge.destination = edge.source;

        adjacencyList[edge.destination].push_back(reverseEdge);
    }

    totalEdges++;
    return true;
}

bool Graph::hasNode(int nodeId) const {
    return nodes.find(nodeId) != nodes.end();
}

const Node& Graph::getNode(int nodeId) const {
    auto it = nodes.find(nodeId);

    if (it == nodes.end())
        throw std::runtime_error("Node not found");

    return it->second;
}

std::string Graph::getNodeName(int nodeId) const {
    return getNode(nodeId).name;
}

const std::vector<Edge>& Graph::getNeighbors(int nodeId) const {
    auto it = adjacencyList.find(nodeId);

    if (it == adjacencyList.end())
        throw std::runtime_error("Node not found");

    return it->second;
}

const std::unordered_map<int, Node>& Graph::getAllNodes() const {
    return nodes;
}

size_t Graph::nodeCount() const {
    return nodes.size();
}

size_t Graph::edgeCount() const {
    return totalEdges;
}

bool Graph::isDirected() const {
    return directed;
}