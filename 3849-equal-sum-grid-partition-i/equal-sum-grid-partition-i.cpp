class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long total=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }
        // horizontal
        long long sumh=0;
        for(int k=0;k<n-1;k++){
            for(int j=0;j<m;j++){
                sumh+=grid[k][j];
            }
            if(sumh==total-sumh) return true;
        }
        // vertical
        long long sumv=0;
         for(int k=0;k<m-1;k++){
            for(int i=0;i<n;i++){
                sumv+=grid[i][k];
            }
            if(sumv==total-sumv) return true;
        }
        return false;
    }
};