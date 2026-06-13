#include "visualization/DotExporter.hpp"

#include <fstream>

bool DotExporter::exportGraph(
    const Graph& graph,
    const std::string& filename
) {
    std::ofstream file(filename);

    if (!file.is_open())
        return false;

    file << "graph TransportationNetwork {\n";

    for (const auto& node : graph.getAllNodes()) {
        file << "    "
             << node.first
             << " [label=\""
             << node.second.name
             << "\"];\n";
    }

    for (const auto& node : graph.getAllNodes()) {
        for (const auto& edge :
             graph.getNeighbors(node.first)) {

            if (edge.source < edge.destination) {
                file << "    "
                     << edge.source
                     << " -- "
                     << edge.destination
                     << " [label=\""
                     << edge.distance
                     << "\"];\n";
            }
        }
    }

    file << "}\n";

    return true;
}