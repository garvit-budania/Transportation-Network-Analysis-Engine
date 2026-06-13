#pragma once

#include <string>

#include "core/Graph.hpp"

class DotExporter {
public:
    static bool exportGraph(
        const Graph& graph,
        const std::string& filename
    );
};