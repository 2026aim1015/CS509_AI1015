#include "../include/bellman_ford.h"
#include <limits>
#include <algorithm>

std::vector<double> bellmanFord(const CSRGraph& graph,int source)
{
    const double INF = std::numeric_limits<double>::infinity();
    int V = graph.num_vertices;
    std::vector<double> distance(V, INF);
    distance[source] = 0.0;
    //relax for v-1 iteration
    for(int iteration=0;iteration<V-1;iteration++)
    {
        bool changed = false;
        for(int u=0;u<V;u++)
        {
            if(distance[u]==INF)
                continue;

            for (int i=graph.row_ptr[u];i<graph.row_ptr[u+1];i++)
            {
                int v = graph.col_ind[i];
                double weight = graph.weights[i];
                if (distance[u] + weight<distance[v])
                {
                    distance[v] = distance[u] + weight;
                    changed = true;
                }
            }
        }

        //no change means get smallest distance
        if (!changed)
            break;
    }
    return distance;
}