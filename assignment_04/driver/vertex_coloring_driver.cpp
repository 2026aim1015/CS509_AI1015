#include "../include/vertex_coloring.h"
#include "../include/graph.h"

#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{

    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <input_file>"<< endl;
        return 1;
    }
    string filename = argv[1];
    CSRGraph graph = loadCSRGraph(filename);

    auto start = chrono::high_resolution_clock::now();

    ColoringResult result = greedyVertexColoring(
            graph.row_ptr,
            graph.col_ind,
            graph.num_vertices
        );

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;

    cout << "Algorithm: Greedy Vertex Coloring"<< endl;

    cout << "Vertex colors:" << endl;

    for (int i = 0; i < graph.num_vertices; i++)
    {
        cout << i << " "<< result.colors[i]<< endl;
    }

    cout << "Colors used: " << result.colors_used<< endl;

    cout << "Execution time: "<< elapsed.count()<< " ms"<< endl;

    return 0;
}