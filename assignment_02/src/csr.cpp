#include "graph.h"
using namespace std;
CSRGraph convertToCSR(const vector<vector<pair<int,double>>>&adjacency)
{
    CSRGraph csr;

    csr.num_vertices = adjacency.size();

    csr.num_edges = 0;

    csr.row_ptr.resize(csr.num_vertices + 1);

    csr.row_ptr[0] = 0;

    for (int u = 0; u < csr.num_vertices; u++)
    {
        csr.num_edges += adjacency[u].size();

        csr.row_ptr[u + 1] =
            csr.row_ptr[u] + adjacency[u].size();
    }

    csr.col_ind.resize(csr.num_edges);
    csr.weights.resize(csr.num_edges);

    int index = 0;

    for (int u = 0; u < csr.num_vertices; u++)
    {
        for (int j = 0; j < adjacency[u].size(); j++)
        {
            csr.col_ind[index] = adjacency[u][j].first;
            csr.weights[index] = adjacency[u][j].second;
            index++;
        }
    }

    return csr;
}