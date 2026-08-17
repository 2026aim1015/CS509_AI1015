#include "../include/graph.h"
#include "../include/mst.h"

#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;


// Print MST result
void printResult(const string& algorithm, const MSTResult& result)
{
    cout << "Algorithm: " << algorithm << endl;

    cout << endl;
    cout << "MST edges:" << endl;

    for(size_t i = 0; i < result.edges.size(); i++)
    {
        cout << result.edges[i].u << " "
             << result.edges[i].v << " "
             << result.edges[i].weight << endl;
    }

    cout << endl;

    cout << "Total MST weight: "
         << result.total_weight << endl;
}


// Measure and run Kruskal
MSTResult runKruskal(const CSRGraph& graph, double& time_ms)
{
    auto start = high_resolution_clock::now();

    MSTResult result = kruskalMST(graph);

    auto end = high_resolution_clock::now();

    time_ms =
        duration<double, milli>(end - start).count();

    return result;
}


// Measure and run Prim
MSTResult runPrim(const CSRGraph& graph, double& time_ms)
{
    auto start = high_resolution_clock::now();

    MSTResult result = primMST(graph);

    auto end = high_resolution_clock::now();

    time_ms =
        duration<double, milli>(end - start).count();

    return result;
}


int main(int argc, char* argv[])
{
    // -----------------------------------------------
    // Check command-line argument
    // -----------------------------------------------

    if(argc < 2)
    {
        cout << "Usage: " << argv[0]
             << " <input_file>" << endl;

        return 1;
    }

    string filename = argv[1];


    // -----------------------------------------------
    // CSR conversion
    //
    // This is NOT timed.
    // -----------------------------------------------

    CSRGraph graph = loadCSRGraph(filename);


    // Check whether graph was loaded
    if(graph.num_vertices == 0)
    {
        cerr << "Error: Graph could not be loaded."
             << endl;

        return 1;
    }


    // -----------------------------------------------
    // Run Kruskal
    // -----------------------------------------------

    double kruskal_time;

    MSTResult kruskal_result =
        runKruskal(graph, kruskal_time);


    // -----------------------------------------------
    // Run Prim
    // -----------------------------------------------

    double prim_time;

    MSTResult prim_result =
        runPrim(graph, prim_time);


    // -----------------------------------------------
    // Print Kruskal result
    // -----------------------------------------------

    printResult(
        "Kruskal's MST",
        kruskal_result
    );

    cout << "Execution time: "
         << kruskal_time
         << " ms"
         << endl;


    cout << endl;


    // -----------------------------------------------
    // Print Prim result
    // -----------------------------------------------

    printResult(
        "Prim's MST",
        prim_result
    );

    cout << "Execution time: "
         << prim_time
         << " ms"
         << endl;


    // -----------------------------------------------
    // Check correctness
    // -----------------------------------------------

    cout << endl;

    
    return 0;
}