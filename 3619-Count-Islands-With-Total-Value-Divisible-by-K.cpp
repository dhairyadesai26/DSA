class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
         int m = grid.size();
        int n = grid[0].size();

        vector<int> a = {0, 1, 0, -1};
        vector<int> b = {1, 0, -1, 0};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] != 0 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    long long sum=grid[i][j];


                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();


                        for (int l = 0; l < 4; l++) {
                            int dx = x + a[l];
                            int dy = y + b[l];

                            if (dx >= 0 && dx < m &&
                                dy >= 0 && dy < n &&
                                grid[dx][dy] != 0 &&
                                !visited[dx][dy]) {
                                sum+=grid[dx][dy];

                                visited[dx][dy] = true;
                                q.push({dx, dy});
                            }
                        }
                    }

                    if (sum % k==0) {
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
};