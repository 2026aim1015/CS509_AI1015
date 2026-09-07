#include "../include/graph.h"
#include "../include/vertex_pagerank.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    //Check command line argument
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0]<< " <input_file>" << endl;
        return 1;
    }

    string filename = argv[1];

    ifstream infile(filename);

    if (!infile.is_open())
    {
        cerr << "Error: Cannot open input file: "<< filename << endl;
        return 1;
    }

    int V, E;

    //Read V and E
    if (!(infile >> V >> E))
    {
        cerr << "Error: Invalid graph header." << endl;
        return 1;
    }

    if (V <= 0)
    {
        cerr << "Error: Number of vertices must be positive."<< endl;
        return 1;
    }

    if (E < 0)
    {
        cerr << "Error: Number of edges cannot be negative."<< endl;
        return 1;
    }

    //CSR representation
    vector<int> row_ptr(V + 1, 0);
    vector<int> col_ind;

    col_ind.reserve(E);

    // Read adjacency list
    for (int u = 0; u < V; u++)
    {
        int vertex;
        int out_degree;

        if (!(infile >> vertex >> out_degree))
        {
            cerr << "Error: Invalid adjacency list for vertex "<< u << endl;
            return 1;
        }

        if (vertex != u)
        {
            cerr << "Error: Expected vertex "<< u << " but found "<< vertex << endl;
            return 1;
        }

        if (out_degree < 0)
        {
            cerr << "Error: Invalid outdegree for vertex "<< u << endl;
            return 1;
        }

        row_ptr[u + 1] = row_ptr[u] + out_degree;
        for (int j = 0; j < out_degree; j++)
        {
            int neighbor;

            if (!(infile >> neighbor))
            {
                cerr << "Error: Missing neighbor for vertex "<< u << endl;
                return 1;
            }

            if (neighbor < 0 || neighbor >= V)
            {
                cerr << "Error: Invalid neighbor vertex "<< neighbor << endl;
                return 1;
            }
            col_ind.push_back(neighbor);
        }
    }

    // Check actual edge count
    if ((int)col_ind.size() != E)
    {
        cerr << "Error: Edge count does not match input."<< endl;
        return 1;
    }
    // Read PageRank parameters
    string keyword;

    double damping;
    double tolerance;
    int max_iterations;

    if (!(infile >> keyword >> damping))
    {
        cerr << "Error: Missing DAMPING value." << endl;
        return 1;
    }

    if (keyword != "DAMPING")
    {
        cerr << "Error: Expected DAMPING." << endl;
        return 1;
    }

    if (!(infile >> keyword >> tolerance))
    {
        cerr << "Error: Missing TOLERANCE value." << endl;
        return 1;
    }

    if (keyword != "TOLERANCE")
    {
        cerr << "Error: Expected TOLERANCE." << endl;
        return 1;
    }

    if (!(infile >> keyword >> max_iterations))
    {
        cerr << "Error: Missing MAX_ITERATIONS value."<< endl;
        return 1;
    }

    if (keyword != "MAX_ITERATIONS")
    {
        cerr << "Error: Expected MAX_ITERATIONS." << endl;
        return 1;
    }
    //Validate PageRank parameters
    
    if (damping <= 0.0 || damping >= 1.0)
    {
        cerr << "Error: Damping must be between 0 and 1."<< endl;
        return 1;
    }

    if (tolerance <= 0.0)
    {
        cerr << "Error: Tolerance must be positive."<< endl;
        return 1;
    }

    if (max_iterations <= 0)
    {
        cerr << "Error: MAX_ITERATIONS must be positive."<< endl;
        return 1;
    }
    auto start_time = chrono::high_resolution_clock::now();

    PageRankResult result = pageRank(row_ptr,col_ind,V,damping,tolerance,max_iterations);

    auto end_time = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed =
        end_time - start_time;

    //Calculate sum of ranks
    double rank_sum = 0.0;

    for (int i = 0; i < V; i++)
    {
        rank_sum += result.ranks[i];
    }

    cout << fixed << setprecision(6);
    cout << "Algorithm: PageRank" << endl;
    cout << "Damping: "<< damping << endl;
    cout << "Vertex ranks:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " "<< result.ranks[i] << endl;
    }

    cout << "Sum of ranks: "<< rank_sum << endl;
    cout << "Iterations: "<< result.iterations << endl;
    cout << "Converged: "<< (result.converged ? "true" : "false")<< endl;
    cout << "Execution time: "<< elapsed.count() << " ms" << endl;

    return 0;
}