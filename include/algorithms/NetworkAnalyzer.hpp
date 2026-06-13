#pragma once

#include "core/Graph.hpp"

class NetworkAnalyzer {
public:
    static int connectedComponents(const Graph& graph);

    static double averageDegree(const Graph& graph);

    static double networkDensity(const Graph& graph);

    static int mostConnectedNode(const Graph& graph);
};