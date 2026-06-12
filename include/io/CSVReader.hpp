#pragma once

#include <string>
#include "core/Graph.hpp"

class CSVReader {
public:
    bool loadNodes(const std::string& filename, Graph& graph);
    bool loadEdges(const std::string& filename, Graph& graph);
};