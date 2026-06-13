#pragma once

#include <vector>

#include "core/Graph.hpp"

class NetworkResilience {
public:
    static std::vector<int> articulationPoints(
        const Graph& graph
    );

    static std::vector<std::pair<int, int>> bridges(
        const Graph& graph
    );
};