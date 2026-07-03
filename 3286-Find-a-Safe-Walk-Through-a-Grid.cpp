class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> vis(n, vector<int>(m, -1));

        vector<int> da{0, 0, -1, 1};
        vector<int> db{1, -1, 0, 0};

        health -= grid[0][0];

        if(health < 1)
            return false;

        q.push({0, 0});
        vis[0][0] = health;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int i = it.first;
            int j = it.second;

            int currHealth = vis[i][j];

            if(i == n - 1 && j == m - 1)
                return true;

            for(int t = 0; t < 4; t++) {
                int ni = i + da[t];
                int nj = j + db[t];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    int newHealth = currHealth - grid[ni][nj];

                    if(newHealth >= 1 && newHealth > vis[ni][nj]) {
                        vis[ni][nj] = newHealth;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return false;
    }
};