#include "../include/mst.h"
#include <queue>
#include <vector>
using namespace std;
//edge in priority queue
struct PQEdge
{
    int u;
    int v;
    double weight;
};
//for getting minimun priority edge
struct CompareEdge
{
    bool operator()(const PQEdge& a, const PQEdge& b)
    {
        return a.weight > b.weight;
    }
};
//prim algorithm
MSTResult primMST(const CSRGraph& graph)
{
    MSTResult result;
    int V = graph.num_vertices;
    //check for no vertice graph
    if(V == 0)
    {
        return result;
    }
    //visited vector to check whether node is visited or not
    vector<bool> visited(V, false);
    //min priority queue
    priority_queue<
        PQEdge,
        vector<PQEdge>,
        CompareEdge
    > pq;
    //start wih vertex 0
    int startV = 0;
    visited[startV] = true;
    //add all edges of priority queue
    int start = graph.row_ptr[startV];
    int end = graph.row_ptr[startV + 1];
    for(int i = start; i < end; i++)
    {
        PQEdge edge;
        edge.u = startV;
        edge.v = graph.col_ind[i];
        edge.weight = graph.weights[i];
        pq.push(edge);
    }
    //select min weight edge
    while(!pq.empty() && result.edges.size()<static_cast<size_t>(V - 1))
    {
        PQEdge current = pq.top();
        pq.pop();
        int u = current.u;
        int v = current.v;

        //check if vertices is visited or not
        if(visited[v])
        {
            continue;
        }
        //add vertices and select min weight edge
        visited[v] = true;
        MSTEdge mstEdge;
        mstEdge.u = u;
        mstEdge.v = v;
        mstEdge.weight = current.weight;
        result.edges.push_back(mstEdge);
        result.total_weight += current.weight;

        start = graph.row_ptr[v];
        end = graph.row_ptr[v+1];

        for(int i=start;i<end; i++)
        {
            int next = graph.col_ind[i];
            if(!visited[next])
            {
                PQEdge edge;
                edge.u = v;
                edge.v = next;
                edge.weight = graph.weights[i];
                pq.push(edge);
            }
        }
    }
    return result;
}