#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include "graph.h"
#include <vector>

std::vector<std::vector<double>>floydWarshall(const CSRGraph& graph);

#endif