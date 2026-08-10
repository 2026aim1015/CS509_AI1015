#include"../include/floyd_warshall.h"
#include<limits>
#include<algorithm>

std::vector<std::vector<double>>floydWarshall(const CSRGraph& graph)
{
    const double INF =std::numeric_limits<double>::infinity();

    int V = graph.num_vertices;
    // matrix for distance
    std::vector<std::vector<double>> dist(V,std::vector<double>(V, INF));
    // self distance as 0 is updated
    for(int i=0;i<V;i++)
    {
        dist[i][i] = 0.0;
    }
    //csr to matrix
    for (int u = 0; u < V; u++)
    {
        for (int i = graph.row_ptr[u];i < graph.row_ptr[u + 1];i++)
        {
            int v = graph.col_ind[i];
            double weight = graph.weights[i];

            dist[u][v] =std::min(dist[u][v], weight);
        }
    }

    // update distance using floyd warshall algorithm
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            if(dist[i][k]==INF)
                continue;

            for(int j=0;j<V;j++)
            {
                if(dist[k][j] == INF)
                    continue;

                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}