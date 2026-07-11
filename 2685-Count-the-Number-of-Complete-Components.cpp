class Solution {
public:
    class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int count = 0;

      for(auto &e : edges){
      dsu.unionBySize(e[0], e[1]);
      }

unordered_map<int,int> nodes;

for(int i = 0; i < n; i++)
    nodes[dsu.find(i)]++;

unordered_map<int,int> edgeCount;

for(auto &e : edges)
    edgeCount[dsu.find(e[0])]++;

unordered_set<int> visited;

for(int i = 0; i < n; i++) {

    int parent = dsu.find(i);

    if(visited.count(parent))
        continue;

    visited.insert(parent);

    int node = nodes[parent];
    int requiredEdges = node * (node - 1) / 2;

    if(edgeCount[parent] == requiredEdges)
        count++;
}

return count;
    }
};