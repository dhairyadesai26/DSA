class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>& adj,vector<bool>& visited,int& cnt){
        visited[node]=true;
        for(auto& [neighbour,cost]:adj[node]){
            if(!visited[neighbour]){
                cnt+=cost;
                dfs(neighbour,adj,visited,cnt);

            }
        }


    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int cnt=0;
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> visited(n,false);
        for(auto& edges:connections){
            int u=edges[0];
            int v=edges[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});

        }
        dfs(0,adj,visited,cnt);
        return cnt;



    }
};