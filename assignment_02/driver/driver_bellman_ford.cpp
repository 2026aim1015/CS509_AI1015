#include "../include/graph.h"
#include "../include/bellman_ford.h"

#include<iostream>
#include<vector>
#include<chrono>
#include<limits>

int main(int argc, char* argv[])
{
    if(argc != 2) 
    { 
        std::cerr<<"Usage: "<<argv[0]<<" <input_file>"<<std::endl;
        return 1; 
    }
    //test file as input
    std::string filename = argv[1];

    // conversion of graph to csr
    CSRGraph graph = loadCSRGraph(filename);
    if (graph.num_vertices<=0)
    {
        std::cerr<<"Error: Graph could not be loaded."<<std::endl;
        return 1;
    }
    int source = graph.source;
    //start timer
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<double> distance =bellmanFord(graph, source);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    bool negative_cycle = false;

    for(int u=0; u<graph.num_vertices; u++)
    {
        if(distance[u] == std::numeric_limits<double>::infinity())
            continue;

        for(int i = graph.row_ptr[u];i < graph.row_ptr[u + 1];i++)
        {
            int v = graph.col_ind[i];
            double weight = graph.weights[i];

            if(distance[u] + weight < distance[v])
            {
                negative_cycle = true;
                break;
            }
        }

        if(negative_cycle)
            break;
    }

    std::cout<<"Algorithm: Bellman-Ford"<<std::endl;
    std::cout<<"Source: "<<source<<std::endl;
    std::cout<<"Vertex Distance"<<std::endl;

    for (int i = 0; i < graph.num_vertices; i++)
    {
        std::cout <<i<<" ";

        if (distance[i] ==
            std::numeric_limits<double>::infinity())
        {
            std::cout<<"INF";
        }
        else
        {
            std::cout<<distance[i];
        }

        std::cout<<std::endl;
    }

    if(negative_cycle)
    {
        std::cout<<"Negative cycle: detected"<<std::endl;
    }
    else
    {
        std::cout<<"Negative cycle: none"<<std::endl;
    }
    std::cout<<"Execution time: "<<elapsed.count()<< " ms" << std::endl;
    return 0;
}

