#pragma once

#include "core/Graph.hpp"

class MaxFlow {
public:
    static int edmondsKarp(
        const Graph& graph,
        int source,
        int sink
    );
};