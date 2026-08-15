#ifndef MST_H
#define MST_H
#include "graph.h"
#include <vector>

struct MSTEdge
{
    int u;
    int v;
    double weight;
};

struct MSTResult
{
    std::vector<MSTEdge> edges;
    double total_weight = 0.0;
};

MSTResult kruskalMST(const CSRGraph& graph);
MSTResult primMST(const CSRGraph& graph);
#endif