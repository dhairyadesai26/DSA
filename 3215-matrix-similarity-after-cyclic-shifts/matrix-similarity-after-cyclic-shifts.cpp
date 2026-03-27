class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n; 

        vector<vector<int>> grid = mat;

        while (k--) {
            vector<vector<int>> temp = grid;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (i % 2 == 0) {
                        grid[i][j] = temp[i][(j + 1) % n];   
                    } else {
                        grid[i][j] = temp[i][(j - 1 + n) % n];
                    }

                }
            }
        }

        return grid == mat;
    }
};