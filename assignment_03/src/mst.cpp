#include "../include/mst.h"
#include<algorithm>
#include<vector>
using namespace std;
//disjoint set union class 
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
            int rootA = find(a);
            int rootB = find(b);
            //have same parent means this edge form cycle in mst
            if(rootA == rootB)
            {
                return false;
            }
            //combine using rank
            if(rank[rootA] < rank[rootB])
            {
                parent[rootA] = rootB;
            }
            else if(rank[rootA] > rank[rootB])
            {
                parent[rootB] = rootA;
            }
            else
            {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
            return true;
        }
};