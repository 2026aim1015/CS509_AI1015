#include "../include/graph.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

CSRGraph loadCSRGraph(const std::string& filename)
{
    CSRGraph graph;
    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cerr << "Error: Cannot open file: " << filename << std::endl;
        return graph;
    }

    std::string line;

    int V = 0;
    int E = 0;

    while (std::getline(infile, line))
    {
        if (line.empty() || line[0] == '#')
            continue;
        std::stringstream ss(line);

        if (ss >> V >> E)
            break;
    }
    if (V <= 0)
    {
        std::cerr << "Error: Invalid number of vertices." << std::endl;
        return graph;
    }

    graph.num_vertices = V;
    std::vector<std::vector<int>> adjacency(V);

    while (std::getline(infile, line))
    {
        if (line.empty() || line[0] == '#')
            continue;
        std::stringstream ss(line);
        std::string first_token;
        if (!(ss >> first_token))
            continue;
        if (first_token == "SOURCE" ||
            first_token == "source" ||
            first_token == "Source")
        {
            ss >> graph.source;
            continue;
        }

        if (first_token == "DAMPING" ||
            first_token == "damping" ||
            first_token == "Damping" ||
            first_token == "TOLERANCE" ||
            first_token == "tolerance" ||
            first_token == "Tolerance" ||
            first_token == "MAX_ITERATIONS" ||
            first_token == "max_iterations" ||
            first_token == "Max_iterations")
        {
            continue;
        }
    
        int u;

        try
        {
            u = std::stoi(first_token);
        }
        catch (...)
        {
            continue;
        }        
        if (u < 0 || u >= V)
        {
            std::cerr << "Error: Vertex " << u << " is out of range." << std::endl;
            continue;
        }

        int degree;

        if (!(ss >> degree))
        {
            std::cerr << "Error: Missing degree for vertex " << u << std::endl;
            continue;
        }

        if (degree < 0)
        {
            std::cerr << "Error: Invalid degree for vertex " << u << std::endl;
            continue;
        }

        for (int i = 0; i < degree; i++)
        {
            int v;
            if (!(ss >> v))
            {
                std::cerr << "Error: Missing neighbor for vertex "<< u << std::endl;
                break;
            }
            if (v < 0 || v >= V)
            {
                std::cerr << "Error: Invalid neighbor " << v << " for vertex " << u << std::endl;
                continue;
            }
            if (u == v)
            {
                std::cerr << "Error: Self-loop detected at vertex " << u << std::endl;
                continue;
            }
            adjacency[u].push_back(v);
        }
    }
    infile.close();


    graph.row_ptr.resize(V + 1, 0);

    for (int u = 0; u < V; u++)
    {
        graph.row_ptr[u + 1] = graph.row_ptr[u] + static_cast<int>(adjacency[u].size());
    }

    int total_edges = graph.row_ptr[V];
    graph.col_ind.reserve(total_edges);
    graph.weights.clear();

    for (int u = 0; u < V; u++)
    {
        for (size_t j = 0;j < adjacency[u].size();j++)
        {
            graph.col_ind.push_back(adjacency[u][j]);
        }
    }
    graph.num_edges = total_edges;

    return graph;
}