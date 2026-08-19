class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<vector<int>> q;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        q.push({entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;

        while (!q.empty()) {
        vector<int> curr = q.front();
        q.pop();

        int x = curr[0];
        int y = curr[1];
        int dist = curr[2];

        for (int i = 0; i < 4; i++) {
        int nr = x + dx[i];
        int nc = y + dy[i];

        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

            if (maze[nr][nc] == '.' && !visited[nr][nc]) {

                if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                    return dist + 1;
                }

                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
        }
            }

            return -1;
          }
         };