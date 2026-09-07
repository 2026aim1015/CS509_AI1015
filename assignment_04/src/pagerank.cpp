#include "../include/pagerank.h"

#include <cmath>
#include <vector>

PageRankResult pageRank(
    const std::vector<int>& row_ptr,
    const std::vector<int>& col_ind,
    int num_vertices,
    double damping,
    double tolerance,
    int max_iterations)
{
    PageRankResult result;
    result.ranks.resize(num_vertices);
    double initial_rank = 1.0 / num_vertices;
    for (int i = 0; i < num_vertices; i++)
    {
        result.ranks[i] = initial_rank;
    }

    result.iterations = 0;
    result.converged = false;

    std::vector<double> new_ranks(num_vertices);

    for (int iteration = 1; iteration <= max_iterations; iteration++)
    {
        
        double base_rank =
            (1.0 - damping) / num_vertices;

        for (int v = 0; v < num_vertices; v++)
        {
            new_ranks[v] = base_rank;
        }

        double dangling_rank = 0.0;

        for (int u = 0; u < num_vertices; u++)
        {
            int start = row_ptr[u];
            int end = row_ptr[u + 1];

            int out_degree = end - start;

            if (out_degree == 0)
            {
                dangling_rank += result.ranks[u];
            }
        }

        double dangling_contribution = damping * dangling_rank / num_vertices;

        for (int v = 0; v < num_vertices; v++)
        {
            new_ranks[v] += dangling_contribution;
        }

        for (int u = 0; u < num_vertices; u++)
        {
            int start = row_ptr[u];
            int end = row_ptr[u + 1];

            int out_degree = end - start;

            if (out_degree == 0)
            {
                continue;
            }

            double contribution = damping * result.ranks[u] / out_degree;

            for (int edge = start; edge < end; edge++)
            {
                int v = col_ind[edge];

                new_ranks[v] += contribution;
            }
        }

        double total_change = 0.0;

        for (int v = 0; v < num_vertices; v++)
        {
            total_change +=
                std::fabs(new_ranks[v] - result.ranks[v]);
        }

        for (int v = 0; v < num_vertices; v++)
        {
            result.ranks[v] = new_ranks[v];
        }

        result.iterations = iteration;

        if (total_change <= tolerance)
        {
            result.converged = true;
            break;
        }
    }

    return result;
}