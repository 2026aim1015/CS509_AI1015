#include"../include/graph.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

CSRGraph loadCSRGraph(const std::string& filename)
{
    std::ifstream infile(filename);
    CSRGraph graph;
    //ckecking for input file
    if(!infile.is_open())
    {
        std::cerr<<"Error: Cannot open file: "<<filename<<std::endl;
        return graph;
    }
    std::string line;
    int V = 0;
    int E = 0;

    //read vertices and edges
    while(std::getline(infile, line))
    {
        if(line.empty() || line[0] == '#')
            continue;
        std::stringstream ss(line);
        if(ss>>V>>E)
            break;
    }
    if(V<=0)
    {
        infile.close();
        return graph;
    }
    graph.num_vertices = V;
    //take input from file and store in form of adjacency list
    std::vector<std::vector<std::pair<int, double>>> adjacency(V);

    while(std::getline(infile, line))
    {
        if(line.empty() || line[0] == '#')
            continue;
        std::stringstream ss(line);

        std::string first_token;
        ss >> first_token;

        // for reading source node from file
        if(first_token == "SOURCE" ||
            first_token == "source" ||
            first_token == "Source")
        {
            ss>>graph.source;
            continue;
        }
        int u;
        try
        {
            u=std::stoi(first_token);
        }
        catch (...)
        {
            continue;
        }
        if(u<0||u>=V)
            continue;

        int degree;
        if(!(ss>>degree))
            continue;
        //push the pair of destination and weight
        for(int i=0;i<degree;i++)
        {
            int v;
            double weight;
            if(!(ss>>v>>weight))
                break;

            if(v>=0&&v<V)
            {
                adjacency[u].push_back({v, weight});
            }
        }
    }

    infile.close();
    //complete row_ptr
    graph.row_ptr.resize(V+1, 0);
    for(int u=0;u<V;u++)
    {
        graph.row_ptr[u+1] =graph.row_ptr[u] +static_cast<int>(adjacency[u].size());
    }

    int total_edges = graph.row_ptr[V];
    graph.col_ind.reserve(total_edges);
    graph.weights.reserve(total_edges);
    //complete col_ind,weights of csrgraph
    for(int u=0;u<V;u++)
    {
        for(size_t j=0;j<adjacency[u].size();j++)
        {
            graph.col_ind.push_back(adjacency[u][j].first);
            graph.weights.push_back(adjacency[u][j].second);
        }
    }
    graph.num_edges = total_edges;
    return graph;
}
