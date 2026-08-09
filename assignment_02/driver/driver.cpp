#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

#include "../src/graph.h"

using namespace std;

int main()
{
    // Open input file
    ifstream inputFile("tests/test_01.txt");

    if (!inputFile)
    {
        cout << "Error: Could not open input file." << endl;
        return 1;
    }

    int V, E;

    // Read number of vertices and edges
    inputFile >> V >> E;

    if (V <= 0 || E < 0)
    {
        cout << "Error: Invalid number of vertices or edges." << endl;
        return 1;
    }

    // Create adjacency list
    vector<vector<pair<int, double>>> adjacency(V);

    // Read adjacency list
    for (int u = 0; u < V; u++)
    {
        int vertex;
        int degree;

        inputFile >> vertex >> degree;

        // Check vertex number
        if (vertex < 0 || vertex >= V)
        {
            cout << "Error: Invalid vertex number." << endl;
            return 1;
        }

        // Check degree
        if (degree < 0)
        {
            cout << "Error: Invalid degree." << endl;
            return 1;
        }

        // Read neighbours and weights
        for (int j = 0; j < degree; j++)
        {
            int neighbour;
            double weight;

            inputFile >> neighbour >> weight;

            // Check neighbour
            if (neighbour < 0 || neighbour >= V)
            {
                cout << "Error: Invalid neighbour." << endl;
                return 1;
            }

            adjacency[vertex].push_back(
                {neighbour, weight}
            );
        }
    }

    // Read SOURCE
    string sourceWord;
    int source;

    inputFile >> sourceWord >> source;

    if (sourceWord != "SOURCE")
    {
        cout << "Error: SOURCE line missing." << endl;
        return 1;
    }

    if (source < 0 || source >= V)
    {
        cout << "Error: Invalid source vertex." << endl;
        return 1;
    }

    inputFile.close();

    // Convert adjacency list to CSR
    CSRGraph graph = convertToCSR(adjacency);

    // Print information
    cout << "Number of vertices: "
         << graph.num_vertices << endl;

    cout << "Number of edges: "
         << graph.num_edges << endl;

    cout << "Source: "
         << source << endl;

    // Print CSR
    cout << "\nrow_ptr: ";

    for (int i = 0; i < graph.row_ptr.size(); i++)
    {
        cout << graph.row_ptr[i] << " ";
    }

    cout << "\ncol_ind: ";

    for (int i = 0; i < graph.col_ind.size(); i++)
    {
        cout << graph.col_ind[i] << " ";
    }

    cout << "\nweights: ";

    for (int i = 0; i < graph.weights.size(); i++)
    {
        cout << graph.weights[i] << " ";
    }

    cout << endl;

    return 0;
}