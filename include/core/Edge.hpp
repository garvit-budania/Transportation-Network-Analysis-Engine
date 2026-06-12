#pragma once

struct Edge
{
    int source;
    int destination;

    double distance;
    double travelTime;
    double cost;

    int capacity;
};