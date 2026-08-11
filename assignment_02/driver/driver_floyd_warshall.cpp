#include "../include/graph.h"
#include "../include/floyd_warshall.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <limits>

int main(int argc, char* argv[])
{
    if(argc != 2) 
    { 
        std::cerr<<"Usage: "<<argv[0]<<" <input_file>"<<std::endl;
        return 1; 
    }
    //text file as input
    std::string filename = argv[1];

    //graph to csr
    CSRGraph graph = loadCSRGraph(filename);

    if(graph.num_vertices <= 0)
    {
        std::cerr<<"Error: Graph could not be loaded."<<std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<double>> distance = floydWarshall(graph);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed =end - start;

    bool negative_cycle = false;
    for(int i = 0; i < graph.num_vertices; i++)
    {
        if(distance[i][i] < 0)
        {
            negative_cycle = true;
            break;
        }
    }

    std::cout<<"Algorithm: Floyd-Warshall"<<std::endl;
    std::cout<<"Distance matrix:"<<std::endl;
    //INF is matrix to store the resultant matrix
    const double INF = std::numeric_limits<double>::infinity();

    for(int i=0;i< graph.num_vertices; i++)
    {
        for(int j=0; j < graph.num_vertices; j++)
        {
            if(distance[i][j] == INF)
            {
                std::cout<< "INF";
            }
            else
            {
                std::cout<<distance[i][j];
            }

            if(j < graph.num_vertices - 1)
            {
                std::cout<<" ";
            }
        }

        std::cout<<std::endl;
    }
    //checking for negative cycle
    if(negative_cycle)
    {
        std::cout<<"Negative cycle: detected"<< std::endl;
    }
    else
    {
        std::cout<<"Negative cycle: none"<<std::endl;
    }
    std::cout<<"Execution time: "<< elapsed.count()<< " ms"<< std::endl;
    return 0;
}

