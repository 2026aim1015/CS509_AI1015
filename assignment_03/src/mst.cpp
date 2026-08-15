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
        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int find(int x)
        {
            if(parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int a, int b)
        {
            int rootA = find(a);
            int rootB = find(b);
            if(rootA == rootB)
            {
                return false;
            }

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