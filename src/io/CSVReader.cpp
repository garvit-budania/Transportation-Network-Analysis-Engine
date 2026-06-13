#include "io/CSVReader.hpp"

#include <fstream>
#include <sstream>

bool CSVReader::loadNodes(const std::string& filename, Graph& graph) {
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string id;
        std::string name;
        std::string x;
        std::string y;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, x, ',');
        std::getline(ss, y, ',');

        graph.addNode({
            std::stoi(id),
            name,
            std::stod(x),
            std::stod(y)
        });
    }

    return true;
}

bool CSVReader::loadEdges(const std::string& filename, Graph& graph) {
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string source;
        std::string destination;
        std::string distance;
        std::string travelTime;
        std::string cost;
        std::string capacity;

        std::getline(ss, source, ',');
        std::getline(ss, destination, ',');
        std::getline(ss, distance, ',');
        std::getline(ss, travelTime, ',');
        std::getline(ss, cost, ',');
        std::getline(ss, capacity, ',');

        graph.addEdge({
            std::stoi(source),
            std::stoi(destination),
            std::stod(distance),
            std::stod(travelTime),
            std::stod(cost),
            std::stoi(capacity)
        });
    }

    return true;
}