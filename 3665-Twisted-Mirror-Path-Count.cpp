class Solution {
public:
    int dp[501][501][3];
    int m,n;
    const int mod=1e9+7;
    int solve(int i,int j,int prev,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j][prev+1]!=-1)  return dp[i][j][prev+1];
        int down=0;
        int right=0;
        if(grid[i][j]==1){
            if(prev==0){              
                 down=solve(i+1,j,1,grid);
            }
            else{
                right=solve(i,j+1,0,grid);
            }
        }
        else{
            down=solve(i+1,j,1,grid);
            right=solve(i,j+1,0,grid);
        }
        return dp[i][j][prev+1]=(down +right) % mod;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1,grid);

        
    }
};