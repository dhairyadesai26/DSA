class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                vector<int> row, col;

                for(int k = 0; k < n; k++){
                    row.push_back(grid[i][k]);
                    col.push_back(grid[k][j]);
                }

                if(row == col) count++;
            }
        }

        return count;
    }
};