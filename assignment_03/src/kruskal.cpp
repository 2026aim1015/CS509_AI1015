#include "../include/mst.h"
#include <algorithm>
#include <vector>

using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    //constructor for disjoint set union
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        //initially every vertices is parent itself
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    //find parent of the vertice
    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    //merge two set 
    bool unite(int a, int b)
    {
        int parentA = find(a);
        int parentB = find(b);
        //have same parent means this edge form cycle in mst
        if(parentA == parentB)
        {
            return false;
        }
        //combine using rank
        if(rank[parentA] < rank[parentB])
        {
            parent[parentA] = parentB;
        }
        else if(rank[parentA] > rank[parentB])
        {
            parent[parentB] = parentA;
        }
        else
        {
            parent[parentB] = parentA;
            rank[parentA]++;
        }

        return true;
    }
};
//kruskal algorithm start here
MSTResult kruskalMST(const CSRGraph& graph)
{
    MSTResult res;

    int V = graph.num_vertices;

    vector<MSTEdge> edges;

    for(int u = 0; u < V; u++)
    {
        int start = graph.row_ptr[u];
        int end = graph.row_ptr[u + 1];

        for(int i = start; i < end; i++)
        {
            int v = graph.col_ind[i];
            double weight = graph.weights[i];
            //to store edge once 
            if(u < v)
            {
                edges.push_back({u,v,weight});
            }
        }
    }

    //sort edges on basis of increasing of weights
    sort(edges.begin(),edges.end(),[](const MSTEdge& a, const MSTEdge& b)
        {
            return a.weight < b.weight;
        });
    //create disjoint set union 
    DSU dsu(V);

    for(const MSTEdge& edge : edges)
    {
        //when end point are in different component then cycle would not be created
        if(dsu.unite(edge.u,edge.v))
        {
            res.edges.push_back(edge);
            res.total_weight += edge.weight;
            //mst contain only v-1 edges
            if(res.edges.size() == static_cast<size_t>(V - 1))
            {
                break;
            }
        }
    }
    return res;
}