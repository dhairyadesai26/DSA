1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4    int maxDepth = 0;
5
6    void dfs(int node, int parent, int depth,
7             vector<vector<int>>& adj) {
8
9        maxDepth = max(maxDepth, depth);
10
11        for(int nei : adj[node]) {
12            if(nei != parent) {
13                dfs(nei, node, depth + 1, adj);
14            }
15        }
16    }
17
18    long long modPow(long long base, long long exp) {
19        long long res = 1;
20
21        while(exp > 0) {
22            if(exp & 1) {
23                res = (res * base) % MOD;
24            }
25
26            base = (base * base) % MOD;
27            exp >>= 1;
28        }
29
30        return res;
31    }
32
33    int assignEdgeWeights(vector<vector<int>>& edges) {
34
35        int n = edges.size() + 1;
36
37        vector<vector<int>> adj(n + 1);
38
39        for(auto &e : edges) {
40            int u = e[0];
41            int v = e[1];
42
43            adj[u].push_back(v);
44            adj[v].push_back(u);
45        }
46
47        dfs(1, 0, 0, adj);
48
49        return (int)modPow(2, maxDepth - 1);
50    }
51};