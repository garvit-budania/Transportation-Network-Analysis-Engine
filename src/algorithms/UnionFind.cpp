#include "algorithms/UnionFind.hpp"

void UnionFind::makeSet(int node) {
    parent[node] = node;
    rank[node] = 0;
}

int UnionFind::find(int node) {
    if (parent[node] == node)
        return node;

    parent[node] = find(parent[node]);

    return parent[node];
}

bool UnionFind::unite(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    if (root1 == root2)
        return false;

    if (rank[root1] < rank[root2]) {
        parent[root1] = root2;
    }
    else if (rank[root1] > rank[root2]) {
        parent[root2] = root1;
    }
    else {
        parent[root2] = root1;
        rank[root1]++;
    }

    return true;
}

bool UnionFind::connected(int node1, int node2) {
    return find(node1) == find(node2);
}