#pragma once

#include <unordered_map>

class UnionFind {
private:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> rank;

public:
    void makeSet(int node);

    int find(int node);

    bool unite(int node1, int node2);

    bool connected(int node1, int node2);
};