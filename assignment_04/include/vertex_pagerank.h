#ifndef PAGERANK_H
#define PAGERANK_H

#include <vector>

struct PageRankResult
{
    std::vector<double> ranks;
    int iterations;
    bool converged;
};

PageRankResult pageRank(
    const std::vector<int>& row_ptr,
    const std::vector<int>& col_ind,
    int num_vertices,
    double damping,
    double tolerance,
    int max_iterations
);

#endif