#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "graph.h"
#include <vector>

std::vector<double> bellmanFord(const CSRGraph& graph,int source);

#endif