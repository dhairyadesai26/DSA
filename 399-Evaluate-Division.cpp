class Solution {
public:

    double dfs(string a, string b,
               unordered_map<string, vector<pair<string, double>>>& adj,
               unordered_map<string, bool>& present,
               unordered_map<string, bool>& visited) {

        // Unknown variable
        if (!present[a] || !present[b]) {
            return -1.0;
        }

        // a / a = 1
        if (a == b) {
            return 1.0;
        }

        visited[a] = true;

        for (auto it : adj[a]) {

            string next = it.first;
            double value = it.second;

            if (visited[next]) {
                continue;
            }

            double result = dfs(next, b, adj, present, visited);

            if (result != -1.0) {
                return value * result;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                 vector<double>& values,
                                 vector<vector<string>>& queries) {

        int n = equations.size();
        int m = queries.size();

        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_map<string, bool> present;

        vector<double> ans;

        // Build graph
        for (int i = 0; i < n; i++) {

            string u = equations[i][0];
            string v = equations[i][1];

            double value = values[i];

            // u / v = value
            adj[u].push_back({v, value});

            // v / u = 1 / value
            adj[v].push_back({u, 1.0 / value});

            present[u] = true;
            present[v] = true;
        }

        // Process queries
        for (int i = 0; i < m; i++) {

            string a = queries[i][0];
            string b = queries[i][1];

            unordered_map<string, bool> visited;

            ans.push_back(
                dfs(a, b, adj, present, visited)
            );
        }

        return ans;
    }
};