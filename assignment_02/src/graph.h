#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<utility>
using namespace std;

struct CSRGraph
{
    int num_vertices;
    int num_edges;
    vector<int>row_ptr;
    vector<int>col_ind;
    vector<double>weights;
};

CSRGraph convertToCSR(const vector<vector<pair<int,double>>>&adjacency);
#endif